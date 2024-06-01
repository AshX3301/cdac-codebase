#include<stdio.h>
int incr(int *arr,int x){

for(int i=0;i<x;i++){
    arr[i] += 1;
}
return *arr;
}
int main(){
    int arr[100],lmt;
    printf("Enter the limit:");
    scanf("%d",&lmt);
    printf("\nEnter the elements of the array:");
    for(int i=0;i<lmt;i++){
        scanf("%d",&arr[i]);
    }
    incr(arr,lmt);
    for(int i=0;i<lmt;i++){
        printf("%d ",arr[i]);
    }

}