#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 50
int main(int argc,char *argv[]) {
   if(argc !=2){
        fprintf(stderr,"Usage: %s <filename\n>",argv[0]);
        return EXIT_FAILURE;
    }
    int pipefd[2],fx,i=1,j=1;
    char buff[BUFFER_SIZE];
    char *fifo = "/home/l2-pc14/Desktop/Ashwin_OS/fifo";
    char *filex = argv[1];
    pipefd[1] = open(fifo,O_WRONLY|O_NONBLOCK);
   
    if(pipefd[1]==-1){
        perror("error opening named pipe");
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]);

    fx = open(filex,O_RDWR);
    if(fx==-1){
        perror("error opening file");
        exit(EXIT_FAILURE);
    }
    while(i>0 && j>0){
       i = read(fx,buff,BUFFER_SIZE);
       if(i==-1){
        perror("error reading(exec)");
        exit(EXIT_FAILURE);
       }
       j = write(pipefd[1],buff,i);
       if(j==-1){
        perror("error writing (exec)");
        exit(EXIT_FAILURE);
       }
    }
    close(fx);
    close(pipefd[1]);
    printf("\nexec child pid = %d,exec parent id %d\n",getpid(),getppid());

}