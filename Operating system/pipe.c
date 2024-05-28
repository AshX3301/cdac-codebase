#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

char wrt_buff[BUFFER_SIZE];

void wrt(int pipefd){
int i=1;
int fx = open("copytxt",O_RDWR);
if(fx==-1){
    perror("error opening file");
    exit(EXIT_FAILURE);
}
while(i>0){
    i = read(fx,wrt_buff,sizeof(wrt_buff));
if(i<0){
        perror("error wrt read");
        exit(EXIT_FAILURE);
}
    write(pipefd,wrt_buff,BUFFER_SIZE);
}
close(fx);
}

int main() {

int pipefd[2],fx;
pid_t cpid;
char buff[BUFFER_SIZE];
int i=1;

if(pipe(pipefd) == -1){
    perror("pipe:");
    exit(EXIT_FAILURE);
}

cpid = fork();

if(cpid == -1){
    perror("fork:");
    exit(EXIT_FAILURE);
}
else if(cpid == 0){
    printf("child pid: %d",getpid());
    close(pipefd[1]);

while(i>0){
        i = read(pipefd[0],buff,BUFFER_SIZE);
if(i<0){
        perror("error reading");
        exit(EXIT_FAILURE);
}
        write(STDOUT_FILENO,buff,BUFFER_SIZE);
}
    close(pipefd[0]);
}
else{
    printf("parent pid: %d\n",getpid());
    wrt(pipefd[1]);
    close(pipefd[1]);
    wait(NULL);
}
return 0;
}