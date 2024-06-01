#include<stdio.h>

int main() {

    int arr[100],num,n;
    printf("Enter the array limit:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to delete:");
    scanf("%d",&n);
    for(int j=0;j<num;j++){
        if(arr[j]==n){
            printf("deleting element at index %d\n",j);
            arr[j]=NULL;
            if(j!=num) {
            for(int i=j;(i>=j && i<num-1);i++){
            arr[i]=arr[i+1];
            }
            num --;
            }
        }
    }
printf("The new array is \n");
    for(int k=0;k<num;k++) {
        printf(" %d ",arr[k]);
    }
return 0;
}