#include<stdio.h>
#include<stdlib.h>
void insert(int *arr,int size){
    int i,j,k;
    for(i=1;i<size;i++){
        k = arr[i];
        for(j=i-1;j>=0 && k<arr[j];j--)
            arr[j+1] = arr[j];
        arr[j+1] = k;
    }
}
int main(){
    int arr[50],i,size;
    printf("size:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    insert(arr,size);

    for(i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}