#include<stdio.h>
int main() {
    int a , b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %f\n",a,b,(float)a/b);
    printf("%d modulus %d\n = %d",a,b,a%b);
}