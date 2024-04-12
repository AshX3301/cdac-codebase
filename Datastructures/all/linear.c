#include<stdio.h>
#include<stdlib.h>
void search(int *arr,int ele,int size){
    int i,flag=0;
for(i=0;i<size;i++){
    if(arr[i]==ele){
        flag = 1;
        break;
}
}
if(flag == 1)
printf("element found at index:%d",i);
else
printf("element not found");
}

int main(){
int arr[50],i,size,ele;
printf("Size:");
scanf("%d",&size);
for(i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the element:");
scanf("%d",&ele);
search(arr,ele,size);
}