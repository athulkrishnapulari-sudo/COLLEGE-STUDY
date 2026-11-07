#include <stdio.h>
#include <stdlib.h>

struct Term{
    int coef;
    int exp;
};


int AddPoly(struct Term p1[],struct Term p2[],struct Term result[] , int n1 ,int n2){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(p1[i].exp==p2[j].exp){
            result[k].coef = p1[i].coef+p2[j].coef;
            result[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp){
            result[k].exp = p1[i].exp;
            result[k].coef = p1[i].coef;
            i++;
            k++;
        }
        else{
            result[k].exp = p2[j].exp;
            result[k].coef = p2[j].coef;
            j++;
            k++;
        }
    }
    while(i<n1){
        result[k].exp = p1[i].exp;
        result[k].coef = p1[i].coef;
        i++;
        k++;
    }
    while(j<n2){
        result[k].exp = p2[j].exp;
        result[k].coef = p2[j].coef;
        j++;
        k++;
    }
    return k;
}

void display(struct Term poly[],int size){
    for(int i=0;i<size;i++){
        printf("%dx^%d",poly[i].coef,poly[i].exp);
        if(i!=size-1){
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    int p1s,p2s;
    printf("Enter the size of Polynomial 1 : ");
    scanf("%d",&p1s);
    printf("Enter the size of Polynomial 2 : ");
    scanf("%d",&p2s);
    struct Term p1[p1s],p2[p2s],result[p1s+p2s];
    printf("Enter the Coeff Exp of Polynomial 1 : \n");
    for(int i=0;i<p1s;i++){
        scanf("%d %d",&p1[i].coef,&p1[i].exp);
    }
    printf("Enter the Coeff Exp of Polynomial 2 : \n");
    for(int i=0;i<p2s;i++){
        scanf("%d %d",&p2[i].coef,&p2[i].exp);
    }
    printf("Entered Polynomial 1 : ");
    display(p1,p1s);
    printf("Entered Polynomial 2 : ");
    display(p2,p2s);
    printf("Resulting Polynomial : ");
    display(result,AddPoly(p1,p2,result,p1s,p2s));
}