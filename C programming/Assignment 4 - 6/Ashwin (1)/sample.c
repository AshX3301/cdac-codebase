#include<stdio.h>
int rev = 0;
int isreverse(int ) ;
int main() {
int number,x;
scanf("%d",&number);
x= isreverse(number);
//printf("%d",x);
return 0;
}
int isreverse(int num) {
if(num!=0) {
    int a = num%10;
    rev =rev*10+a;
    num /= 10;
    isreverse(num);
}
printf("\n%d",rev);

return rev;
}