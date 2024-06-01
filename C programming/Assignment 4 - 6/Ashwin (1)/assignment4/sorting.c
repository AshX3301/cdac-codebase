#include<stdio.h>
int sort(int *arr,int n){
    int a = arr[0];
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
    if(arr[i]>arr[j]){
        a = arr[i];
        arr[i]=arr[j];
        arr[j]=a;
    }
    }
}
}

int main() {
    int arr[50],lim;
    printf("Enter the limit:");
    scanf("%d",&lim);
    for(int i=0;i<lim;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,lim);
    printf("\n");
    for(int i=0;i<lim;i++){
    printf(" %d ",arr[i]);
    }
}