#include <stdio.h>
#include <stdlib.h>

#define size 5

int enqueue(int arr[],int *front,int *rear){
    int value;
    printf("Enter the Value which you want to insert : ");
    scanf("%d",&value);
    if ((*rear + 1) % size == *front) {
        printf("Overflow\n");
        return -1;
    }

    if (*front == -1) {
        *front = *rear = 0;
    } else {
        *rear = (*rear + 1) % size;
    }
    arr[*rear]=value;
}
int dequeue(int arr[],int *front,int *rear){
    if(*front==-1){
        printf("Nothing to Dequeue Queue Empty");
        return;
    }
    if(*front==*rear){
        *front=*rear=-1;
    }
    else{
        *front = (*front + 1) % size;
    }
    
}
int peek(int arr[],int *front,int *rear){
    
}
void display(int arr[], int front, int rear) {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;           
        i = (i + 1) % size;              
    }
    printf("\n");
}


int main(){
    int front = -1;
    int rear = -1;
}
