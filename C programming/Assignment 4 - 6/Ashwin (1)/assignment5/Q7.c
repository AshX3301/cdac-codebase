#include<stdio.h>

int main(){
    int n,op;
    printf("enter a number:");
    scanf("%d",&n);
    op = n&0x9B;
    printf("input = %d\n output = %d",n,op);
    return 0;
    
}