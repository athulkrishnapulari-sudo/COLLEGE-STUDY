#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


void enqueue(struct node **front,struct node **rear,int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(*front==NULL){
        *front=*rear=newnode;
    }
    else{
        (*rear)->next=newnode;
        *rear = newnode;
    }
}

void dequeue(struct node **front,struct node **rear){
    struct node *temp;
    if(*front==NULL){
        printf("Queue Empty\n");
        return;
    }
    temp=*front;
    printf("Deleted Element %d",temp->data);
    *front = (*front)->next;
    if(*front==NULL){
        *rear=NULL;
    }
    free(temp);

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
    struct node *front=NULL;
    struct node *rear=NULL;

    int choice,value;

    while(1){
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d",&value);
                enqueue(&front,&rear,value);
                break;

            case 2:
                dequeue(&front,&rear);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}