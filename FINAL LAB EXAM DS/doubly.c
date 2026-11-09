#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};


void insertEnd(struct node **head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        newnode->prev=NULL;
    }
    else{
        struct node *temp;
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertBeg(struct node **head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        if((*head)!=NULL){
            (*head)->prev=newnode;
        }
        *head=newnode;
    }
}


void insertPos(struct node **head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&newnode->data);
    int pos;
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    if (pos == 1) {
        newnode->next = *head;
        newnode->prev=NULL;
        if(*head != NULL) {
            (*head)->prev = newnode;
        }
        *head = newnode;
        return;
    }
    else{
        int i=1;
        struct node *temp = *head;
        while(temp!=NULL&& i<pos-1){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("Invalid Position");
            free(newnode);
        }
        else{
            newnode->next=temp->next;
            newnode->prev=temp;
            if(newnode->next!=NULL){
                temp->next->prev=newnode;
            }
            temp->next=newnode;
        }
    }
}
void deleteEnd(struct node **head){
    if(*head==NULL){
        printf("Empty\n");
        return;
    }
    struct node *temp=*head;
    if(temp->next==NULL){
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}


void deleteBeg(struct node **head){
    if(*head==NULL){
        printf("Empty\n");
        return;
    }
    struct node *temp=*head;
    if(temp->next==NULL){
        *head=NULL;
        free(temp);
        return;
    }
    else{
        *head=temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

void deletePos(struct node **head){
    if(*head==NULL){
        printf("Empty\n");
        return;
    }
    struct node *temp=*head;
    int pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d",&pos);
    if (pos == 1) {
        *head=temp->next;
        if(*head!=NULL) {
            (*head)->prev=NULL;
        }
        free(temp);
        return;
    }
    else{
        int i=1;
        struct node *temp = *head;
        while(temp!=NULL&& i<pos){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("Invalid Position\n");
            return;
        }
        else{
            if(temp->next!=NULL) {
                temp->next->prev=temp->prev;
            }
            temp->prev->next=temp->next;
            free(temp);
        }
    }
}

void display(struct node *head){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node *head = NULL;
    int choice;

    while(1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                insertBeg(&head);
                break;

            case 2:
                insertEnd(&head);
                break;

            case 3:
                insertPos(&head);
                break;

            case 4:
                deleteBeg(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                deletePos(&head);
                break;

            case 7:
                display(head);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}