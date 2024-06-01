#include<stdio.h>
int main() {
int num=0,i,bin,inum;
printf("Enter the integer:");
scanf("%d",&num);
int arr[num];
inum = num;
for(i=0;i<=num;i++) {
    arr[i] = inum%2;
    inum /=2;
    //printf("%d",bin);
}
for(int j=0;j<=num;j++){
    printf("%d",arr[num-j]);
}
return 0;
}