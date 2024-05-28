#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define commands 100
#define argument 10

int main(){
char comm[commands];
char *arg[argument];
int pid;
while(1){
    printf("bash>>");
    //scanf("%s",comm);
    fgets(comm,commands,stdin);
    //arg[0] = strtok(comm," ");
    int len = strlen(comm);
    if(len>0 && comm[len-1]=='\n'){
        comm[len-1] = '\0';
    }
    int count =0;
    char *tok = strtok(comm," ");
    while(tok!=NULL && count<argument-1){
        //printf("%s\n",tok);
        arg[count++] = tok;
        tok = strtok(NULL," ");
    }
    arg[count] = NULL;
    pid = fork();
    if(pid==-1){
        perror("fork failed:");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        int exr = execvp(arg[0],arg);
        printf("process ID: %d\n",getpid());
        if(exr == -1){
            perror("exec failed:");
            exit(EXIT_FAILURE);
        }
    }
    else
    waitpid(pid,NULL,0);

}
return 0;
}