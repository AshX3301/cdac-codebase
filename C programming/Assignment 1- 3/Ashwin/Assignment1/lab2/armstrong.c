#include<stdio.h>
#include<math.h>

int main() {
    int n,a,num,temp,count=0,sum=0;
    scanf("%d",&n);
    num =n;
    while(num!=0){
        num=num/10;
        count++;
    }

    num=n;
    while(num!=0){
        a=n%10;
        sum=sum+pow(a,count);
     
        num=num/10;
    }
       printf("sum=%d\n",sum);
    if(n==sum){
        printf("armstrong");
    }
    else{
        printf("nah");
    }
    return 0;
}