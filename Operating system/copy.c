#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#define BUFF_SIZE 500

int main(){
char buff[BUFF_SIZE];
int fp,fx,i=1,j=1,pid;
printf("process ID:%d\n",getpid());
pid = fork();
if(pid<0){
    perror("failed");
    exit(EXIT_FAILURE);
}
else if(pid == 0){
    printf("This is child: pid = %d,ppid = %d\n",getpid(),getppid());
}
else
printf("This is parent: pid = %d,ppid = %d\n",getpid(),getppid());


fp = open("/home/l2-pc14/Desktop/Ashwin/file",O_RDONLY);
if(fp == -1){
    perror("error");
    exit(EXIT_FAILURE);
}
fx = open("/home/l2-pc14/Desktop/Ashwin_OS/copytxt",O_WRONLY);
if(fx == -1){
    perror("error");
    exit(EXIT_FAILURE);
}
while(i>0&&j>0){
i = read(fp,buff,BUFF_SIZE);
if(i==-1){
    perror("Error reading:");
    exit(EXIT_FAILURE);
}
j=write(fx,buff,BUFF_SIZE);
if(j==-1){
    perror("Error writing:");
    exit(EXIT_FAILURE);
}
}
close(fx);
close(fp);

printf("Files copied\n");
}