#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include<errno.h>

#define BUFFER_SIZE 500
#define handle_error(msg) do{perror(msg);exit(EXIT_FAILURE);}while(0)

//thread function declarations
void *thread1();
void *thread2();
void *stream(void *);

//global variables
int cpid1,cpid2,pipefd[2],fd;
char buff[BUFFER_SIZE];
const char *pipex1 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex1";
const char *pipex3 = "/home/l2-pc14/Desktop/Ashwin_OS/pipex3";
pthread_t thread_x,thread_y,thread_z;


void *stream(void *pipex3){ //stream from p3 to p1
     printf("stream running\n");
    char buffx[BUFFER_SIZE];
    int fd = open((const char*)pipex3,O_RDONLY);
    if(fd == -1){
        handle_error("error opening pipe3!");
    }
    while(read(fd,buffx,BUFFER_SIZE)>0){
        write(STDOUT_FILENO,buffx,BUFFER_SIZE);//print processed data back to terminal
    }
    close(fd);
}

void *thread1(){
    printf("Thread 1 executing\n");
    cpid1 = fork();
    if(cpid1 == -1){
        handle_error("error creating child1");
    }
    else if(cpid1 == 0){
        printf("child1 process ID = %d",getpid());
        int exr = execl("/home/l2-pc14/Desktop/Ashwin_OS/fp2","fp2",NULL);
        if(exr ==-1){
            handle_error("error in exec1");
        }
    }
    else{
        sleep(3); 
        pthread_create(&thread_y,NULL,thread2,NULL);//creating thread for exec2
        printf("waiting for thread 2 to complete\n");
        pthread_join(thread_y,NULL);
    }

}

void *thread2(){
    printf("Thread 2 executing\n");
    cpid2 = fork();
        if(cpid2==-1){
            handle_error("error creating child2");
        }
        else if(cpid2 == 0){
        int exr = execl("/home/l2-pc14/Desktop/Ashwin_OS/fp3","fp3",NULL);
        if(exr ==-1){
            perror("error in exec2");
            handle_error("");
        }
        }
        else{
            sleep(5);
            pthread_create(&thread_z,NULL,stream,(void *)pipex3);//thread for stream
            printf("waiting for thread 3(stream) to complete\n");
            pthread_join(thread_z,NULL); 
        }
}

int main(int argc,char *argv[]){
    if(argc !=2){
        fprintf(stderr,"Usage: %s <filename>\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    char *filex = argv[1];
    int x = mkfifo(pipex1,0666);
    if(x==-1){
        handle_error("error creating named pipe");
    }
    pthread_create(&thread_x,NULL,thread1,NULL); //creating first thread for exec 1
    printf("Main continuing execution\n");
    sleep(2);
    pipefd[1] = open(pipex1,O_WRONLY);
    if(pipefd[1]==-1){
        handle_error("error opening pipeline");
    }
    fd = open(filex,O_RDONLY);
    while(read(fd,buff,BUFFER_SIZE)>0){
        write(pipefd[1],buff,BUFFER_SIZE);
        }
    close(fd);
    printf("waiting for thread 1 execution to complete\n");
    pthread_join(thread_x,NULL);
    printf("All thread executions complete\n");
return 0;
}