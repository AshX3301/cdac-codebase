#include<stdio.h>
#include<math.h>
int fact(int n){
if(n==0)
return 1;
else
return n*fact(n-1);
}
int power(int n,int x){
    if(x==0)
    return 1;
    else 
    return n*power(n,x-1);
}
//int derv(){
//}
int taylor(int n,int x){
if(x==0)
return 1;
else 
return power(n,x)/fact(x)+taylor(n,x-1);
}
int main(){
int a,x,result; //Assuming the function is e^x
printf("Enter the value of a and number of terms for the taylor series:");
scanf("%d %d",&a,&x);
result = taylor(a,x);
printf("%d",result);
//printf("%f",exp(a));
}