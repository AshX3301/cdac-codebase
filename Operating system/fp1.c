#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 500

int main() {
    printf("exec 1 running\n");
    int pipefd[2],pipefd_x[2],count,tcount,fd;
    char buff[BUFFER_SIZE];
    char *tok,*stream;
    char countx;
    stream = (char*)malloc(BUFFER_SIZE);
    if(stream == NULL){
        printf("memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    fd = open("sample.txt",O_RDWR);
    const char *pipex1 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex1";
    const char *pipex2 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex2";
    int x = mkfifo(pipex2,0666);
    pipefd[0] = open(pipex1,O_RDONLY|O_NONBLOCK);
    if(pipefd[0] == -1){
        perror("error opening pipe(r) in child1");
        exit(EXIT_FAILURE);
    }
    close(pipefd[1]);
    pipefd_x[1] = open(pipex2,O_WRONLY);
    if(pipefd_x[1] == -1){
        perror("error opening pipe(w) in child1");
        exit(EXIT_FAILURE);
    }
    close(pipefd_x[0]);
    while(read(pipefd[0],buff,BUFFER_SIZE)>0){
        tok = strtok(buff," ");
        count = 0;
        while(tok!=NULL && count!=BUFFER_SIZE-1){
        stream[count++] = *tok;
        tok = strtok(NULL," ");
        tcount++;
        }
        write(pipefd_x[1],stream,BUFFER_SIZE);
        write(fd,stream,BUFFER_SIZE);

    }
    close(pipefd_x[1]);
    close(fd);
    close(pipefd[0]);
    //itoa(tcount,countx,10);
    //write(pipefd_x[1],countx,sizeof(countx));
    free(stream);
    stream = NULL;
return 0;
}

