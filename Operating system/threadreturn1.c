#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

#define semname_w "/signal_write"
#define semname_r "/signal_read"
#define handle_error(msg) do{perror(msg);exit(EXIT_FAILURE);}while(0)

pthread_attr_t attr;
sem_t *semlock;
pthread_mutex_t mutx;
int indx=0;
int z=0;
struct fact{
int fact;
int num;
};
struct fact fx;
sem_t *signal_write,*signal_read;

void *red(void *arg_x){
    int **argx = arg_x;
    int *mapx = argx[0];
    int *i = argx[1];
    if(sem_wait(&semlock[indx])!=0)
    handle_error("sem_wait");
    sem_wait(signal_write);
    int res = mapx[*i];
    printf("Recieve Thread %d recieved %d\n",*i,res);
    sem_post(signal_read);
    if(indx+1<fx.num)
    if(sem_post(&semlock[++indx])!=0){
    handle_error("sem thread signal error");
}   
    
}

int main(){
fx.num = 10;
pthread_t threadx[fx.num];
semlock = (sem_t*)malloc(fx.num*sizeof(sem_t));
if(semlock == NULL)
    handle_error("malloc semaphore");
for(int i=0;i<fx.num;i++){
    if(sem_init(&semlock[i],0,i==0 ? 1:0)!=0){
        handle_error("sem init");
    }
}
int src = shm_open("/factstore",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
if(src == -1)
    handle_error("error shared memory open");
if(ftruncate(src,fx.num*sizeof(int))==-1)
    handle_error("truncate error");
int *map = mmap(NULL,fx.num*sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,src,0);
if(map == MAP_FAILED)
    handle_error("error mapping");
signal_write = sem_open(semname_w,O_CREAT|O_RDWR,0666,0);
if(signal_write == SEM_FAILED)
    handle_error("error opening named semaphore");
// if(sem_init(signal_write,1,0)!=0)
//     handle_error("sem init_write error");
signal_read = sem_open(semname_r,O_CREAT|O_RDWR,0666,0);
if(signal_read == SEM_FAILED)
    handle_error("error opening named semaphore");
// if(sem_init(signal_read,1,1)!=0)
//     handle_error("sem init_read error");
int **arg = (int**)malloc(2*sizeof(int*));
arg[0] = map;
printf("argument : %p map : %p",arg[0],map);
for(int i=0;i<fx.num;i++){
    arg[1] = &i;
    if(pthread_create(&threadx[i],NULL,red,(void**)arg)!=0)
        handle_error("thread create error in read");
    usleep(100);
}
for(int i=0;i<fx.num;i++){
if(pthread_join(threadx[i],NULL)!=0)
        handle_error("thread join error in read");
}
for(int i=0;i<fx.num;i++){
    if(sem_destroy(&semlock[i])!=0)
    handle_error("sem destroy error");
}
free(semlock);
semlock = NULL;
free(arg);
arg = NULL;
}