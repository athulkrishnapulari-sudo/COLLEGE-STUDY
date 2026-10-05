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
    int search;
    printf("Enter the element which you want to search : ");
    scanf("%d",&search);
    int low=0,high=size-1;
    int found=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(search>mid){
            low=mid+1;
        }
        else if(search<mid){
            high=mid;
        }
        else{
            printf("Element Found at index %d",mid);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Element Not Found");
    }

}