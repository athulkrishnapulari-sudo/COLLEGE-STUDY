#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

void insert(struct node **head,int value){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    new->value=value;
    if(*head==NULL){
        *head=new;
    }
    else{
        struct node *temp;
        temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}


void insertBeg(struct node **head,int value){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->value=value;
    new->next=*head;
    *head = new;
}

void insertAtPos(struct node **head,int key,int value){
    if(*head==NULL){
        printf("List is Empty");
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->value=value;
        int curr_pos = 0;
        struct node *temp;
        temp = *head;
        while(curr_pos<key-2 && temp->next!=NULL){
            curr_pos++;
            temp=temp->next;
        }
        if(curr_pos!=key-2){
            printf("Position does not exists");
            free(new);
        }
        else{
            new->next = temp->next;
            temp->next=new;
        }
    }
}


void display(struct node **head){
    if(*head==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        struct node *temp;
        temp=*head;
        while(temp!=NULL){
            printf("%d -> ",temp->value);
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
            insert(&head,value);
        }
        else if(choice==2){
            printf("Enter the value which you want to insert : ");
            scanf("%d",&value);
            insertBeg(&head,value);
        }
        else if(choice==3){
            printf("Enter the value which you want to insert : ");
            scanf("%d",&value);
            printf("Enter the Position where you want to insert : ");
            scanf("%d",&pos);
            insertAtPos(&head,pos,value);
        }
        else if(choice==4){
            display(&head);
        }
        else if(choice==5){
            printf("Exiting ...");
        }
        else{
            printf("!!! INVALID CHOICE !!!");
        }

    }
}