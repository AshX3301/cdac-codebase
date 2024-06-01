#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str{
    char *s;
    int size;
    int tos;
};
struct str sta;
char peek();
void push(char);
char pop();
void display();
int IsEmpty();  
int IsFull();
char peek(){
    char x;
    if(!IsEmpty()){
        x = sta.s[sta.tos];
    }
    else
    printf("The stack is empty\n");
return x;
}
void push(char n){
    if(!IsFull()){

        sta.s[++sta.tos] = n;
    }
    else
    printf("The stack is full\n");
}
char pop(){
    char x;
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
    sta.s=NULL;
    sta.tos = -1;
    char strx[50],ch,x;
    int flag = 0,i;
    scanf("%s",strx);    
    sta.size = strlen(strx);
    sta.s = (char*)malloc(sta.size);
    for(i=0;i<sta.size;i++){
        ch = strx[i];
        int a,b;
        switch(ch){
            case '+':
            a = pop();
            b = pop();
            push(b+a);
            break;
            case '-':
            a = pop();
            b = pop();
            push(b-a);
            break;
            case '*':
            a = pop();
            b = pop();
            push(b * a);
            break;
            case '/':
            a = pop();
            b = pop();
            if(a==0){
                flag=1;
                break;
            }
            else
            push(b/a);
            break;
            default:
            push(atoi(&ch));
        }
        if(flag==1){
            printf("Invalid string");
            break;
        }
    }
printf("%d",pop());
free(sta.s);
sta.s = NULL;
}