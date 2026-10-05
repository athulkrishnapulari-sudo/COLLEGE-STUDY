#include <stdio.h>
#include <stdlib.h>

int push(int stack[],int *top,int size){
    if(*top>size-1){
        printf("Stack Overflow\n");
    }
    else{
        int data;
        printf("Enter the value which u want to insert\n");
        scanf("%d",&data);
        (*top)++;
        stack[*top]=data;
    }
}

int pop(int stack[],int *top,int size){
    if(*top==-1){
        printf("Stack Underflow , Nothing to Pop\n");
    }
    else{
        printf("The Poped Value is : %d\n",stack[*top]);
        (*top)--;
    }
}

int peek(int stack[],int top){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Top Element : %d\n",stack[top]);
    }
}

int display(int stack[],int top){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of stack : ");
    scanf("%d",&size);
    int stack[size];
    int top=-1;
    push(stack,&top,size);
    push(stack,&top,size);
    push(stack,&top,size);
    push(stack,&top,size);
    display(stack,top);
    pop(stack,&top,size);
    display(stack,top);
    peek(stack,top);
}
