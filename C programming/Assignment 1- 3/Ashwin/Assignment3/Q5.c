#include<stdio.h>
int main() {
int num=0,rnum=0;
scanf("%d",&num);
int inum = num;
while(inum!=0) {
int r = inum%10;
rnum = rnum*10+r;
inum /=10;
}
if (num == rnum) {
printf("palindrome"); }
else {
printf("not a palindrome");
}
printf("%d , %d",num,rnum);
return 0;
}
