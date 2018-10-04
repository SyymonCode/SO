#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

#define   CHILDREN 3
#define ITER 5
#define MAX 9999

<<<<<<< HEAD

int main()
{
  int i, shmid, status;
  key_t key;
  int *ptr;
=======
int main()
{
  int i, shmid,val,num,status,sumatorio;
  key_t key;
  int  *ptr;
  struct shmid_ds buf;
>>>>>>> d29f248a3949644770cb6d742046463959fd808f

  //Creamos la memoria compartida
  key=ftok("E1P1.c",3);
  if((shmid= shmget(key,100*sizeof(int),IPC_CREAT | 0777))==-1)
  exit(1);
<<<<<<< HEAD
  ptr=(int*)shmat(shmid,NULL,0);


  for (i = 0; i < 3; i++)
  {
      if (!fork())
        {
          if(i=0){}

        }
  }

      fprintf(stdout, "Counter: %f\n", *counter);
=======
  //Dirigimos el puntero hacia la memoria
ptr= (int *) shmat(shmid,NULL,0);
//Primer Hijo
if(!fork())
  {
    printf("Hijo 1 creado\n" );
    for (int i = 0; i < 10; i++)
    {
      printf("Introduce la posicion del vector en el que quieres añadir un valor\n");
      scanf("%d", &val );
      printf("Introduce el valor\n");
      scanf("%d", &num  );
      ptr[val]=num;
      printf("El valor en la posicion %d es %d\n", val, ptr[val]);
    }
    exit(0);
  }
//Segundo hijo
if (!fork())
{
    printf("Hijo 2 creado\n");
    for(int i=0; i<100; i++)
    {
      ptr[rand()%100]=rand()%MAX;
      sleep(1);
    }

    exit(0);
}

//Tercer hijo
if (!fork())
 {
    printf("Hijo 3 creado\n");
    for(int i=0;i<5;i++)
    {
      for(int j=0; j<100; j++)
      {
        sumatorio=sumatorio+ptr[j];
      }
      printf("La suma del vector es %d\n",sumatorio );
      //sleep(30);
    }
    exit(0);
  }
  //Espera a que terminen
  for (i = 0; i < CHILDREN; i++)
  {
    pid_t pid = wait(&status);
    printf("\nChild %d finished with status %d\n", pid, WEXITSTATUS(status));
  }
  fprintf(stdout, "vector: %i\n",*ptr );
  shmdt(ptr);
  shmctl(shmid,IPC_RMID,&buf);
  return 0;
>>>>>>> d29f248a3949644770cb6d742046463959fd808f
}
/
