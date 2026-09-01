#include <stdio.h>

int main() {
    int size = 8;
    int a[8] = {8, 3, 12, 7, 15};
    int count = 5; 
    if (count < size) {
        printf("Enter the number to insert: ");
        scanf("%d", &a[count]);
        count++;
    } else {
        printf("Array is full!\n");
    }
    for (int i = 0; i < count; i++) {
        printf("%d\n", a[i]);
    }

    

    return 0;