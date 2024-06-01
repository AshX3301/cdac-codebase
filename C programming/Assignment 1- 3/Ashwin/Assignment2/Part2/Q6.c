#include<stdio.h>

int main() {
    int n,sum=0,x;
    printf("Enter the range:");
    scanf("%d %d",&n,&x);

    for(int i=1;i<=x;i++) {
        if(i>=n && i<=x)
        sum +=i;
        else 
        continue;
    }
    printf("%d\n",sum);
}