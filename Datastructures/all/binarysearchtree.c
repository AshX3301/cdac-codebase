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
struct node * delete(int ele,struct node *);
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
        printf("%d ",curr->data);
        inorder(curr->right);
    }
}

void preorder(struct node *curr){
    if(curr!=NULL){
        printf("%d ",curr->data);
        preorder(curr->left);
        preorder(curr->right);
    }
}

void postorder(struct node *curr){
    if(curr!=NULL){
        postorder(curr->left);
        postorder(curr->right);
        printf("%d ",curr->data);
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
        curr = bst;
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
        else if(curr->right!=NULL){
        curr = curr->right;
        }
        else{
            curr->right = temp;
            break;
        }
       } 
    }
}

struct node * delete(int ele,struct node *curr){
    struct node *temp;
    if(curr!=NULL){
    if(ele<curr->data)
    curr->left = delete(ele,curr->left);
    else if(ele>curr->data)
    curr->right = delete(ele,curr->right);
    else{
    if(curr->left!=NULL && curr->right!=NULL)
    curr->data = find_max(curr->left);
    else{
        temp = curr;
        if(curr->left == NULL)
        curr = curr->right;
        else
        curr = curr->left;
    free(temp);
    temp = NULL;

    }
    } 
    }
return curr;
}

int main(){
    bst = NULL;
    int ch,ele;
    do{
    printf("Binary search tree\n 1.Insert\n 2.Leaf nodes\n 3.Non Leaf nodes\n 4.Delete element\n 5.Inorder\n 6.Post order\n 7.Pre order\n 8.Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("Enter the element:");
               scanf("%d",&ele);
               insert(ele);
               break;
        case 2:printf("%d",NL(bst));
               break;
        case 3:printf("%d",NNL(bst));
               break;
        case 4:printf("Enter the element:");
               scanf("%d",&ele);
               delete(ele,bst);
               break;
        case 5:inorder(bst);
               break;
        case 6:postorder(bst);
               break;
        case 7:preorder(bst);
               break;
        case 8:break;
    }
    }while(ch!=8);
}
