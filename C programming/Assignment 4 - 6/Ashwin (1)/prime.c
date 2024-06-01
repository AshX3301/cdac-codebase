#include<stdio.h>

int main() {
int range,i,j,count,a=0,b=1,c=0;
scanf("%d",&range);

for(i=0;i<=range;i++){
    //printf("*");
    a=b;
    b=c;
    c=a+b;
   // printf("%d",b);
    count = 0;
    for(j=1;j<=b;j++) {
        if(b%j==0)
        count++;
    }
if(count==2)
printf("%d ",b);

}
return 0;
}