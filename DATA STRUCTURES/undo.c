#include <stdio.h>
#include <stdlib.h>

#define size 10

int push(char arr[],char value,int top){
    if(top==size-1){
        printf("Overflow");
    }
    else{
        top++;
        arr[top]=value;
    }
    return top;
}
int pop(char arr[],char value,int top){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("The element deleted : %c\n",arr[top]);
        top--;    
    }
    return top;
}
void display(char arr[], int top)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Current text: ");
        for(int i = 0; i <= top; i++)
        {
            printf("%c", arr[i]);
        }
        printf("\n");
    }
}


int main(){
    int choice=0,top=-1;
    char value;
    char arr[size];
    do{
        printf("===================\n1.Type a char\n2.Undo last char\n3.Display curr text\n4.Exit\n===================\nEnter Your choice : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the character : ");
            scanf(" %c",&value);
            top=push(arr,value,top);
            display(arr, top);
        }
        else if(choice==2){
            top=pop(arr,value,top);
            display(arr, top);
        }
        else if(choice==3){
            display(arr, top);
        }
        else if(choice==4){
            printf("Exiting");
            break;
        }
        else{
            printf("invalid choice");
        }
    }
    while(choice!=4);
}