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
        fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
        return EXIT_FAILURE;
    }
    int pipefd[2],i=1,j=1;
    char buff[BUFFER_SIZE];
    pid_t cpid;
    char *fifo = "/home/l2-pc14/Desktop/Ashwin_OS/fifo";
    int x = mkfifo(fifo,0666);
    if(x==-1){
        perror("error creating named pipe");
        exit(EXIT_FAILURE);
    }

    pipefd[0] = open(fifo,O_RDONLY|O_NONBLOCK);
    if(pipefd[0]==-1){
        perror("error opening pipe");
        exit(EXIT_FAILURE);
    }

    close(pipefd[1]);

    cpid = fork();
    if(cpid == -1){
        perror("error fork");
        exit(EXIT_FAILURE);
    }
    else if(cpid == 0){
        int exr = execl("/home/l2-pc14/Desktop/Ashwin_OS/FR","FR",argv[1],NULL);
        if(exr==-1){
            perror("error exec");
            exit(EXIT_FAILURE);
        }
    }
    else{
        printf("\npid = %d,parent id %d\n",getpid(),getppid());
        wait(NULL);
        while(i>0 && j>0){
        i=read(pipefd[0],buff,BUFFER_SIZE);
            if(i==-1){
                perror("error reading(parent)");
                exit(EXIT_FAILURE);
            }
        j=write(STDOUT_FILENO,buff,i);
            if(j==-1){
                perror("error writing(parent)");
                exit(EXIT_FAILURE);
            }
        }
    }
    close(pipefd[0]);   
    return 0;
    }

