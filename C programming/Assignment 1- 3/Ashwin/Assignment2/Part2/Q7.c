#include<stdio.h>

int main() {
    int n,sum=0,x;
    printf("Enter the number:" );
    scanf("%d",&n);

    for(int i=0;n!=0;i++) {
        x = n%10;
        sum += x;
        n = n/10;
        }
       
  
    printf("%d",sum);
    return 0;
}