#include<stdio.h>

int main() {
    int r,c,l,m,ind,arr[50][50],i,j,arr1[50][50],arr2[50][50];
    printf("Enter the row and coloumn of the matrix 1:");
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter the row and coloumn of the matrix 2:");
    scanf("%d %d",&l,&m);
    for(i=0;i<l;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    if (r==l && c==m){
        for(i=0;i<l;i++){
        for(j=0;j<m;j++){
            arr2[i][j] = arr[i][j]+arr1[i][j];
        }
    } 
    }
    for(i=0;i<r;i++){
        printf("\n");
        for(j=0;j<c;j++){
            printf(" %d ",arr2[i][j]);
        }
    }
    /*printf("Enter the index:\n");
    scanf("%d",&ind)
    for(i=0;i<r;i++){
        printf("\n");
        for(j=0;j<c;j++){
            printf(" %d ",arr[i][j]);
        }*/

        
return 0;
}