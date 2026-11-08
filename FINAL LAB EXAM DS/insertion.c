#include <stdio.h>
#include <stdlib.h>

#define size 5

void insertion(int arr[]) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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
    insertion(arr);
    printf("\nSorted Array : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}