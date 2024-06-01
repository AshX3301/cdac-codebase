#include<stdio.h>
#include<string.h>
void strg(char *str,int x){
    for(int i=0;i<x/2;i++){
       char temp = str[i];
        str[i] = str[x-i-1];
        str[x-i-1] = temp;
       
    }
     printf("%s",str);
     

}

int main(){
    char str[100];
    int length;
    scanf("%s",str);
    length = strlen(str);
    //printf("%d",length);
    strg(str,length);
    //printf("%s",str);
    return 0;
}
