#include <stdio.h>
#include <stdlib.h>

struct polynomial{
    int coeff;
    int exp;
};

int main(){
    int deg1,deg2;
    int largest;
    if (deg1>=deg2){
        largest=deg1;
    }
    else{
        largest=deg2;
    }
    printf("Enter the degree of polynomial 1");
    scanf("%d",&deg1);
    printf("Enter the degree of polynomial 2");
    scanf("%d",&deg2);
    struct polynomial poly1[deg1+1];
    struct polynomial poly2[deg2+1];
    struct polynomial result[deg1+deg2+2];
    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < deg1; i++){
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }
    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < deg2; i++){
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }
    int i=0,j=0,deg3=0;
    while(i<deg1 && i<deg2){
        if(poly1[i].exp == poly2[j].exp){
            result[deg3].coeff = poly1[i].coeff + poly2[j].coeff;
            result[deg3].exp = poly1[i].exp;
            i++;
            j++;
        } 
        else if (poly1[i].exp > poly2[j].exp) {
            result[deg3] = poly1[i];
            i++;
        }
        else {
            result[deg3] = poly2[j];
            j++;
        }

        (deg3)++;

    }
    while (i < deg1)
        result[(deg3)++] = poly1[i++];

    while (j < deg2)
        result[(deg3)++] = poly2[j++];
    
    for (int i = 0; i < deg3; i++) {
        printf("%dx^%d", result[i].coeff, result[i].exp);

        if (i != deg3 - 1)
            printf(" + ");
    }
}