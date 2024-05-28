#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 500
pid_t cpid;
int pipefd[2];
char *pipex4 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex4";
char buff[BUFFER_SIZE];
pthread_t threadx;
    
void *create_child(void *filex){
//sleep(3);
cpid = fork();
if(cpid == -1){
    perror("error creating child");
    exit(EXIT_FAILURE);
}
else if(cpid == 0){
    printf("thread execution about to enter exec\n");
    int y = execl("/home/l2-pc14/Desktop/Ashwin_OS/trx","trx",(char*)filex,NULL);
    if(y == -1){
        perror("exec failed");
        exit(EXIT_FAILURE);
    }
}
else{
    printf("parent process running in thread\n");
    pipefd[0] = open(pipex4,O_RDONLY);
    if(pipefd[0]==-1){
        perror("error opening pipe");
        exit(EXIT_FAILURE);
    }
    while(read(pipefd[0],buff,BUFFER_SIZE)>0){
        write(STDOUT_FILENO,buff,BUFFER_SIZE);
    }
    close(pipefd[0]);

}
}

int main(int argc,char *argv[]) {
    if(argc !=2){
        fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
        return EXIT_FAILURE;
    }
    char *filex = argv[1];

    if(pthread_create(&threadx,NULL,create_child,(void *)filex)!=0){ //create thread(unit of execution)
        perror("error creating threadx");
        exit(EXIT_FAILURE);
    }
    printf("main  11111111111\n");
    int x = mkfifo(pipex4,0666);
    if(x == -1){
        perror("error creating pipe4");
        exit(EXIT_FAILURE);
    }
    printf("main process running\n");
    if(pthread_join(threadx,NULL)!=0){
        perror("error joining threadx");
        exit(EXIT_FAILURE);
    }
    close(pipefd[1]);
  
return 0;
}