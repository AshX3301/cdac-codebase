#include<stdio.h>
#include<stdlib.h>

struct __queue__ {
    int *q;
    int size;
    int front;
    int rear;
};
struct __queue__ cque;
int underflow();
int overflow();
void enque(int);
int deque();
void display();
void point();
int underflow(){
    if(cque.front == -1 && cque.rear == -1)
    return 1;
return 0;
}

int overflow(){
    if(cque.front == (cque.rear+1)%cque.size)
    return 1;
return 0;
}

void enque(int n){
    if(!overflow()){
        if(cque.front == -1){
            cque.front++;
            
        }cque.rear=(cque.rear+1)%cque.size;
        cque.q[cque.rear]= n;
    }
    else 
    printf("\nThe queue is full");
}

int deque(){
    int x = -999;
    if(!underflow()){
        x = cque.q[cque.front];
        if(cque.front==cque.rear){
        cque.front=-1;
        cque.rear = -1;
        }
        else
        cque.front=(cque.front+1)%cque.size;
    }
    else
    printf("\nThe queue is empty");
return x;
}

void display(){
    for(int i=cque.front;i!=cque.rear;i=(i+1)%cque.size){
        printf("%d",cque.q[i]);
    }
    printf("%d",cque.q[cque.rear]);
    printf("\n");
}
void point(){
    printf("Front:%d\n",cque.front);
    printf("Rear:%d\n",cque.rear);
}
int main(){
    cque.q = NULL;
    cque.size = 0;
    cque.front = -1;
    cque.rear = -1;
    int ch,x,y;
    printf("Enter the queue size:");
    scanf("%d",&cque.size);
    cque.q = (int*)malloc(cque.size*sizeof(int));
    do{
    printf("Enter your choice\n 1.Enque\n 2.Deque\n 3.Display\n 4.Pointer position\n");
    scanf("%d",&x);
    switch(x){
        case 1:
        printf("Enter the element:");
        scanf("%d",&y);
        enque(y);
        break;
        case 2:
        printf("Element %d has been deleted",deque());
        break;
        case 3:
        display();
        break;
        case 4:
        point();
        break;
        default:
        printf("Not a valid operation");
    }
    }while(x!=0);
free(cque.q);
cque.q = NULL;
}