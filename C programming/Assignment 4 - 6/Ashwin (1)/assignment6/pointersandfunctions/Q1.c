#include<stdio.h>

int main(){
    int num,*ptr;
    printf("Enter the number:");
    scanf("%d",&num);
    ptr = &num;
    printf("The number value:%d\n",num);
    printf("The number value using pointer:%d",*ptr);
}