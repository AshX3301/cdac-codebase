#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int *arr,int n,int root){
int lc,rc,large;
lc=2*root+1;
rc = 2*root+2;
large = root;
if(lc<n && arr[lc]>arr[large])
large = lc;
if(rc<n && arr[rc]>arr[large])
large = rc;
if(large!=root){
    swap(arr+large,arr+root);
    heapify(arr,n,large);
}
for(int i=0;i<n;i++){
    printf("stage %d:%d\n ",i,arr[i]);
}
}

void hsort(int *arr,int n){
for(int i=n/2-1;i>=0;i--)
heapify(arr,n,i);
for(int i = n-1;i>0;i--){
swap(arr,arr+i);
heapify(arr,i,0);//important
}
}

int main(){
int arr[50],size;
printf("Enter the size:");
scanf("%d",&size);
printf("Elements:");
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
hsort(arr,size);
printf("sorter array:");
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}
return 0;
}
