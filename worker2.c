/*
 ============================================================================
 To build use  : mpicc worker.c -o worker
 ============================================================================
 */
#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#define MAXLEN 100

char *greetings[] = { "Hello", "Hi", "Awaiting your command", "Another Message", "Temp 1", "Temp 2", "Temp 3", "More FUnny Messages" };
char buff[MAXLEN];

int main (int argc, char **argv)
{
  MPI_Init (&argc, &argv);
  int rank;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);

  // Set the value
  srand(time(NULL) + ((rank + 2) * 2));
  int grID = rand () % 8;
  pid_t pid = getpid();

  sprintf(buff, "Node %i with PID: %i says %s", rank, pid, greetings[grID]);
  MPI_Send (buff, strlen (buff), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  MPI_Finalize ();
}
