To compile this programs you need to run: 

```
  mpicc worker2.c -o worker.exe && mpicc master2.c -o master.exe
  mpirun --use-hhwthread-cpus -app ./appConf
```

The option **--use-hhwthread-cpus** is optional, since the development was in a 2 CPU core.

For the second part you can run 

```
  mpicc trapmpi_trap0.c -o trap.exe
  mpirun --use-hwthread-cpus --oversubscribe -np 4 ./trap.exe
```
