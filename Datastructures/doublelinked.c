#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;
void insert_beg(int);
void insert_end(int);
void insert_aft(int,int);
void insert_bef(int,int);
int dele_f();
int dele_l();
void dele_spec(int);
void trave_for();
void trave_back();
void reverse();
void freemem();
void insert();
void delete();
void insert_beg(int ele){
struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));
temp->data = ele;
temp->prev = NULL;
if(start == NULL){
    temp->next = NULL;
    start = temp;
}
else{
    temp->next = start;
    start = temp;
    temp->next->prev = temp;
}
}
void insert_end(int ele){
    struct node *temp,*curr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;
    if(start==NULL){
        temp->prev = NULL;
        start = temp;
    }
    else{
        curr = start;
        while(curr->next!=NULL)
            curr = curr->next;
        temp->prev = curr;
        curr->next = temp;
    }

}
void insert_aft(int ele,int sele){
    struct node *temp,*curr;
    if(start!=NULL){
        curr = start;
        while(curr!=NULL && curr->data!=sele)
            curr = curr->next;
        if(curr!=NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->prev = curr;
            temp->next = curr->next;
            if(curr->next!=NULL){
                curr->next->prev = temp;
            }
            curr->next = temp;
        }
        else
        printf("Element not found");
    }
    else
    printf("list is empty");
}
void insert_bef(int ele,int sele){
    struct node *temp,*curr;
    if(start!=NULL){
        curr = start;
        while(curr!=NULL && curr->data!=sele)
        curr = curr->next;
        if(curr!=NULL){
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data=ele;
            temp->next = curr;
            temp->prev = curr->prev;
            if(curr->prev == NULL)
            start = temp;
            else
            curr->prev->next = temp;
            curr->prev = temp;
        
        }
        else
        printf("Element not found");
    }
    else
    printf("The list is empty");
}
void trave_for(){
    struct node *curr;
    curr = start;
    while(curr!=NULL){
        printf("%p ",curr->prev);
        printf("%d ",curr->data);
        printf("%p ",curr->next);
        printf("\n");
        curr = curr->next;
    }
}
void insert(){
    int ch,ele,sele;
    while(ch!=6){
    printf("Enter your choice\n 1.Insert beg\n 2.Insert last\n 3.Insert before\n 4.Insert after\n 5.traverse\n 6.go back");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("\nEnter the element to enter:");
               scanf("%d",&ele);
        insert_beg(ele);
        break;
        case 2:printf("\nEnter the element to enter:");
               scanf("%d",&ele);
        insert_end(ele);
        break;
        case 3:printf("\nEnter the element to enter:");
               scanf("%d",&ele);
               printf("Enter the element before which element needs to be inserted:");
               scanf("%d",&sele);
        insert_bef(ele,sele);
        break;
        case 4:printf("\nEnter the element to enter:");
               scanf("%d",&ele);
               printf("Enter the element after which element needs to be inserted:");
               scanf("%d",&sele);
        insert_aft(ele,sele);
        break;
        case 5:trave_for();
        break;
        case 6:break;
        default:
        printf("Enter valid option");
    }
    }
}
int del_f(){
    int x = -999;
    struct node *temp;
    if(start!=NULL){
        temp = start;
        x = temp->data;
        if(temp->next!=NULL)
        temp->next->prev = NULL;
        start = temp->next;
        free(temp);
        temp = NULL;
    }
    else
    printf("list is empty");
return x;
}
int del_l(){
    int x = -999;
    struct node *curr;
    if(start!=NULL){
        curr = start;
        while(curr->next!=NULL)
        curr = curr->next;
        if(curr->prev == NULL){
            x = curr->data;
            start = curr->next;
            free(curr);
            curr = NULL;
        }
        else
        {
            x = curr->data;
            curr->prev->next = NULL;
            free(curr);
            curr = NULL;
        }
    }
    else
    printf("The list is empty");
return x;
}
void dele_spec(int sele){
    struct node *curr,*temp;
    if(start!=NULL){
        if(start->data == sele){
            temp = start;
            temp->next->prev = NULL;
            start = temp->next;
            free(temp);
            temp = NULL;
        }
        else{
        curr = start;
        while(curr!=NULL && curr->data!=sele)
        curr = curr->next;

        if(curr!=NULL){
           curr->prev->next = curr->next;
           if(curr->next!=NULL)
           curr->next->prev = curr->prev;
            free(curr);
            curr = NULL;
        }
        else
        printf("Element not found");
        }

    }
    else
    printf("The list is empty");
}
void delete(){
    int ch,sele;
    while(ch!=5){
    printf("Enter your choice\n 1.Delete beg\n 2.Delete last\n 3.Delete spec\n 4.traverse\n 5.go back");
    scanf("%d",&ch);
    switch(ch){
        case 1:del_f();
        break;
        case 2:del_l();
        break;
        case 3:printf("Enter the element to be deleted:");
               scanf("%d",&sele);
        dele_spec(sele);
        break;
        case 4:trave_for();
        break;
        case 5:break;
        default:
        printf("Enter valid option");
    }
    }
}
void freemem(){
    if(start!=NULL){
        while(start!=NULL){
        del_f();
        }
    }
    else
    printf("The list is empty");
}
void trave_back(){
    struct node *curr;
    curr = start;
    while(curr->next!=NULL)
    curr = curr->next;

    while(curr->prev!=NULL){
        printf("%d",curr->data);
        curr = curr->prev;
    }
    printf("%d",curr->data);
}
void reverse(){
    struct node *curr,*temp;
    if(start!=NULL){
        curr = start;
        while(curr->next!=NULL)
        curr = curr->next;

        start = curr;
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
        while(curr!=NULL && curr->next!=NULL){
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
        }
    }
    else
    printf("List is empty");
}

int main(){
start = NULL;
int ch;
do{
printf("Enter your choice\n 1.Insert\n 2.Delete\n 3.Reverse\n 4.Traverse forward\n 5.Traverse backward\n 6.exit\n");
scanf("%d",&ch);
switch(ch){
    case 1:
    insert();
    break;
    case 2:
    delete();
    break;
    case 3:
    reverse();
    break;
    case 4:trave_for();
    break;
    case 5:trave_back();
    break;
    case 6:break;
    default:
    printf("Not a valid option");
}
}while(ch!=6);
freemem();
return 0;
}