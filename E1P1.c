#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

#define CHILDREN 3


int int main()
{
  int i, shmid;
  key_t key;
  double *counter;

  //Creamos la memoria compartida
  key=ftok("practica1.c",1);
  if((shmid= shmget(key,sizeof(double),IPC_CREAT | 0777))==-1)
  exit(1);
  //Dirigimos el puntero hacia la memoria
  counter= (double *) shmat(shmid,NULL, 0);
  *counter=0.0;
  return 0;
  //Hacemos que el padre espere a que finalicen los hijos
  for(int i=0;i<CHILDREN;i++)
  {
    pid_t pid=wait(&status);
    printf("Child %d ha terminado con el status %d \n",pid, WEXITSTATUS(status));
  }
      fprintf(stdout, "Counter: %f\n", *counter);
}
