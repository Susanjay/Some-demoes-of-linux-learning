#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
//ssize_t write(int fd, const void *buf, size_t count);
//int mkfifo(const char *pathname, mode_t mode);
//int open(const char *pathname, int flags);
 
int main()
{
        int fd;
        char *str = "message from fifo";
        int cnt = 0;
 
        fd = open("./file",O_WRONLY);
        printf("write open success\n");
 
        while(1){
                write(fd,str,strlen(str));
 
                sleep(1);
        }
        close(fd);
	return 0;
}

