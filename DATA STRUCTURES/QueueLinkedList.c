#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void enqueue(struct node **head,int value){
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
void dequeue(struct node **top){
    if(*top==NULL){
        printf("QUEUE EMPTY. NOTHING TO DEQUEUE");
    }
    else{
        struct node *temp;
        temp=*top;
        *top=temp->next;
        free(temp);
    }
}
void peek(struct node **top){
    if(*top==NULL){
        printf("QUEUE EMPTY");
    }
    else{
        struct node *temp;
        temp=*top;
        printf("Front Element is : %d\n",temp->value);
    }
}

void display(struct node **top)
{
    struct node *temp;
    temp = *top;
    if (*top == NULL)
    {
        printf("QUEUE EMPTY");
    }
    else
    {
        printf("The QUEUE : \n");
        while (temp != NULL)
        {
            printf("| %d |", temp->value);
            if (*top == temp)
            {
                printf(" <-Front");
            }
            else if(temp->next==NULL){
                printf(" <-Rear");
            }
            temp = temp->next;
            printf("\n");
        }
        printf("------\n");
    }
}

int main()
{
    struct node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&head, value);
                printf("%d inserted into queue.\n", value);
                break;

            case 2:
                dequeue(&head);
                break;

            case 3:
                peek(&head);
                break;

            case 4:
                display(&head);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}