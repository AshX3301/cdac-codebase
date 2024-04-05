#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *l3=NULL;

void insert_end(int,struct node **);
void trave_for(struct node *);
void eval(struct node *,struct node *);

void insert_end(int ele,struct node **start){
    struct node *temp,*curr;//initialize temp and curr
    temp = (struct node*)malloc(sizeof(struct node));//reserving memory for temp
    temp -> data = ele;//data assignment
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
        printf("%d",curr->data);
        curr = curr->next;
    }
}

void eval(struct node *l1,struct node *l2){
    
    while(l1!=NULL && l2!=NULL){
    if(l1->data<l2->data){
        insert_end(l1->data,&l3);
        l1=l1->next;
    }
    else{
        insert_end(l2->data,&l3);
        l2 = l2->next;
    }
    }
    while(l1!=NULL){
        insert_end(l1->data,&l3);
        l1 = l1->next;
    }
    while(l2!=NULL){
        insert_end(l2->data,&l3);
        l2 = l2->next;
    }
}

int main(){
struct node *l1=NULL;
struct node *l2=NULL;
    
    int ch,ele;
    do{
        printf("Enter choice\n 1.List 1\n 2.List 2\n 3.Merge and sort\n 4.Display list 1\n 5.Display list 2\n 6.Display list 3\n 7.exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element:");
            scanf("%d",&ele);
            insert_end(ele,&l1);
            break;
            case 2:
            printf("Enter the element:");
            scanf("%d",&ele);
            insert_end(ele,&l2);
            break;
            case 3:eval(l1,l2);
            break;
            case 4:trave_for(l1);
            break;
            case 5:trave_for(l2);
            break;
            case 6:trave_for(l3);
            break;
            case 7:break;
            default:
            printf("Invalid option");
        }
    }while(ch!=7);
return 0;
}