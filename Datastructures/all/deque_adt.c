#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;
void insert_end(int ele){
    struct node *temp,*curr;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = start;
    if(start==NULL){
        temp->prev = NULL;
        start = temp;
        temp->next = start;
    }
    else{
        curr = start;
        while(curr->next!=start)
            curr = curr->next;
        temp->prev = curr;
        curr->next = temp;
    }

}
int del_l(){
    int x = -999;
    struct node *curr;
    if(start!=NULL){
        curr = start;
        while(curr->next!=start)
        curr = curr->next;
            if(curr->prev==NULL && curr->next==start){
            x = curr->data;
            start = NULL;
            free(curr);
            curr = NULL;
        }
        else
        {
            x = curr->data;
            curr->prev->next = start;
            free(curr);
            curr = NULL;
        }
    }
    else
    printf("The list is empty");
return x;
}
/*int del_f(){
    int x = -999;
    struct node *temp,*curr;
    if(start!=NULL){
        temp = start;
        x = temp->data;
        if(temp->next!=start)
        temp->next->prev = NULL;
        curr = start;
        while(curr->next!=start)
        curr = curr->next;
        start = temp->next;
        if(curr->prev==NULL && curr->next==start)
        start = NULL;
        else
        curr->next = start;
        free(temp);
        temp = NULL;
    }
    else
    printf("list is empty");
return x;
}
*/
void trave_for(){
    struct node *curr;
    if(start!=NULL){
    curr = start;
    while(curr->next!=start){
        printf("%p ",curr->prev);
        printf("%d ",curr->data);
        printf("%p ",curr->next);
        printf("\n");
        curr = curr->next;
    }
    printf("%p ",curr->prev);
    printf("%d ",curr->data);
    printf("%p ",curr->next);
    }
    else
    printf("List is empty\n");
}
int main(){
    start = NULL;
    int ch,ele;
    do{
        printf("Deque ADT\n 1.Enque\n 2.Deque\n 3.Display\n 4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element:");
            scanf("%d",&ele);
            insert_end(ele);
            break;

            case 2:
            del_l();
            break;

            case 3:trave_for();
            break;

            case 4:break;
            default:
            printf("Not a valid choice:");
        }

    }while(ch!=4);
}

