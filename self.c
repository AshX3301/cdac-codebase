#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
 void insert(int ele)
 {
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=start;
    start=temp;
 }
 void display()
 {
    struct node *curr;
    if(start!=NULL)
    {
        curr=start;
        while(curr->next!=NULL)
        {
            printf("%d\t",curr->data);
            curr=curr->next;
        }
        printf("%d\n",curr->data);
    }
    else 
    printf("Element not found");
 }
 void eval(int ele)
 {
    struct node *temp,*curr;
    if(start!=NULL)
    {
     curr=start;
     while(curr->next!=NULL && curr->next->data!=ele)
     curr=curr->next;
     if(curr->next!=NULL)
     {
        temp=curr->next;
      curr->next=temp->next;
      temp->next=start;
      start=temp;
     }
    } 
    else 
    printf("Empty list");
    if(start->data==ele)
    printf("self adjusted list");
 }
 int main()
 {
    start=NULL;
    int ch,ele;
    struct node *temp,*curr;
    printf("Enter the choice\n1.list\n2.eval\n3.display\n4.exit\n");
    scanf("%d",&ch);
    while(ch)
    {
        switch(ch)
        {
            case 1: 
            printf("Enter the elements");
            scanf("%d",&ele);
            insert(ele);
            break;
            case 2:
            printf("Enter the element to be adjusted");
            scanf("%d",&ele);
            eval(ele);
            break;
            case 3:display();
            break;
            case 4: exit(1);
        }
        printf("Enter the choice\n1.list\n2.eval\n3.display\n4.exit\n");
    scanf("%d",&ch);
    }
 }