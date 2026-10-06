#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void enqueue(struct node **front,struct node **rear){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter the Value which you want to insert : ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(*front==NULL){
        *front=newnode;
        *rear=newnode;
    }
    else{
        struct node *temp;
        temp=*rear;
        temp->next=newnode;
        *rear=newnode;
    }
}

void dequeue(struct node **front,struct node **rear){
    if(*front==NULL){
        printf("Nothing to Delete Queue Empty");
        return;
    }
    struct node *temp;
    temp=*front;
    *front=temp->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display(struct node **front){
    
    if(*front==NULL){
        printf("Queue Empty\n");
    }
    else{
        struct node *temp;
        temp=*front;
        while(temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    struct node *front = NULL;
    struct node *rear = NULL;
    enqueue(&front,&rear);
    enqueue(&front,&rear);
    enqueue(&front,&rear);
    display(&front);
    dequeue(&front,&rear);
    display(&front);
}