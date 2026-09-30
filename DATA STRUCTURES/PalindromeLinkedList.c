
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};

void insert(struct node **head, char data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node **head, char a[])
{
    struct node *temp = *head;
    int i = 0;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        a[i++] = temp->data;

        temp = temp->next;
    }
    a[i] = '\0';
}

void reverse(struct node **head, char b[])
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    struct node *temp = *head;
    int i = 0;

    while (temp != NULL)
    {
        b[i++] = temp->data;
        temp = temp->next;
    }
    b[i] = '\0';
}

int main()
{
    struct node *head = NULL;
    char data;
    char a[100];
    char b[100];
    printf("Enter the String : ");
    while ((data = getchar()) != '\n')
    {
        insert(&head, data);
    }
    printf("\nString Entered : ");
    display(&head, a);
    reverse(&head, b);
    printf("\nReversed String : %s", b);
    if (strcmp(a, b) == 0)
    {
        printf("\nPalindrome");
    }
    else
    {
        printf("\nNot Palindrome");
    }

    return 0;
}
