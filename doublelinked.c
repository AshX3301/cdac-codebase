#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}
struct node *start;
void insert_beg(int);
void insert_end(int);
void insert_aft(int,int);
void insert_bef(int,int);
int dele_aft();
int dele_bef();
void dele_spec(int);
void trav_for();
void trav_back();
void reverse();

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
            temp->prev = curr;
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


int main(){

}