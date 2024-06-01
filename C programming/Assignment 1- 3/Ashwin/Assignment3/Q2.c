#include<stdio.h>

int main() {
    int fact=1, number;
    scanf("%d",&number);

    for(int i=1;i<=number;i++) {
        fact *= i;

    }
    printf(" %d ",fact);
}