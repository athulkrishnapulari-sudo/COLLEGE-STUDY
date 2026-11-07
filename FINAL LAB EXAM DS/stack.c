#include <stdio.h>
#include <stdlib.h>

#define size 5

void push(int stack[],int *top){
    int ele;
    if(*top==size-1){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter the Element to Push : ");
        scanf("%d",&ele);
        stack[++(*top)]=ele;
    }
}

void pop(int stack[],int *top){
    if(*top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("The Element %d Poped !\n",stack[(*top)--]);
    }
}

void peek(int stack[],int top){
    if(top==-1){
        printf("Stack Empty\n");
    }
    else{
        printf("The Top Element is : %d\n",stack[top]);
    }
}

void display(int stack[],int top){
    for(int i=top;i>=0;i--){
        printf("| %d |\n",stack[i]);
    }
    printf("------\n");
}

int main() {
    int stack[size];
    int top = -1;
    int choice;

    do {
        printf("\n----- STACK OPERATIONS -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                push(stack, &top);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                peek(stack, top);
                break;

            case 4:
                if(top == -1) {
                    printf("Stack Empty\n");
                }
                else {
                    display(stack, top);
                }
                break;

            case 5:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}