#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int low,int n1){
    int i=0,j=0,k=0;
 
}

int main(){
    int i,n1;
    printf("Enter the size of array1:");
    scanf("%d",&n1);
    int arr[n1];
    printf("First array:");
    for(i=0;i<n1;i++){
        scanf("%d",&arr[i]);
    }
    merge(arr,0,n1);
    printf("Sorted array:");
    for(i=0;i<n1;i++){
        printf("%d",arr[i]);
    }

}