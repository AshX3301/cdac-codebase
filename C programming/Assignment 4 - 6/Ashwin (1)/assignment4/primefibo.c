#include<stdio.h>
int primefib();
int isprime();
int fibo(int n){
    if(n==0 || n==1)
    return 1;
    else
    return fibo(n-1)+fibo(n-2);
}
int isprime(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0)
        return 0;

    }
    return 1;
}
int primefib(int x,int z){
    int y;
for(int i=2;i<=x;i++){
y = fibo(i);
if(isprime(y) && y>z){
    printf(" %d ",y);

}
}
}
int main() {
int ulimit,llimit;
printf("Enter the upper and lower limits:");
scanf("%d %d",&ulimit,&llimit);
primefib(ulimit,llimit);
return 0;
}
