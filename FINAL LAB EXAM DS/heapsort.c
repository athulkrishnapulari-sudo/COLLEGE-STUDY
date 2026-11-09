#include <stdio.h>
#include <stdlib.h>

#define size 100


void printArray(int arr[], int n){
    for (int i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void readArray(int arr[], int n){
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
}


void MaxHeapify(int arr[],int i,int n){
    int largest = i;
    int l = i*2;
    int r = (i*2)+1;
    if(l<=n && arr[largest]<arr[l]){
        largest = l;
    }
    if(r<=n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        MaxHeapify(arr,largest,n);
    }
}

void HeapSort(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        MaxHeapify(arr,i,n);
        printArray(arr,n);
    }
    for(int i=n;i>=2;i--){
        int temp=arr[i];
        arr[i]=arr[1];
        arr[1]=temp;
        printArray(arr,n);
        MaxHeapify(arr,1,i-1);
        printArray(arr,n);
    }
}

int main(){
    int arr[50];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    readArray(arr, n);
    printf("Original array: ");
    printArray(arr, n);
    HeapSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}