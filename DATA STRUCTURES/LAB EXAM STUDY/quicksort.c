#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int start, int stop)
{
    int i = start;
    int j = stop;
    int pivot = start;

    while(i < j)
    {
        while(i <= stop && arr[i] <= arr[pivot])
        {
            i++;
        }

        while(j >= start && arr[j] > arr[pivot])
        {
            j--;
        }

        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Put pivot in its correct position
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int j = partition(arr, low, high);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted Array: ");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}