#include<stdio.h>

int main() {
    float r,p,a;
    printf("enter the radius of the circle:");
    scanf("%f",&r);
    
    a=3.14*r*r;
    p=3.14*2*r;

    printf("area = %f\n perimeter = %f\n",a,p);

    
}