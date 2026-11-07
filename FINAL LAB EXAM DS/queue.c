#include <stdio.h>
#include <stdlib.h>

#define size 5

int enqueue(int queue[],int *front,int *rear){
    int ele;
    if(*rear==-1){
        *front=0;
    }
    if(*rear<size-1){
        printf("Enter the Element to Enqueue : ");
        scanf("%d",&ele);
        queue[++(*rear)]=ele;
    }
    else{
        printf("Queue Full\n");
    }
    
}

void dequeue(int queue[],int *front,int *rear){
    if(*front==-1){
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted Element: %d\n",queue[*front]);
    if(*front==*rear){
        *front=-1;
        *rear=-1;
    }
    else{
        (*front)++;
    }
    
}

void peek(int queue[], int front) {
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
}

void display(int queue[],int front,int rear){
    if(front==-1){
        printf("Empty\n");
    }
    printf("\nQueue Elements:\n");
    for(int i = front; i <= rear; i++) {
        printf("| %d |", queue[i]);
    }

    printf("\n");
}


int main() {

    int queue[size];
    int front = -1, rear = -1;
    int choice;

    while(1) {

        printf("\n----- LINEAR QUEUE OPERATIONS -----\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                enqueue(queue, &front, &rear);
                break;

            case 2:
                dequeue(queue, &front, &rear);
                break;

            case 3:
                peek(queue, front);
                break;

            case 4:
                display(queue, front, rear);
                break;

            case 5:
                printf("Exiting Queue Operations...\n");
                return 0;

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}
