#include <stdio.h>
#include <stdlib.h>

int merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k =0;

    int temp[100];

    while(i<=mid && j<=high){
        if(arr[j]<=arr[i]){
            temp[k]=arr[j];
            j++;
            k++;
        }
        else if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=arr[j];
        j++;
        k++;
    }
    k = 0;
    for (int x = low; x <= high; x++) {
        arr[x] = temp[k];
        k++;
    }
}
int mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[] = {8, 3, 12, 7, 15, 2, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}