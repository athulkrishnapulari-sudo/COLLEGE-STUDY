#include <stdio.h>
#include <stdlib.h>

#define size 5

int linearSearch(int a[]){
    int search;
    int flag=0;
    printf("\nEnter the Element to Search : ");
    scanf("%d",&search);
    for(int i=0;i<size;i++){
        if(a[i]==search){
            flag=1;
            printf("Element Found At Index %d\n",i);
        }
    }
    if(flag==0){
        printf("Element Not Found!!!");
    }
}

int binarySearch(int a[]){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int search;
    int flag=0;
    printf("\nEnter the Element to Search : ");
    scanf("%d",&search);
    int low=0;
    int high = size-1;
    int mid;
    while(low<high){
        mid = (low+high)/2;
        if(search<a[mid]){
            high=mid;
        }
        else if(search>a[mid]){
            low=mid+1;
        }
        else{
            printf("Element Found at index %d",mid);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Element Not Found!!!");
    }
}


int main() {
    int arr[size];
    int choice;

    for (int i = 0; i < size; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Array : ");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    do {
        printf("\n\n----- SEARCH MENU -----\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");

        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearSearch(arr);
                break;

            case 2:
                binarySearch(arr);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}