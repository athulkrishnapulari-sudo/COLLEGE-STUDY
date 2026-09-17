#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (*top == NULL)
    {
        *top = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
}

void pop(struct node **top){
    if(*top==NULL){
        printf("STACK EMPTY. NOTHING TO POP");
    }
    else{
        struct node *temp;
        temp=*top;
        *top=temp->next;
        printf("Popped %d\n",temp->data);
        free(temp);
    }
}
void peek(struct node **top){
    if(*top==NULL){
        printf("STACK EMPTY");
    }
    else{
        struct node *temp;
        temp=*top;
        printf("Top Element is : %d\n",temp->data);
    }
}

void display(struct node **top)
{
    struct node *temp;
    temp = *top;
    if (*top == NULL)
    {
        printf("STACK EMPTY");
    }
    else
    {
        printf("The STACK : \n");
        while (temp != NULL)
        {
            printf("| %d |", temp->data);
            if (*top == temp)
            {
                printf(" <-Top");
            }
            temp = temp->next;
            printf("\n");
        }
        printf("------\n");
    }
}

void main()
{
    struct node *top = NULL;
    int choice,value;
    while(choice!=5){
        printf("=============\n");
        printf("  MAIN MENU\n");
        printf("=============\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n=============\nEnter Your Choice : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the Value that you want to push : ");
            scanf("%d",&value);
            push(&top,value);
        }
        else if(choice==2){
            pop(&top);
        }
        else if(choice==3){
            peek(&top);
        }
        else if(choice==4){
            display(&top);
        }
        else if(choice==5){
            printf("Exiting...");
        }
        else{
            printf("!!! INVALID CHOICE !!!");
        }
    }
}