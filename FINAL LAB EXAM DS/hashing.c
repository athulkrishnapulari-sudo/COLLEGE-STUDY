#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 10
#define A 0.357840




void initialize(int hashtable[]){
    for(int i=0;i<size;i++){
        hashtable[i]=-1;
    }
}


int division(int key){
    return key%size;
}

int multiplication(int key){
    double kA = key*A;
    double kAm = fmod(kA,1);
    double f = size * kAm;
    int index = floor(f);
    return index;
}

int midSquare(int key){
    int square = key*key;
    int temp = square;
    int digits = 0;
    while(temp>0){
        digits++;
        temp=temp/10;
    }
    int remove = (digits-1)/2;
    for(int i=0;i<remove;i++){
        square = square/10;
    }
    int mid = square%10;
    return mid % size;
}

int folding(int key){
    int sum = 0;
    int temp=key;
    while(temp>0){
        sum = sum + (temp%100);
        temp=temp/100;
    }
    return sum % size;
}

int getHash(int key,int hashChoice){
    switch(hashChoice){
        case 1:
            return division(key);
        case 2:
            return multiplication(key);
        case 3:
            return midSquare(key);
        case 4:
            return folding(key);
        default:
            return division(key);
    }
}


void linearProbing(int hashTable[],int key,int index){
    for(int i=0;i<size;i++){
        int pos=(index+i)%size;
        if(hashTable[pos]==-1){
            hashTable[pos]=key;
            printf("Inserted %d at index %d\n",key,pos);
            return;
        }
    }
    printf("\nHash Table is Full");
}

void QuadraticProbing(int hashTable[],int key,int index){
    for(int i=0;i<size;i++){
        int pos=(index+(i*i))%size;
        if(hashTable[pos]==-1){
            hashTable[pos]=key;
            printf("Inserted %d at index %d\n",key,pos);
            return;
        }
    }
    printf("\nHash Table is Full");
}
int secondKey(int key){
    return 7-(key%7);
}

void DoubleHashing(int hashTable[],int key,int index){
    int sec = secondKey(key);
    for(int i=0;i<size;i++){
        int pos=(index+sec*i)%size;
        if(hashTable[pos]==-1){
            hashTable[pos]=key;
            printf("Inserted %d at index %d\n",key,pos);
            return;
        }
    }
    printf("\nHash Table is Full");
}


void insert(int hashTable[],int hashChoice,int probeChoice){
    int key;
    printf("Enter the Key to insert : ");
    scanf("%d",&key);
    int index = getHash(key,hashChoice);
    if(hashTable[index]==-1){
        hashTable[index]=key;
        printf("Inserted %d at index %d\n",key,index);
        return;
    }
    printf("Collision for %d at index %d\n",key,index);
    switch(probeChoice){
        case 1:
            linearProbing(hashTable,key,index);
            break;
        case 2:
            QuadraticProbing(hashTable,key,index);
            break;
        case 3:
            DoubleHashing(hashTable,key,index);
            break;
        default:
            linearProbing(hashTable,key,index);
    }
}
void display(int hashtable[]){
    printf("\n----- HASH TABLE -----\n");
    for(int i=0;i<size;i++){
        if(hashtable[i]==-1)
            printf("Index %d: Empty\n",i);
        else
            printf("Index %d: %d\n",i,hashtable[i]);
    }
}

int main(){
    int hashTable[size];
    initialize(hashTable);
    int hashChoice,probeChoice,choice=0;
    printf("==========HASHING METHOD==========\n");
    printf("1.Division Method\n");
    printf("2.Multiplication Method\n");
    printf("3.Mid Square Method\n");
    printf("4.Folding Method\n");
    printf("==================================\n");
    printf("Select the Hashing Method : ");
    scanf("%d",&hashChoice);
    printf("==========PROBING METHOD==========\n");
    printf("1.Linear Probing\n");
    printf("2.Quadratic Probing\n");
    printf("3.Double Hashing\n");
    printf("==================================\n");
    printf("Select the Probing Method : ");
    scanf("%d",&probeChoice);
    while(choice!=3){
        printf("\n----- OPERATIONS -----\n");
        printf("1. Insert single key\n");
        printf("2. Display Hash Table\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert(hashTable,hashChoice,probeChoice);
                break;
            case 2:
                display(hashTable);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }


}