#include<stdio.h>

int main() {

    int arr[100],num,n;
    printf("Enter the array limit:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search:");
    scanf("%d",&n);
    for(int j=0;j<=num;j++){
        if(arr[j]==n){
            printf("number found at index %d",j);
            break;
    }
    }
return 0;
}
