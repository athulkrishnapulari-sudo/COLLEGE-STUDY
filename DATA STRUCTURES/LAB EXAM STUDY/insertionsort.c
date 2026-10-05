#include <stdio.h>
#include <stdlib.h>



int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=key;
    }
    printf("Sorted Array : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

}