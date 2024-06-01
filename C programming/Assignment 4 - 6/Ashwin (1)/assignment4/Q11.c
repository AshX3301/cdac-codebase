#include<stdio.h>
int copy(int arr[],int num){
    int arr1[50];
for(int i=0;i<num;i++){
    arr1[i] = *(arr + i);
    printf(" *%d ",arr1[i]);
}

}

int main(){
int arr[50],num;
printf("Enter the limit:");
scanf("%d",&num);
for(int i=0;i<num;i++) {
    scanf("%d",&arr[i]);
}
copy(arr,num);
}