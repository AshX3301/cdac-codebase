#include<stdio.h>
struct student{ 
    int roll;
    char name[50];
    float marks;
};

void read(struct student s[]){
FILE *fp;
int avg =0;
fp =  fopen("students.dat","r");
for(int i = 0;fscanf(fp,"%d %s %f" ,&s[i].roll,s[i].name,&s[i].marks)!=EOF;i++){
    printf("%d\n %s\n %f\n" ,s[i].roll,s[i].name,s[i].marks);
    avg += s[i].marks;
}
printf("The average marks:%d",avg/5);
fclose(fp);
}

int main(){
FILE *fp;
fp = fopen("students.dat","w");

 struct student s[5];
 for(int i = 0;i<5;i++){
    scanf("%d %s %f" ,&s[i].roll,s[i].name,&s[i].marks);
 }   
 for(int i= 0;i<5;i++){
     fprintf(fp,"%d\n %s\n %f\n" ,s[i].roll,s[i].name,s[i].marks);
 
 }
 printf("File written succesfully");
 fclose(fp);
 read(s);
}