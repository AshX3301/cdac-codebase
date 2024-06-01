#include<stdio.h>

int main() {
    int number,sum=0;
    scanf("%d",&number);
    while(number!=0){
        if(number%2 !=0)
        sum += number;
        number--;
    }

printf("%d",sum);

}