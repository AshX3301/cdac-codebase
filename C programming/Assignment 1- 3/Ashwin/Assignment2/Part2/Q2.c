#include<stdio.h>
int main(){
    char input;
    printf("Enter something:");
    scanf("%c",&input);
    if(input>='a' && input<='z' || input>='A' && input<='Z'){
        printf("The input is an alphabet\n");
        printf("The ascii value of the input is %d",input);
    }
    else if(input>='0' && input<='9'){
    printf("The input is digit\n");
    printf("The ascii value of the input is %d",input);

}
return 0;
}
   