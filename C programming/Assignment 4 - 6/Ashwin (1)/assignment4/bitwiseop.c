#include<stdio.h>
#include<stdlib.h>


int main(){
    int8_t a,b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("a&b:%d\n",a&b);
    printf("a|b:%d\n",a|b);
    printf("a^b:%d\n",a^b);
    printf("~a:%d\n",~a);
    printf("a<<b:%d\n",a<<b);
    printf("a>>b:%d\n",a>>b);
return 0;


}