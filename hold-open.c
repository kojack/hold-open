#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *filename = NULL;
    int fd;
    int ret;
    char buf[16];
    int seconds = 30000;

    if(argc >= 2) {
       filename = argv[1];
       if(argc >= 3) seconds = atoi(argv[2]);
    }
    else {
       printf("%s <file name>\n", argv[0]);
       exit(1);
    }

    fd = open(filename, O_RDONLY);
    if(fd == -1) {
       perror("open");
       exit(1);
    }

    while(seconds--) {
       sleep(1);
    }

    ret = close(fd);
    if(ret == -1) {
       perror("close");
       exit(1);
    }

    return(0);
}
