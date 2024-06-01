#include<stdio.h>

int arrch(int *arr,int n) {

        int a,b;
        a=arr[0];
        b=arr[0];
        for(int j=0;j<n;j++){
        if(arr[j]<a)
        a = arr[j];
        
        if(arr[j]>b)
        b= arr[j];
    }

    printf("%d %d",a,b);
return 1;
}
int main() {

    int arr[50],num;
    printf("Enter the array limit:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    arrch(arr,num);

return 0;
}