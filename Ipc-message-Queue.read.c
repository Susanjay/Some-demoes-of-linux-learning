 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
#include<stdio.h>
#include<string.h>
struct msgbuf{

   long mtype;
   char mtext[128];



};
int main()
{
      int msgID =msgget(0x1237, IPC_CREAT|0777);
struct  msgbuf readbuf;
struct msgbuf sendbuf={988,"this is message content of 988!"};
      if(msgID==-1)
      {
          printf("creat message queue failed !\n");

      
      }

     // int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

      msgrcv(msgID, &readbuf, sizeof(readbuf.mtext), 888,0);
      msgsnd(msgID, &sendbuf, strlen(sendbuf.mtext), 0);
      printf("read content of 888: %s\n",readbuf.mtext);
return 0;


}
