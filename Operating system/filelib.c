#include<stdio.h>
#include<syscall.h>
struct student{
    int rollno;
    char name[50];
    float marks;
};
struct student st[5];

void read(){

}
int main(){
FILE *fp;
fp = fopen("student.dat","w");
for(int i = 0;i<5;i++){
    scanf("%d %s %f",&st[i].rollno,st[i].name,&st[i].marks);
}
for(int i=0;i<5;i++){
    if(!fprintf(fp,"%d\n %s\n %f\n",st[i].rollno,st[i].name,st[i].marks))
    printf("Error writing file");
}
fclose(fp);
}