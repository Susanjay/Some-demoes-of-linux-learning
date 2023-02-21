#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char **argv)
{
        int signum;
        int pid;

        signum=atoi(argv[1]);
        pid=atoi(argv[2]);

        union sigval value;
        value.sival_int=100;

        sigqueue(pid,signum,value);
        printf("%d,done\n",getpid());
        return 0;
}

