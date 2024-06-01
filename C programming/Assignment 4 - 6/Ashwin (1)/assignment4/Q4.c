#include<stdio.h>

int reverse(int *arr,int n) {
        int temp;
        for(int j=0;j<n/2;j++){ 
        temp = arr[j];
        arr[j] = arr[n-j-1];
        arr[n-j-1] = temp;
    }
}

int main() {

    int arr[100],num;
    printf("Enter the array limit:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    reverse(arr,num);
    for(int j=0;j<num;j++){ 
        printf("%d",arr[j]);
    }
return 0;
}