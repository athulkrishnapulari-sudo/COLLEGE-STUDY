#include <stdio.h>
#include <stdlib.h>

#define size 5

void bubble_sort(int arr[]){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int main()
{
    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Initial Array : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    bubble_sort(arr);
    printf("\nSorted Array : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}