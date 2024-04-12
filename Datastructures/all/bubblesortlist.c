#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start;

void insert_end(int);
void dele_spec(int);
void sort();
//void freemem();
void traverse();
void traverse(){
    struct node *curr;
    if(start!=NULL){
    curr = start;
    while(curr!=NULL){
        printf("%d",curr->data);
        curr = curr->next;
    }
    }
    else
    printf("The list is empty\n");
}
void insert_end(int ele){
    struct node *curr,*temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = ele;
        temp->next = NULL;
        if(start == NULL){
            start = temp;
        }
        else{
        curr = start;
        while(curr->next!=NULL)
        curr = curr->next;
        curr->next = temp;
        }
}
void dele_spec(int ele){
    struct node *temp,*curr;
    if(start!=NULL){
        temp = start;
        if(temp->data == ele){
            start = temp->next;
            free(temp);
            temp = NULL;
        }
        else
        curr = start;
        while(curr->next!=NULL && curr->next->data!=ele)
        curr = curr->next;

        if(curr->next!=NULL){
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
            temp = NULL;
        }
        else
        printf("Element not found\n");
    }
    else
    printf("The list is empty\n");
}

void sort(){
    struct node *temp,*curr,*curr1;
    if(start!=NULL){
        curr = start;
    while(curr->next!=NULL){
        curr1 =  curr;
        curr = curr->next;
        if(curr1->data>curr->data){
            
        }

    }  
    }
}
int main(){
    int ele,ch;
    do{
    printf("1.Insert\n 2.Delete\n 3.Sort\n 4.Display\n 5.Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("Enter the element:");
        scanf("%d",&ele);
        insert_end(ele);
        break;
        case 2:printf("Enter the element");
        scanf("%d",&ele);
        dele_spec(ele);
        break;
        case 3:sort();
        break;
        case 4:traverse();
        break;
        case 5:break;
    }

}while(ch!=5);
}