#include<stdio.h>
#include<stdbool.h>
#include "../../../../../../usr/lib/llvm-10/lib/clang/10.0.0/include/stdbool.h"

bool recur(int i) {

    int x = i;
    if(x == 10)
    return true;
    else 
    {
        x++;
        recur(x);

    }
    return false;
printf("%d",x);
}



 int main() {
    int n=0;
    recur(n);
 }