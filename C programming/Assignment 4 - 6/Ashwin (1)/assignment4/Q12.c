#include<stdio.h>
int swap(int *x,int *y){
    int ptr;
    ptr = *x;
    *x = *y;
    *y = ptr;
}
int main(){
    int a,b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("%d %d",a,b);
}