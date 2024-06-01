#include<stdio.h>
int main() {
    int inp,a,b;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);

    printf("Select operation:\n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division:\n");
    scanf("%d",&inp);

    switch (inp)
    {
    case 1:
        printf("%d + %d = %d",a,b,a+b);
        break;
    case 2:
        printf("%d - %d = %d",a,b,a-b);
        break;    
    case 3:
        printf("%d * %d = %d",a,b,a*b);
        break;
    case 4:
        printf("%d / %d = %f",a,b,(float)a/b);
        break;
    default:
        printf("Option Invalid");
        break;
    }
}