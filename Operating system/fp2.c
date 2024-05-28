#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define NUM_CHAR 256

int main() {
  printf("exec 2 running\n");
  int pipefd[2],pipefd_x[2];
  char buff[BUFFER_SIZE];
  unsigned int *freq;
  const char *pipex2 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex2";
  const char *pipex3 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex3";
  freq = (int *)calloc(NUM_CHAR,sizeof(int));
  if(freq == NULL){
    printf("error allocating continuous memory\n");
    exit(EXIT_FAILURE);
  }
  int x = mkfifo(pipex3,0666);
      if(x == -1){
        perror("error creating pipe3 in child2");
        exit(EXIT_FAILURE);
    }
    else{
        printf("pipe3 created");
    }
    pipefd[0] = open(pipex2,O_RDONLY|O_NONBLOCK);
    if(pipefd[0] == -1){
        perror("error opening pipe(r) in child2");
        exit(EXIT_FAILURE);
    }
    close(pipefd[1]);
    pipefd_x[1] = open(pipex3,O_WRONLY);
    if(pipefd_x[1] == -1){
        perror("error opening pipe(w) in child2");
        exit(EXIT_FAILURE);
    }
    close(pipefd_x[0]);
    while(read(pipefd[0],buff,BUFFER_SIZE)>0){
        for(int i=0;i<=NUM_CHAR;i++){
        freq[(unsigned char)buff[i]]++;
        }
        write(pipefd_x[1],buff,BUFFER_SIZE);
    }
    for(int i=0;i<=NUM_CHAR;i++){
        printf("%c count = %d\n",(char)i,freq[i]);
    }
    free(freq);
    freq = NULL;
    close(pipefd_x[1]);
    close(pipefd_x[0]);
return 0;
}