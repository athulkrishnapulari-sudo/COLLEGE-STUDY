#include <stdio.h>
#include <stdlib.h>

#define size 100

void insert(int heap[],int *n,int value){
    *n=*n+1;
    heap[*n]=value;
    int i = *n;
    while(i>1){
        int parent=(i/2);
        if(heap[parent]<heap[i]){
            int temp=heap[parent];
            heap[parent]=heap[i];
            heap[i]=temp;
            i=parent;
        }
        else{
            return;
        }
    }
}
void delete(int heap[],int *n){
    heap[1]=heap[*n];
    *n=*n-1;
    int i=1;
    while(i<=*n){
        int left = i*2;
        int right = i*2+1;
        int child;
        if (left > *n) {
            return;
        }
        if(right <= *n && heap[left]>heap[right]){
            child=left;
        }
        else{
            child=right;
        }
        if(heap[i]<heap[child]){
            int temp=heap[child];
            heap[child]=heap[i];
            heap[i]=temp;
            i=child;
        }
        else{
            return;
        }

    }
}

int main(){
    int heap[size]={0,70,60,40,45,50,39,16,10,9,35};
    int n=10;
    int value;

    printf("Enter value: ");
    scanf("%d",&value);
    insert(heap,&n,value);

    printf("Enter value: ");
    scanf("%d",&value);
    insert(heap,&n,value);

    printf("Max Heap: ");
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    delete(heap, &n);
    printf("\nMax Heap: ");
    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}