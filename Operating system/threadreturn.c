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
struct fact{
int fact;
int num;
};
struct fact fx;
sem_t *signal_write,*signal_read;

void *fact(void *n){

int num = *(int*)n;
printf("Write thread [%d] executing\n",num);
printf("th1\n");
if(sem_wait(&semlock[indx])!=0)
    handle_error("sem_wait");

int *result = malloc(sizeof(int));
pthread_mutex_lock(&mutx);
*result = 1;
pthread_mutex_unlock(&mutx); 
for(int i=1;i<=num;i++){
    pthread_mutex_lock(&mutx);
    *result *= i;
    pthread_mutex_unlock(&mutx); 
}
printf("th2\n");
if(indx+1<fx.num)
if(sem_post(&semlock[++indx])!=0){
    handle_error("sem thread signal error");
}
pthread_mutex_lock(&mutx);
fx.fact = *result;
pthread_mutex_unlock(&mutx); 
printf("th3\n");
pthread_exit((void*)result);

}


int main(){ 
int y;

signal_write = sem_open(semname_w,O_CREAT|O_RDWR,0666,0);
if(signal_write == SEM_FAILED)
    handle_error("error opening named semaphore");
// if(sem_init(signal_write,1,0)!=0)
//     handle_error("sem init_write error");
signal_read = sem_open(semname_r,O_CREAT|O_RDWR,0666,1);
if(signal_read == SEM_FAILED)
    handle_error("error opening named semaphore");
// if(sem_init(signal_read,1,1)!=0)
//     handle_error("sem init_read error");

if(pthread_attr_init(&attr)!=0)
handle_error("init thread");
if(pthread_mutex_init(&mutx,NULL)!=0){
    handle_error("mutex_init");
}
size_t stacksize = 4*1024*1024;
if(pthread_attr_setstacksize(&attr,stacksize)!=0)
    handle_error("stack size error");

printf("Enter the limit:");
scanf("%d",&fx.num);
printf("1\n");
int shx = shm_open("/factstore",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
if(shx==-1){
    handle_error("shared memory error");
}
y = ftruncate(shx,fx.num*sizeof(int));
if(y==-1)
    handle_error("truncate error");
int *map = mmap(NULL,sizeof(int)*fx.num,PROT_READ|PROT_WRITE,MAP_SHARED,shx,0);
if(map == (void *) -1){
    handle_error("map error");
}
printf("2\n");
semlock = (sem_t*)malloc(fx.num*sizeof(sem_t));
if(semlock == NULL)
    handle_error("malloc semaphore");
for(int i=0;i<fx.num;i++){
    if(sem_init(&semlock[i],0,i==0 ? 1:0)!=0){
        handle_error("sem init");
    }
}
printf("3\n");

pthread_t threadx[fx.num];
if(threadx == NULL){
    handle_error("thread handle memory allocation failed");
}
printf("4\n");
for(int i=0;i<fx.num;i++){
    printf("5\n");
    if(pthread_create(&threadx[i],&attr,fact,&i)!=0)
    handle_error("thread create error:");
    usleep(100);
}
int *result;
for(int i=0;i<fx.num;i++){
    pthread_join(threadx[i],(void**)&result);
    sem_wait(signal_read);//wait until read operation is complete;
    map[i] = *result;
    usleep(100);
    sem_post(signal_write);//signal write operation complete

    printf("Thread %d returned factorial:%d\n",i,*result);
}

if(pthread_attr_destroy(&attr)!=0)
    handle_error("destroy error attr");
for(int i=0;i<fx.num;i++){
    if(sem_destroy(&semlock[i])!=0)
    handle_error("sem destroy error");
}
free(result);
free(semlock);
semlock = NULL;
// if(munmap((void*)shx,fx.num*sizeof(int))!=0){
//     handle_error("unmap error");
// }
// shm_unlink("/factstore");
return 0;
}
