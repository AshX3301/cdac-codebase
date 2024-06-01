#include<stdio.h>

int main() {
    float i,p,t,r;
    printf("enter the principal,rate and time:");
    scanf("%f %f %f",&p,&r,&t);
    
    i = (p*t*r)/100.0;

    printf("The simple interest of your loan is: %0.2f",i);

    return 0;
}