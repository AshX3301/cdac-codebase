#include<stdio.h>
int check(int *arr){
int a,b;
a = arr[0];
b = arr[0];
for(int i=0;i<5;i++){
    if(arr[i]>a)
    a = arr[i];
    
    if(arr[i]<b)
    b = arr[i];
}
printf("Max element:%d\n",a);
printf("Min element:%d\n",b);
}


int reverse(int *arr){
    int a;
for(int i = 0;i<5;i++){
    int rem = 0;
    while(arr[i]!=0){
    a = arr[i]%10;
    rem = rem*10 + a;
    arr[i] = arr[i]/10;
    }
    arr[i] = rem;

}
for(int i = 0;i<5;i++){
    printf("%d ",arr[i]);
}

}


int main(){
    int arr[] = {12,25,32,47,59},sum = 0;
    for(int i=0;i<5;i++){
        printf("%d  ",arr[i]);
        sum += arr[i];
    }
    printf("\nsum = %d\n",sum);
    check(arr);
    reverse(arr);
}