#include<stdio.h>
int natural(int x){
if(x!=0){
    return x+natural(x-1);
}
else
return 0;
}

int main(){
    int a;
    printf("Enter the limit:");
    scanf("%d",&a);
    printf("%d",natural(a));
}