#include<stdio.h>
int main(){
    int i=8,j=5,E1,E2,E3,E5;
    float x=0.005,y=0.01,E4,E6;
    char c = 'c' , d = 'd';
   // printf("%d",c);
    E1 = (3*i*j)+(2*100);
    E2 = (i*j)%(c+2*d)/(x*y);
    E3 = 5 * (i + j) > 'c';
    E4 = 2 * x + (y==0);
    E5 = (x>y) && (i>0) || (j <5);
    E6= 750 % 200;
    printf("value of expressions is %d\n %d\n %d\n %d\n %f\n %d\n %f\n: ",d,E1,E2,E3,E4,E5,E6);
   // scanf("%d",&b);
   return 0;

}
