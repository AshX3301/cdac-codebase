#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int *arr,int size){
    for(int i=0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[i])
            swap(arr+i,arr+j);
        }
    }
}
int main(){
    int arr[50],i,size;
    printf("Enter the size:");
    scanf("%d",&size);
    printf("Enter the elements:");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    bubble(arr,size);
    printf("Sorted array:");
    for(i = 0;i<size;i++)
    printf("%d ",arr[i]);
return 0;
}