#include<stdio.h>

int main() {

    int arr[100],num,sum=0;
    printf("Enter the array limit:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<num;j++){
        sum +=arr[j];
        }
        printf("Sum is:%d",sum);
    
return 0;
}