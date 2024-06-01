#include<stdio.h>

void printArray(int arr[]) {
    printf("inside function: %d",sizeof(arr));
    printf("array elements:");
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }

}


int main() {
    int arr[4] ={'a','b','c','d'};
    printf("Outside the function: %ld ",sizeof(arr));
    printArray(arr);
    return 0;
}

/*int main() {
    int Arr[] = {1,2,3,4,5,6};
    int length = *(&Arr+1)-Arr;
    //printf("%d",&Arr);

    printf("%d",length);
    return 0;
}*/