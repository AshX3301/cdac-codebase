#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void insert_end(int);
int delete_f();
void trave_for();
void freemem();

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
int delete_f(){
    int x = -999;//arbritary element
    struct node *temp;//initialize
    if(start!=NULL){//checking if elements are present
        temp = start;//start address passed to temp
        x = temp->data;//value return
        start = temp->next;//temp contains address of next element which is passed to start
        free(temp);//free temp
        temp = NULL;//pointer NULL

    }
    else
    printf("List is empty");
return x;
}
void trave_for(){
    struct node *curr;
    if(start!=NULL){
    curr = start;
    while(curr!=NULL){
        printf("%d",curr->data);
        curr = curr->next;
    }
    }
    else
    printf("The list is empty");
}
void freemem(){
    if(start!=NULL){
        while(start!=NULL){
        delete_f();
        }
    }
    else
    printf("The list is empty");
    trave_for();
}
int main(){
    start = NULL;
    int ch,ele;
    do{
        printf("Queue Op\n 1.Enque\n 2.Deque\n 3.Display\n 4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element:");
            scanf("%d",&ele);
            insert_end(ele);
            
            break;

            case 2:printf("%d Dequed",delete_f());
            break;

            case 3:trave_for();
            break;

            case 4:break;
            default:
            printf("Invalid choice");
        }
    }while(ch!=4);
freemem();
return 0;
}