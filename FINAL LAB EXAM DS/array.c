#include <stdio.h>
#include <stdlib.h>

#define size 5

void insert(int a[],int *length){
    int value;
    if(*length<size){
        printf("Enter the Element to Insert : ");
        scanf("%d",&value);
        a[(*length)++]=value;
    }
}
void search(int a[],int length){
    if(length==0){
        printf("Nothing to Search !!!");
        return;
    }
    else{
        int search;
        int flag=0;
        printf("\nEnter the Element to Search : ");
        scanf("%d",&search);
        for(int i=0;i<length;i++){
            if(a[i]==search){
                flag=1;
                printf("Element Found At Index %d\n",i);
            }
        }
        if(flag==0){
            printf("Element Not Found!!!");
        }
    }
}

void update(int a[],int length){
    int index;
    int element;
    printf("\nEnter the Index which you want to Update : ");
    scanf("%d",&index);
    if(index+1<=length){
        printf("Enter the New Element : ");
        scanf("%d",&element);
        a[index]=element;
    }
}

void delete(int a[],int *length){
    int index;
    printf("\nEnter the Index which you want to Delete : ");
    scanf("%d",&index);
    if(index==*length-1){
        (*length)--;
    }
    else if(index<*length-1){
        for(int i=index;i<*length-1;i++){
            a[i]=a[i+1];
        }
        (*length)--;
    }
    else{
        printf("Index Out of Range\n");
    }
}

void sort(int a[],int length){
    int temp;
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void display(int a[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",a[i]);
    }
}

int main()
{
    int length = 0;
    int arr[size];
    int choice;

    while (1)
    {
        printf("\n========== ARRAY OPERATIONS ==========\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Sort\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert(arr, &length);
                break;

            case 2:
                search(arr, length);
                break;

            case 3:
                update(arr, length);
                break;

            case 4:
                delete(arr, &length);
                break;

            case 5:
                sort(arr, length);
                break;

            case 6:
                display(arr, length);
                break;

            case 7:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}