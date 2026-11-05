#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left , *right;
};

struct node* createNode(int value){
    struct node *NewNode;
    NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->value=value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
}


void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->value);
    }
}

int main(){
    struct node *root;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

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