#include<stdio.h>
#include<stdlib.h>
/*void sum(int r,int c,int *(*(arr+r)+c)){
    int i,j,sumx = 1;
    for(j = 0;j<c;j++){
        for(i = j+1;i<r;i++){
            sumx = sumx + arr[i][j];
            printf("i = %d j = %d\n",i,j);
            printf("%d",arr[i][j]);
        }
    }
    
    //return sumx;
}
*/
int main(){
    int arr[10][10];
    int i,j,r,c,sumx=0;
    printf("Enter the size of the square matrix:");
    scanf("%d %d",&r,&c);
    printf("Enter the elements:");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
        for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",arr[i][j]);
            printf("%p\t",&arr[i][j]);
        }
        printf("\n");
    }
    for(j = 0;j<c;j++){
        for(i = j+1;i<r;i++){
            sumx = sumx + arr[i][j];
            printf("i = %d j = %d\n",i,j);
            printf("%d",arr[i][j]);
        }
    }
    printf("%d",sumx);

  // sum(r,c,*(arr+r)+c);
return 0;
}