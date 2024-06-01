#include<stdio.h>
int main(){
    char value;
            printf("enter the value: ");
            scanf("%c",&value);
    
        if(value>='a' && value <='z' || value>='A' && value <='z')
            printf("the value enter is charachter %c",value);
        else if (value >= '0' || value <= '9')  
         printf("the value enter is digit %c",value);  
    return 0;
}