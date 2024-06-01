#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct sting{
char *s;
int size;
int tos;
};
char peek();
void push(char);
char pop();
void display();
int IsEmpty();
int IsFull();

struct sting sta;
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
    char str[50],ch,x;
    int length=0,flag = 0,i;
    printf("Enter the string:");
    scanf("%s",str);    
    length = strlen(str);
    sta.size = length;
    sta.s = (char*)malloc(sta.size);
    for(i=0;i<=length-1;i++){
        ch = str[i];
        switch(ch){
            case '(':
            push(ch);
            break;
            case '[':
            push(ch);
            break;
            case '{':
            push(ch);
            break;
            case ')':if(!(peek()=='(')){ 
                        flag=1;
            }
                    else{
                    x = pop();
                    printf("\n%c",x);
                    }
            break;
            case ']':if(!(peek()=='[')){ 
                    flag=1;
                    
            }
                    else{
                    x = pop();
                    printf("\n%c",x);
                    }
            break;
            case '}':if(!(peek()=='{')){
                    flag=1;
            }
                    else{
                    x = pop();
                 printf("\n%c",x);
                    }
            break;
            default:
            break;

        }
        if(flag==1)
        break;
    }
    
    if(flag==1)
    printf("Unbalanced");

    else if(i==length && IsEmpty())
    printf("Balanced");
    else
    printf("Unbalanced");
free(sta.s);
sta.s = NULL;
}