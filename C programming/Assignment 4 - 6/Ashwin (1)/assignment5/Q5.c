#include<stdio.h>
long double ncr(long double n){
if(n==0){
return 1;
}
else 
return n*ncr(n-1); 


}

int main(){
    long double n,r,x;
    printf("Enter n and r values:");
    scanf("%Lf %Lf",&n,&r);
    x = ncr(n)/(ncr(r)*ncr(n-r));
    printf("%Lf",x);

}