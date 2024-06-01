#include<stdio.h>
//#include<string.h>

int main(){
    char c[100];
    int i = 0,count = 0;
    fgets(c,sizeof(c),stdin);
    //scanf("%s",c);
    for(int i=0;(c[i] != '\0' && c[i] != '\n');i++){
    count++;}
    printf("%d",count);
}

