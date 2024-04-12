#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *start;
 int insert_end()
 {
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    curr=start;
    while(curr->next!=NULL)
     curr=curr->next;
     temp->prev=curr;
     temp->next=curr->next;
     curr->next=temp;
 }
 void display()
 {
    struct node *curr;
    if(start!=NULL)
    {
    curr=curr->next;
    while(curr->next!=NULL)
    {   
        printf("%p\t",curr->prev);
        printf("%d\t"curr->data);
        printf("%p\n",curr->next);
        curr=curr->next;
    }
      printf("%p\t",curr->prev);
        printf("%d\t"curr->data);
        printf("%p\n",curr->next);
    }
    else
    printf("List not present");
 }
 int main()
 {
    start=NULL;
    int ch,ele,sel;
    printf("enter the choice\n1.insert\n2.delete first\n3.detele last\n4.delete specific\n5.display\n6.exit\n");
    scanf("%d",&ch);
    while(ch)
    {
        switch(ch)
        {
            case 1:insert_end();
            break;
            case 5: display();
            break;
            case 6:exit(1);
            break;
        }
    }
 }