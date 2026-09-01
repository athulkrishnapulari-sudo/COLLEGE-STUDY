#include <stdio.h>
#include <stdlib.h>

#define size 100

int Enqueue(int q[],int front,int rear){
    int value;
    if(rear==size-1){
        printf("Queue Overflow");
        return;
    }
    else if(front==-1){
        front=0;
        rear=0;
        printf("Enter the value to enqueue");
        scanf("%d",&value);
        q[rear]=value;
    }
    else{
        rear++;
        printf("Enter the value to enqueue");
        scanf("%d",&value);
        q[rear]=value;
    }

}
int Dequeue(int q[],int front,int rear){

}


int main(){
    int queue[size];
    int choice,i;
    do{
        printf("Menu\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter Your Choice : ");
        scanf("%d",&choice);
        if (choice==1){
            
        }
        else if (choice == 2){
            
        }
        else if (choice == 3){
            
        }
        else if (choice == 4){
            printf("exiting");
            break;
        }
        else{
            printf("Invalid choice");
        }
    }
    while(choice!=4);
}