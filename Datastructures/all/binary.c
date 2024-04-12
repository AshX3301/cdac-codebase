#include<stdio.h>
#include<stdlib.h>
int bsearc(int *arr,int ele,int low,int high){
int mid;
mid = (low+high)/2;
    if(low <= high){
if(arr[mid] == ele)
return mid;

if(ele<arr[mid]){
    bsearc(arr,ele,low,mid-1);
}
else 
    bsearc(arr,ele,mid+1,high);
}
else
return -1;
}
int main(){
int x,arr[50],i,size,ele;
printf("Size:");
scanf("%d",&size);
for(i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the element:");
scanf("%d",&ele);
x = bsearc(arr,ele,0,size-1);
if(x!=-1)
printf("Element found at index %d",x);
else
printf("Element not found");
return 0;
}
