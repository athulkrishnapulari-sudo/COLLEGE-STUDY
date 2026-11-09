#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left,*right;
};

struct node* create(int data){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int value){
    if(root == NULL) {
        return create(value);
    }
    if(value<root->data){
        root->left = insert(root->left,value);
    }
    else if(value>root->data){
        root->right = insert(root->right,value);
    }
    else{
        printf("Duplicate Values not allowed\n");
    }
    return root;
}

int search(struct node *root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
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

struct node* finMin(struct node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct node* delete(struct node* root,int key){
    if(root==NULL){
        printf("Element Not Found\n");
        return NULL;
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp = root->left;
            free(temp);
            return temp;
        }
        else{
            struct node *temp=finMin(root->right);
            root->data=temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value))
                    printf("Element Found!\n");
                else
                    printf("Element Not Found!\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}