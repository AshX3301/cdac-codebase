#include<stdio.h>
#include<stdlib.h>
union employee{
    int id;
    char name[50];
    float salary;
};
int read(struct employee e[]){
    FILE *fp;
    fp =fopen("data.txt","r");
}
int main(){
union employee e[3];
FILE *fp;
fp = fopen("data.txt","w");
if(fp==NULL){
    printf("File not found");
    exit(1);
}
else
printf("file found\n");

 for(int i = 0;i<3;i++){
    scanf("%d %s %f" ,&e[i].id,e[i].name,&e[i].salary);
 }   
 for(int i= 0;i<3;i++){
     fprintf(fp,"%d\n %s\n %f\n" ,e[i].id,e[i].name,e[i].salary);
 
 }
 printf("File written succesfully");
 fclose(fp);
 
}