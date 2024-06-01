#include<stdio.h>
int main() {
int num,i,bin;
printf("Enter the integer:");
scanf("%d",&num);

for(i=0;i<=num;i++) {
    bin = num%2;
    num = num /2;
    //bin = bin * 10;
    printf("%d ",bin);
    }
return 0;
}