#include<stdio.h>
int main(){
    int r,c;
    for (r=0;r<=6;r++) {
        if(r==0 || r==3 || r==6) {
        for(c=0;c<=4;c++){
            printf("*");
        }
        }
        else if((r>=1 || r<=3 && c==0) ) {
        printf("*");
        }
        else
        printf(" ");
        //for(c=0;c<=3;c++){
             // if((r==0 || c>=0 && c<4) && (r==0 && c>=0 || c<1) && (r==3 && c>=0 || c<4)) 
             //{  
            //printf("*");
              //}
              //else
              //{
                //printf("  ");
              //}
        }
        printf("\n");
    }

