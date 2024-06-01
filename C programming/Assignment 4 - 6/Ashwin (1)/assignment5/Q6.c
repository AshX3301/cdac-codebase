#include<stdio.h>
int tofh(int n,char s,char h,char d){
    if(n==1){
    printf("Disk %d from %c ---> %c\n",n,s,d);
    return;
    }
    else
    tofh(n-1,s,d,h);
    printf("Disk %d from %c --> %c\n",n,s,d);
    tofh(n-1,h,s,d);
}
int main(){
    char s = 'A',h = 'B',d = 'C';
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    tofh(n,s,h,d);
}