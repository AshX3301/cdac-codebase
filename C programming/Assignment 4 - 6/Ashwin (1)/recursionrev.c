#include<stdio.h>

int isrev(int num) {
    if(num!=0)
    {
        return(num%10+isrev(num/10));
        
    }

}



int main() {
    int number,x;
    scanf("%d",&number);
    x=isrev(number);
    printf("%d",x);
}