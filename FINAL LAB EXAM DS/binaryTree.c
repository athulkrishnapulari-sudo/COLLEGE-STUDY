#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(){
    int data;
    printf("Enter the Data (-1 if no Node): ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    printf("Enter the Data of left child of %d : \n",newnode->data);
    newnode->left=create();
    printf("Enter the Data of right child of %d : \n",newnode->data);
    newnode->right=create();
    return newnode;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node *root;
    root=create();
    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n");
}