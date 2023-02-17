#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
        char buf[1024]={0};
          int fd;
          if(mkfifo("./file",0600) == -1 && errno != EEXIST){
                printf("mkfifo fail\n");
                perror("why");
        }

        fd = open("./file",O_RDONLY);
        printf("read open success\n");

        while(1){
                int n_read = read(fd,buf,128);
                printf("read %d byte,contxt = %s \n",n_read,buf);
        }

        close(fd);

        return 0;

}

