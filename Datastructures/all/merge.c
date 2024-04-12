#include<stdio.h>
#include<stdlib.h>
void mergex(int *arr,int low,int n1,int mid){
    int i,j,k;
    int arr1[mid-low+1],arr2[n1-mid];
    for(i = 0; i < mid-low+1; i++)
        arr1[i] = arr[low + i];
    for(j = 0;j<n1-mid; j++)
        arr2[j] = arr[mid+1+j];
    i=0;
    j=0;
    k = low;
    while(i!=mid-low+1 && j!=n1-mid){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;k++;
        }
        else{
            arr[k] = arr2[j];
            j++;k++;
        }
    }
    while(i<mid-low+1){
        arr[k] = arr1[i];
        k++;i++;
    }
    while(j<n1-mid){
        arr[k] = arr2[j];
        j++;k++;
    }
}


void merge(int *arr,int low,int n1){
    int i=0,j=0,mid;
    if(low!=n1){
    mid  = (low+n1)/2;
    merge(arr,low,mid);
    merge(arr,mid+1,n1);
    mergex(arr,low,n1,mid);
    }    
}

int main(){
    int i,n1,arr[50];
    printf("Enter the size of array:");
    scanf("%d",&n1);
    printf("array:");
    for(i=0;i<n1;i++){
        scanf("%d",&arr[i]);
    }
    merge(arr,0,n1-1);
    printf("Sorted array:");
    for(i=0;i<n1;i++){
        printf("%d",arr[i]);
    }

}