#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void insert_beg(int);
void delete_spec(int);
void insert_end(int);
void trave_for();
void access(int);

void insert_beg(int ele){
    struct node *temp;//temp initilization
    temp = (struct node*)malloc(sizeof(struct node));//memory allocation
    temp -> data = ele; //setting the data to the input value
    temp -> next = start;//pointer address of next element from start
    start = temp;//passing address of temp to start
}

void delete_spec(int sele){
    struct node *temp,*curr;//initialize
    if(start!=NULL){
    if(start->data==sele){//if the first element is the data sele
        temp =  start;
        start = temp->next;//assign next element address to start
        free(temp);//free the deleted element memory
    }
    else{
        curr = start;
        while(curr->next!=NULL && curr->next->data!=sele)//traverse till the element is found
        curr = curr->next;
    if(curr->next!=NULL){//element found before the end of the list
        temp = curr->next;//curr address given to temp
        curr->next = temp->next;//temps address passed to curr
        free(temp);//memory freed
    }
    else
    printf("Element not found");
    }
    }
    else
    printf("List is empty");
}

void insert_end(int ele){
    struct node *temp,*curr;//initialize temp and curr
    temp = (struct node*)malloc(sizeof(struct node));//reserving memory for temp
    temp -> data = ele;//data assignment
    temp -> next = NULL;//setting temp next address to null since its the last element
    if(start == NULL)//no element in the list
    start = temp;//passing address of temp to start
    else{
    curr = start;//initialize for traversal
while(curr->next!=NULL)//while loop for traversing 
    curr = curr->next;
curr ->next=temp;//assigning temps address to last element
}
}

void trave_for(){
    struct node *curr;
    curr = start;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void access(int ele){
struct node *curr;
if(start!=NULL){
curr = start;
while(curr!=NULL && curr->data!=ele)
    curr = curr->next;
if(curr!=NULL){
    printf("%d accessed\n",curr->data);
    delete_spec(ele);
    insert_beg(ele);
}
else
printf("element not found\n");
}
else
printf("list is empty");
}

int main(){
    start = NULL;
    int ele,l,ch;
    printf("Enter the size of the list:");
    scanf("%d",&l);
    printf("Enter the list elements:");
    for(int i=0;i<l;i++){
    scanf("%d",&ele);
    insert_end(ele);
    }
    do{
        printf("1.Traverse\n 2.Access element\n 3.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:trave_for();
            break;
            case 2:printf("Enter the element to be accessed:");
            scanf("%d",&ele);
            access(ele);
            break;
            case 3:exit(1);
            break;
            default:
            printf("Invalid choice!");
            break;
        }
    }while(ch!=0);

return 0;
}