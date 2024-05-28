#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>

struct student{
    int rollno;
    char name[50];
    float marks;
};
struct student st[5];
void rea(){
int fr,i=0;
fr = open("studentsys.dat",O_RDONLY);
if(fr == -1){
    perror("error");
    exit(1);
}
    while (read(fr, &st[i], sizeof(struct student)) > 0) {
        printf("%d\n%s\n%.2f\n", st[i].rollno, st[i].name, st[i].marks);
        i++;
    }

    close(fr);
}

int main(){
int fp;
fp = open("studentsys.dat", O_CREAT|S_IRWXU|O_WRONLY);
if(fp == -1){
    perror("error");
    exit(1);
}
for(int i = 0;i<5;i++){
    scanf("%d %s %f",&st[i].rollno,st[i].name,&st[i].marks);
}
for(int i=0;i<5;i++){
    if(dprintf(fp,"%d %s %f",st[i].rollno,st[i].name,st[i].marks)<0){
        perror("Error writing file");
        break;
    }
    //dprintf(fp,"%d %s %f",st[i].rollno,st[i].name,st[i].marks);
}
close(fp);
rea(st);
}