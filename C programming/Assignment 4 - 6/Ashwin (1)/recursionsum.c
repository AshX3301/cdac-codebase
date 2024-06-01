#include<stdio.h>

int sum(int number) {
if (number>0)
return(number%10 + sum(number/10));
else 
return 0;

}

int main(){
    int number,x;
    scanf("%d",&number);
    x=sum(number);
    printf("%d",x);
return 0;
}