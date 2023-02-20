 #include <sys/ipc.h>
 #include <sys/types.h>
 #include <sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    key_t key;
    key=ftok(".",1);
    int shmid;
    char *shmaddr;
    shmid=shmget(key,1024*4,IPC_CREAT|0666);
     if(shmid==-1)
     {
       printf("creat sharedmemory failed !\n");
       exit(-1);
     
     }
     // void *shmat(int shmid, const void *shmaddr, int shmflg);
     shmaddr=shmat(shmid,NULL,0);
     if(shmaddr==(char *)-1)
     {
       printf("Shared memory address mapping failed ！\n");
     
     }
     else
     {
        printf("Shared memory address mapping successful ! \n");
	strcpy(shmaddr,"zhaoebin nice !");
     }
     sleep(5);
     shmdt(shmaddr);
     shmctl(shmid,IPC_RMID,0);
     printf("Quit\n");
return 0;

}
     //  int shmget(key_t key, size_t size, int shmflg);

