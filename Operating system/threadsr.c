#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 500
int pipefd[2];
char *pipex4 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex4";
char buff[BUFFER_SIZE];
int main(int argc,char *argv[]) {
    if(argc != 2){
        fprintf(stderr,"Usage:%s <filename>\n",argv[0]);
        return EXIT_FAILURE;
    }
    printf("exec running succesfully\n");
    pipefd[1] = open(pipex4,O_WRONLY);
    char *filex = argv[1];
    int fd = open(filex,O_RDONLY);
    while(read(fd,buff,BUFFER_SIZE)>0){
        write(pipefd[1],buff,BUFFER_SIZE);
    }
return 0;
}