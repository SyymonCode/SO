#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

#define CHILDREN 3


int int main(int argc, char const *argv[])
 {
   int i, shmid, status;
   key_t key;
   double *counter;
   void adder(int);
   struct shmid_ds buf;

   //Creamos la memoria compartida

   key=ftok("memoriacompartida.c", 1);
   if((shmid= shmget(key,sizeof(double),IPC_CREAT | 0777))==-1)
   {
     exit(1);
   }
   counter = (double * ) shmat(shmid, NULL,0);
   *counter=0.0;

   //Ejecutamos los hijos

   for(int i=0;i< CHILDREN;i++)
   {
     if(!fork())
     {
       adder(i);
       exit(0);
     }
   }

   //Hacemos que el proceso espere

   for(i=0;i< CHILDREN;i++)
   {
     pid_t pid=wait(&status);
     printf("\n Hijo numero %d termina con status %d\n",pid, WEXITSTATUS(status));
   }
  return 0;
}


void adder(int id)
{
  double x=1.0;
  double *counter;
  int i, shmid;
  key_t key;

  //Creamos la meomria compartida

  key=ftok ("shmemory.c",1);
  if((shmid)shmget (key,sizeof(double),0))==-1)
  perror("Child:");

}
