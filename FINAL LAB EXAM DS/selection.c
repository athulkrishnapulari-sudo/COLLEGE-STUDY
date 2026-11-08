#include <stdio.h>
#include <stdlib.h>

#define size 5

int min(int arr[],int low){
    int smallest=low;
    for(int i=low+1;i<size;i++){
        if(arr[i]<arr[smallest]){
            smallest=i;
        }
    }
    return smallest;
}

void selection(int arr[]){
    int low=0;
    while(low<size){
        
        int smallest = min(arr, low);

        int temp = arr[low];
        arr[low] = arr[smallest];
        arr[smallest] = temp;
        low++;
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
    selection(arr);
    printf("\nSorted Array : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}