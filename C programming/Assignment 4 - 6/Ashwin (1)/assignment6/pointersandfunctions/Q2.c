#include<stdio.h>
int swap(int *num,int *temp){
int ptr;
ptr = *num;
*num = *temp;
*temp = ptr;
}
int main(){
int num,temp;
printf("Enter the numbers:");
scanf("%d %d",&num,&temp);
swap(&num,&temp);
printf("The numbers after swapping: %d %d ",num,temp);
}