#include<stdio.h>

int main() {
    int r,c,ind,ind1,arr[50][50],i,j;
    printf("Enter the row and coloumn of the matrix:");
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("Enter the index:\n");
    scanf("%d %d",&ind,&ind1);
            printf(" %d ",arr[ind][ind1]);
        
     
return 0;
}