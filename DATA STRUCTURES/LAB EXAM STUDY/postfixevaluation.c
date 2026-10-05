#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int push(int stack[],int *top,int size,int data){
    if(*top>size-1){
        printf("Stack Overflow\n");
    }
    else{
        (*top)++;
        stack[*top]=data;
    }
}

int pop(int stack[],int *top,int size){
        int now = stack[*top];
        (*top)--;
        return now;
}

int peek(int stack[],int top){

    return stack[top];

}

int main(){
    int size=10;
    char postfix[size];
    printf("Enter the postfix Expression : ");
    scanf("%s",postfix);
    int stack[size];
    int top=-1;
    for(int i=0;postfix[i]!='\0';i++){
        char ch = postfix[i];
        if(isalnum(ch)){
            push(stack,&top,size,ch - '0');
        }
        else{
            int b = pop(stack,&top,size);
            int a = pop(stack,&top,size);
            int result;
            switch(ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;
            }
            push(stack,&top,size,result);
        }
    }
    printf("The Result is %d",peek(stack,top));
}