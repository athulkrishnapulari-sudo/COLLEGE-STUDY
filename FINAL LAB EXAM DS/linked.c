#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertEnd(struct node **head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp;
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insertBeg(struct node **head){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
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
    
    if(*head==NULL){
        printf("List Empty\n");
        return;
    }
    if (pos == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    else{
        int i=1;
        struct node *temp = *head;
        while(temp->next!=NULL&& i!=pos-1){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("Invalid Position");
            free(newnode);
        }
        else{
            newnode->next=temp->next;
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
    struct node *prev = temp;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
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
        free(temp);
        return;
    }
    else{
        int i=1;
        struct node *temp = *head;
        struct node *prev = temp;
        while(temp!=NULL&& i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(temp==NULL || temp->next==NULL && i<pos-1) {
            printf("Invalid Position\n");
            return;
        }
        else{
            prev->next=temp->next;
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

int main(){
    struct node *head = NULL;
    insertEnd(&head);
    insertEnd(&head);
    display(head);
    insertBeg(&head);
    display(head);
    insertPos(&head);
    display(head);
    deleteEnd(&head);
    display(head);
    deleteBeg(&head);
    display(head);
    deletePos(&head);
    display(head);
}