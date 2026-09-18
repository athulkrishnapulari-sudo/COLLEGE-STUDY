#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void Insert(struct node **head,int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
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
void InsertBeggining(struct node **head,int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
    }
    else{
        struct node *temp;
        temp=*head;
        temp->prev=newnode;
        newnode->next=*head;
        *head=newnode;
    }
}
void InsertAtPos(struct node **head,int pos,int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(*head==NULL){
        printf("List Empty");
    }
    else{
        struct node *temp;
        temp=*head;
        int pos1=0;
        while(temp!=NULL){
            pos1++;
            if(pos1==pos){
                break;
            }
            else{
                temp=temp->next;
            }
        }
        if(temp==NULL){
            printf("Position Out of Range\n");
        }
        else{
            newnode->next=temp;
            newnode->prev=temp->prev;
            if(temp->prev != NULL)
            {
                temp->prev->next = newnode;
            }
            else
            {
                *head = newnode;
            }

            temp->prev = newnode;
        }
    }
}
void Display(struct node **head){
    if(*head==NULL){
        printf("Linked List Empty\n");
    }
    else{
        struct node *temp;
        temp=*head;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void main(){
    struct node *head = NULL;
    int choice=0,value,pos;
    while(choice!=5){
        printf("=====================\n");
        printf("      MAIN MENU      \n");
        printf("=====================\n");
        printf("1.Insert             \n");
        printf("2.Insert At Beginning\n");
        printf("3.Insert At Position \n");
        printf("4.Display            \n");
        printf("5.Exit               \n");
        printf("=====================\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value which you want to insert : ");
            scanf("%d",&value);
            Insert(&head,value);
        }
        else if(choice==2){
            printf("Enter the value which you want to insert : ");
            scanf("%d",&value);
            InsertBeggining(&head,value);
        }
        else if(choice==3){
            printf("Enter the value which you want to insert : ");
            scanf("%d",&value);
            printf("Enter the Position where you want to insert : ");
            scanf("%d",&pos);
            InsertAtPos(&head,pos,value);
        }
        else if(choice==4){
            Display(&head);
        }
        else if(choice==5){
            printf("Exiting ...");
        }
        else{
            printf("!!! INVALID CHOICE !!!");
        }

    }
}