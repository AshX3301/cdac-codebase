#include<stdio.h>
#include<stdlib.h>
void push();
int pop();
int IsEmpty();
int IsFull();
void display();
struct __stack__ {
    int *s;
    int size;
    int tos;
};
struct __stack__ sta;
void push(int n){
    if(!IsFull()){

        sta.s[++sta.tos] = n;
    }
    else
    printf("The stack is full\n");
}
int pop(){
    int x = -999;
    if(!IsEmpty()){
        x = sta.s[sta.tos--];
    }
    else
    printf("The stack is empty\n");
return x;
}

void display(){
for(int i = 0;i<=sta.tos;i++){
    printf(" %d",sta.s[i]);
    printf("\n");
}
}

int IsEmpty(){
    if(sta.tos==-1)
    return 1;
return 0;
}
int IsFull(){
    if(sta.tos == sta.size-1)
    return 1;
return 0;
}

int main(){
int ch,n,y;
sta.s = NULL;
sta.size = 0;
sta.tos = -1;
printf("Stack size?");
scanf("%d",&sta.size);
sta.s = (int*)malloc(sizeof(int)*sta.size);
do {
printf("1.Push\n 2.Pop\n 3.Display\n");
scanf("%d",&ch);
switch(ch) {
    case 1:
    printf("\nEnter elements:");
    for(int i=0;i<sta.size;i++){
        scanf("%d",&n);
        push(n);
    }
    break;
    case 2:
    y=pop();
    printf("\n%d deleted",y);
    break;
    case 3:
    display();
    break;

    default:
    printf("Not a valid option\n");
}
}while(ch!=0);
free(sta.s);
sta.s = NULL;
}