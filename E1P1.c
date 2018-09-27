#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>

#define CHILDREN 3


int main()
{
  int i, shmid, status;
  key_t key;
  int *ptr;

  //Creamos la memoria compartida
  key=ftok("E1P1.c",3);
  if((shmid= shmget(key,100*sizeof(int),IPC_CREAT | 0777))==-1)
  exit(1);
  ptr=(int*)shmat(shmid,NULL,0);


  for (i = 0; i < 3; i++)
  {
      if (!fork())
        {
          if(i=0){}

        }
  }

      fprintf(stdout, "Counter: %f\n", *counter);
}
/
