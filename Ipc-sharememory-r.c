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
    shmid=shmget(key,1024*4,0);//寻找此前写demo创建的内存块通过相同的key值。
     if(shmid==-1)
     {
       printf("open sharedmemory failed !\n");
       exit(-1);
     
     }
     // void *shmat(int shmid, const void *shmaddr, int shmflg);
     shmaddr=shmat(shmid,0,0);//与找到的虚拟内存块建立连接。
     if(shmaddr==(char *)-1)
     {
       printf("Shared memory address mapping failed ！\n");
     
     }
     else
     {
        printf("Shared memory address mapping successful ! \n");
	printf("content : %s\n",shmaddr);
     }
     printf("Quit\n");
return 0;

}
     //  int shmget(key_t key, size_t size, int shmflg);

