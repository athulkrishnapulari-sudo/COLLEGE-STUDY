#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int size=10;
double A = 0.618033;

void initialize(int a[]){
    for(int i=0;i<size;i++){
        a[i]=-1;
    }
}

void Division(int arr[]){
    int ele;
    printf("Enter The element to Insert : ");
    scanf("%d",&ele);
    int hash = ele%size;
    if(arr[hash]==-1){
        arr[hash]=ele;
    }
    else{
        printf("%d Already Occupied\n",hash);
    }
}

void MidSquare(int arr[size]){
    int ele;
    printf("Enter The element to Insert");
    scanf("%d",&ele);
    int mid = (ele /100)%100;
    int hash = mid % size;
    if(arr[hash]==-1){
        arr[hash]=ele;
    }
    else{
        printf("%d Already Occupied\n",hash);
    }
}

void Multiplication(int arr[size]){
    int ele;
    printf("Enter The element to Insert");
    scanf("%d",&ele);
    double kA = ele*A;
    double kAm = fmod(kA,1.0);
    int hash = size * kAm;
    if(arr[hash]==-1){
        arr[hash]=ele;
    }
    else{
        printf("%d Already Occupied\n",hash);
    }
}

int hashFolding(int arr[]) {
    int ele;
    printf("Enter The element to Insert");
    scanf("%d",&ele);
    char str[20];
    sprintf(str, "%d", ele);
    int sum = 0;
    for (int i = 0; i < strlen(str); i += 2) {
        char chunk[3] = {0};
        strncpy(chunk, str + i, 2);
        sum += atoi(chunk);
    }
    int hash= sum % size;
    if(arr[hash]==-1){
        arr[hash]=ele;
    }
    else{
        printf("%d Already Occupied\n",hash);
    }
}

void display(int arr[]){
    for(int i=0;i<size;i++){
        if(arr[i]==-1){
            printf("EMPTY\n");
        }
        else{
            printf("%d\n",arr[i]);
        }
        
    }
}


int main() {
    int arr[10];
    int methodChoice, contChoice;

    initialize(arr);

    printf("\n--- Choose Hashing Method ---\n");
    printf("1. Division Method\n");
    printf("2. Mid-Square Method\n");
    printf("3. Multiplication Method\n");
    printf("4. Folding Method\n");
    printf("Enter your choice: ");
    scanf("%d", &methodChoice);

    while (1) {
        switch (methodChoice) {
            case 1:
                Division(arr);
                break;
            case 2:
                MidSquare(arr);
                break;
            case 3:
                Multiplication(arr);
                break;
            case 4:
                hashFolding(arr);
                break;
            default:
                printf("Invalid choice!\n");
                return 0;
        }

        printf("\nCurrent Hash Table:\n");
        display(arr);

        printf("\nDo you want to insert another element? (1 = Yes, 0 = Exit): ");
        scanf("%d", &contChoice);

        if (contChoice == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
