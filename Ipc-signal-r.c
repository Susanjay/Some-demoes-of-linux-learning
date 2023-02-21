#include<signal.h>
#include<stdio.h>
void    handler(int signum, siginfo_t *info, void *context)
{
        printf("get signum=%d\n",signum);
        if(context!=NULL){
                printf("get data=%d\n",info->si_int);
                printf("get data=%d\n",info->si_value.sival_int);
                printf("from:%d\n",info->si_pid);
        }
}
int main()
{
        struct sigaction act;
	act.sa_sigaction=handler;
        act.sa_flags=SA_SIGINFO; ///be able to get message
        sigaction(SIGUSR1,&act,NULL);
        while(1);
	return 0;




}
