#include<stdio.h>
int fibo(int n){
    if(n==0 || n==1)
    return 1;
    else
    return fibo(n-1)+fibo(n-2);
}
int main() {
int limit;
scanf("%d",&limit);
for(int i=0;i<=limit;i++)
printf(" %d",fibo(i));

}