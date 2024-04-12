





























     #include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void funpf(struct node *);
void insert_beg(int ele){
    struct node *temp;//temp initilization
    temp = (struct node*)malloc(sizeof(struct node));//memory allocation
    temp -> data = ele; //setting the data to the input value
    temp -> next = start;//pointer address of next element from start
    start = temp;//passing address of temp to start
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
void trave_back(){
if(start!=NULL)
funpf(start);
else
printf("The list empty");
}
void funpf(struct node *curr){
    if(curr!=NULL){
        funpf(curr->next);
        printf("%d",curr->data);
    }
}
int main(){
    start = NULL;
    int ch,ele;
    do{
        printf("Stack Op\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element:");
            scanf("%d",&ele);
            insert_beg(ele);
            
            break;

            case 2:printf("%d popped",delete_f());
            break;

            case 3:trave_back();
            break;

            case 4:break;
            default:
            printf("Invalid choice");
        }
    }while(ch!=4);
return 0;
}