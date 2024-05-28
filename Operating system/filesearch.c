#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <mqueue.h>

#define handle_error(msg) do{perror(msg);exit(EXIT_FAILURE);}while(0) //error handler

char *pipeline = "/home/l2-pc14/Desktop/Ashwin_OS/pipeline";
char *que_name = "/frequency";
           struct mq_attr {
               long mq_flags;       /* Flags (ignored for mq_open()) */
               long mq_maxmsg;      /* Max. # of messages on queue */
               long mq_msgsize;     /* Max. message size (bytes) */
               long mq_curmsgs;     /* # of messages currently in queue
                                       (ignored for mq_open()) */
           };
struct mq_attr attr;
int main(){
attr.mq_maxmsg = 10;
attr.mq_maxmsg = sizeof(char*);
attr.mq_curmsgs = 0;
attr.mq_flags = 0;
if(mkfifo(pipeline,0666)!=0) //opening named pipe for data processing
    handle_error("error creating named pipe");
int pipefd = open(pipeline,O_WRONLY);


}