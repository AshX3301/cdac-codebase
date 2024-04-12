#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quick(int *arr,int low,int high){
    if(low<high){
int piv,i,j;
i = low;
j = high;
piv = arr[low];
while(i<j){
while(piv>=arr[i] && i<high)
    i++;
while(arr[j]>piv)
    j--;

if(i<j){
    swap(arr+i,arr+j);
    i++;
    j--;
}
else
i++;
}
swap(arr+low,arr+j);
quick(arr,low,j-1);
quick(arr,j+1,high);
    }
}
int main(){
int arr[50],i,j,n,low,high;
printf("Enter the size of array:");
scanf("%d",&n);
printf("Enter the elements of the array:");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
low=0;
high=n-1;
quick(arr,low,high);
for(i=0;i<n;i++){
    printf("%d",arr[i]);
}
}