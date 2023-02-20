#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
    int shmid = 786447; 
    struct shmid_ds ds; //声明一个结构体类型的shmid_ds保存共享内存的信息
    int res = shmctl(shmid, IPC_STAT, &ds);  //查询共享内存
    if (res == -1) 
    {   
        perror("shmctl");
        exit(-1);
    }   
    printf("cpid = %d, lpid = %d\n", ds.shm_cpid, ds.shm_lpid); //获取创建PID和最后使用的PID
}
