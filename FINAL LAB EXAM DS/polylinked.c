#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coeff;
    int exp;
    struct poly* next;
};

struct poly* createNode(int coeff,int exp){
    struct poly *newnode = (struct poly*)malloc(sizeof(struct poly));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;
}

void create(struct poly **p,int n){
    int coeff,exp;
    printf("Enter the Coeff exp of polynomial");
    for(int i=0;i<n;i++){
        scanf("%d %d",&coeff,&exp);
        if(*p==NULL){
            *p=createNode(coeff,exp);
        }
        else{
            struct poly *temp = *p;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=createNode(coeff,exp);
        }
    }
}

void AddPoly(struct poly *p1,struct poly *p2,struct poly **result){
    struct poly *temp;
    while(p1!=NULL && p2!=NULL){
        if(p1->exp==p2->exp){
            int sumcoeff = p1->coeff+p2->coeff;
            if(*result==NULL){
                *result=createNode(sumcoeff,p1->exp);
                temp = *result;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=createNode(sumcoeff,p1->exp);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->exp>p2->exp){
            if(*result==NULL){
                *result=createNode(p1->coeff,p1->exp);
                temp = *result;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=createNode(p1->coeff,p1->exp);
            }
            p1=p1->next;
        }
        else if(p2->exp>p1->exp){
            if(*result==NULL){
                *result=createNode(p2->coeff,p2->exp);
                temp = *result;
            }
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=createNode(p2->coeff,p2->exp);
            }
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        if(*result==NULL){
            *result=createNode(p1->coeff,p1->exp);
            temp = *result;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=createNode(p1->coeff,p1->exp);
        }
        p1=p1->next;
    }
    while(p2!=NULL){
        if(*result==NULL){
            *result=createNode(p2->coeff,p2->exp);
            temp = *result;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=createNode(p2->coeff,p2->exp);
        }
        p2=p2->next;
    }
}

void display(struct poly *head) {
    struct poly *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    struct poly *p1=NULL,*p2=NULL,*result=NULL;
    int p1s,p2s;
    printf("Enter the size of poly1 : ");
    scanf("%d",&p1s);
    create(&p1,p1s);
    printf("Enter the size of poly2 : ");
    scanf("%d",&p2s);
    create(&p2,p2s);
    display(p1);
    display(p2);
    AddPoly(p1, p2, &result);

    printf("Resultant Polynomial: ");
    display(result);
}