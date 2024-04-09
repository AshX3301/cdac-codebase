#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *bst;

int NL(struct node *);
int NNL(struct node *);
int height(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);
int find_max(struct node *);
int find_min(struct node *);
void insert(int ele);
int max(int,int);
int max(int x,int y){
    if(x>y)
    return x;
    else
    return y;
}

int NL(struct node *curr){
    if(curr==NULL)
    return 0;
    if(curr->left == NULL && curr->right == NULL)
        return 1;
    else
    return (NL(curr->left) + NL(curr->right));
}

int NNL(struct node *curr){
    if(curr == NULL)
    return 0;
    if(curr->left == NULL && curr->right == NULL)
    return 0;
    else
    return(NNL(curr->left)+NNL(curr->right)+1);//1 for the root node
}

int height(struct node *curr){
    if(curr == NULL)
    return -1;
    if(curr->left == NULL && curr->right == NULL)
    return 0;
    else
    return(max(height(curr->left),height(curr->right))+1);
}

void inorder(struct node *curr){
    if(curr!=NULL){
        inorder(curr->left);
        printf("%d",curr->data);
        inorder(curr->right);
    }
}

void preorder(struct node *curr){
    if(curr!=NULL){
        printf("%d",curr->data);
        preorder(curr->left);
        preorder(curr->right);
    }
}

void postorder(struct node *curr){
    if(curr!=NULL){
        postorder(curr->left);
        postorder(curr->right);
        printf("%d",curr->data);
    }
}

int find_max(struct node *curr){
while(curr->right!=NULL)
curr = curr->right;

return curr->data;
}

int find_min(struct node *curr){
    while(curr->left!=NULL)
    curr = curr->left;

    return curr->data;
}

void insert(int ele){
    struct node *temp,*curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->right = NULL;
    temp->left = NULL;
    if(bst == NULL){
        bst = temp;
    }
    else{
       while(1){
        if(ele<curr->data){
            if(curr->left!=NULL)
            curr = curr->left;
            else
            {
                curr->left = temp;
                break;
            }
        }
        else if(curr->right!=NULL)
        curr = curr->right;
        else{
            curr->right = temp;
            break;
        }
       } 
    }
}

