#include <stdio.h>
#include <stdlib.h>

#define size 5

int min(int arr[],int low){
    int min=arr[low];
    int min_index = low;
    for(int i=low;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
            min_index=i;
        }
    }
    return min_index;
}

int main(){
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++){
        int index=min(arr,i+1);
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
    printf("Sorted Array : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}