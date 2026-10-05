#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define size 10

char stack[size];
int top = -1;

void push(char ch){
    stack[++top]=ch;
}
char pop(){
    return stack[top--];
}
char peek(){
    return stack[top];
}
int precedence(char ch){
    switch(ch){
        case '^':
            return 3;
        case '/':
        case '*':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
char infixtopostfix(char infix[],char postfix[]){
    int i=0;
    int j=0;
    char ch;
    while(infix[i]!='\0'){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j]=ch;
            j++;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j]=pop();
                j++;
            }
            if(top!=-1){
                pop();
            }
        }
        else{
            while(top!=-1 && stack[top]!='(' && precedence(stack[top])>=precedence(ch)){
                postfix[j]=pop();
                j++;
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
            postfix[j] = pop();
            j++;
        }
        postfix[j]='\0';
}

int main()
{
    char infix[size];
    char postfix[size];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}