#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str{
char *opsrt;
int size;   
int  tos;
}; 
struct str sta;
int prec(char);
int peek();
void push(char);
char pop();
void display();
int IsEmpty();  
int IsFull();
int op(char*,int);
void rev(char*);
int prec(char ch){
    switch(ch){
        case '*':
        case '/':
        return 3;
        break;
        case '+':
        case '-':
        return 2;
        break;
        case ')':
        case ']':
        case '}':
        return 1;
        break;
        
    }
}
int peek(){
    int x=-999;
    if(!IsEmpty()){
        x = sta.opsrt[sta.tos];
    }
    else
    printf("The stack is empty\n");
return x;
}
void push(char n){
    if(!IsFull()){

        sta.opsrt[++sta.tos] = n;
    }
    else
    printf("The stack is full\n");
}
char pop(){
    char x;
    if(!IsEmpty()){
        x = sta.opsrt[sta.tos--];
    }
    else
    printf("The stack is empty\n");
return x;
}

void display(){
for(int i = 0;i<=sta.tos;i++){
    printf(" %c",sta.opsrt[i]);
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
int op(char *strx,int j){
switch(peek()){
    case '+':
    case '-':
    case '*':
    case '/':
   strx[j++]=pop();
    break;
    
}
}
/*void rev(char *strx){
for(int i=0;i<sta.size/2;i++){
    char temp = strx[i];
    strx[i] = strx[sta.size-i-1];
    strx[sta.size-i-1] = temp;
}
}
*/
int main(){
    sta.opsrt=NULL;
    sta.tos = -1;
    char str[50],ch,x;
    int length=0,flag = 0,j=0,i;
    printf("Enter the string:");
    scanf("%s",str);    
    length = strlen(str);
    sta.size = length;
    sta.opsrt = (char*)malloc(sta.size);
    char strx[length];
    for(i=length-1;i>=0;i--){
        ch =str[i];
        switch(ch){
            case ')':
            //(ch); break;
            case ']':
           // push(ch);break;
            case '}':
            push(ch);
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            if(!IsEmpty()){
                while(!IsEmpty() && prec(peek())>prec(ch)){
                    strx[j++]=pop();
                }
            }
            push(ch);
            break;
            case '(':
            case '[':
            case '{':
            while(peek()!=')' && peek()!=']' && peek()!='}'){
                strx[j++] = pop();
            }
                x = pop();
            break;
            default:
            strx[j++] = ch;
            break;
        }
    }
op(strx,j);
strx[j] = '\0';
//rev(strx);
//printf("%s",strx);

for(j=0;j<sta.size-1;j++){
    push(strx[j]);
}
for(j=0;j<sta.size-1;j++){
    printf("%c",pop());
}

free(sta.opsrt);
sta.opsrt = NULL;
}
