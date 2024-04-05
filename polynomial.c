#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int power;
    struct node *next;
};
struct node *p3 = NULL;
struct node *start = NULL;
void insert_end(int ele,int powr,struct node **start){
    struct node *temp,*curr;//initialize temp and curr
    temp = (struct node*)malloc(sizeof(struct node));//reserving memory for temp
    temp -> data = ele;//data assignment
    temp -> power = powr; 
    temp -> next = NULL;//setting temp next address to null since its the last element
    if(*start == NULL)//no element in the list
    *start = temp;//passing address of temp to start
    else{
    curr = *start;//initialize for traversal
while(curr->next!=NULL)//while loop for traversing 
    curr = curr->next;
curr ->next=temp;//assigning temps address to last element
}
}

void trave_for(struct node *start){
    struct node *curr;
    curr = start;
    while(curr!=NULL){
        printf("%dx^%d",curr->data,curr->power);

        curr = curr->next;
    }
}

void eval(struct node *p1,struct node *p2){
    while(p1!=NULL && p2!=NULL){
    if(p1->power == p2->power){
        insert_end(p1->data+p2->data,p1->power,&p3);
        p1 = p1->next;
        p2 = p2->next;
    }
    else if(p1->power > p2->power){
        insert_end(p1->data,p1->power,&p3);
        p1 = p1->next;
    }
    else{
        insert_end(p2->data,p2->power,&p3);
        p2 = p2->next;
    }
    }
    while(p1!=NULL){
        insert_end(p1->data,p1->power,&p3);
        p1 = p1->next;
    }
    while(p2!=NULL){
        insert_end(p2->data,p2->power,&p3);
        p2 = p2->next;
    }
}
int main(){
struct node *p1 = NULL;
struct node *p2 = NULL;
int ele,powr,coeff,ch;
do{
    printf("Choice\n 1.Polynomial 1\n 2.Polynomial 2\n 3.Traverse 1\n 4.Traverse 2\n 5.Evaluate\n 6.Traverse 3\n 7.exit");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("Enter coeff and power:");
            scanf("%d %d",&coeff,&powr);
            insert_end(coeff,powr,&p1);
            break;
        case 2:printf("Enter coeff and power:");
            scanf("%d %d",&coeff,&powr);
            insert_end(coeff,powr,&p2);
            break;
        case 3:trave_for(p1);
        break;
        case 4:trave_for(p2);
        break;
        case 5:eval(p1,p2);
        break;
        case 6:trave_for(p3);
        break;
        case 7:break;

    }
}while(ch!=7);
return 0;
}