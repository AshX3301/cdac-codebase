#include<stdio.h>

int main() {
    int n,sum=0;
    printf("Enter the number:");
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        if(n%i==0 && n!=i){
        sum +=i;
        }
        
    }
    //printf("%d",sum);
    if(sum==n){
        printf("The number is perfect");
    }
    else
    printf("The number is not perfect");
}