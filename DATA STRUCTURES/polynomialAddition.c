#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coeff;
    int exp;
};

void input(struct poly p[],int size){
    for(int i=0;i<size;i++){
        scanf("%d %d",&p[i].coeff,&p[i].exp);
    }
}
void display(struct poly p[],int size){
    int i;
    for(i=0;i<size-1;i++){
        printf("%dx^%d +",p[i].coeff,p[i].exp);
    }
    printf("%dx^%d\n",p[i].coeff,p[i].exp);
}
int PolynomialAddition(struct poly p1[],struct poly p2[],struct poly result[],int size1,int size2){
    int k=0;
    if(size1<size2){
        for(int i=0;i<size1;i++){
            int coeffSum=p1[i].coeff;
            int exp = p1[i].exp;
            for(int j=0;j<size2;j++){
                if(p1[i].exp==p2[j].exp){
                    coeffSum+=p2[j].coeff;
                }
            }
            result[k].coeff=coeffSum;
            result[k].exp=exp;
            k++;
        }
       for(int i=0;i<size2;i++){
            int exp = p2[i].exp;
            int found =0;
            for(int j=0;j<size1;j++){
                if(p2[i].exp==p1[j].exp){
                    found = 1;
                }
            }
            if(found==0){
                result[k].coeff=p2[i].coeff;
                result[k].exp=p2[i].exp;
                k++;
            }
            
        }
        
    }
    else{
        for(int i=0;i<size2;i++){
            int coeffSum=p2[i].coeff;
            int exp = p2[i].exp;
            for(int j=0;j<size1;j++){
                if(p2[i].exp==p1[j].exp){
                    coeffSum+=p1[j].coeff;
                }
            }
            result[k].coeff=coeffSum;
            result[k].exp=exp;
            k++;
        }
        for(int i=0;i<size1;i++){
            int exp = p1[i].exp;
            int found =0;
            for(int j=0;j<size2;j++){
                if(p1[i].exp==p2[j].exp){
                    found = 1;
                }
            }
            if(found==0){
                result[k].coeff=p1[i].coeff;
                result[k].exp=p1[i].exp;
                k++;
            }
            
        }
    }
    return k;
}

int main(){
    int size1,size2;
    printf("Enter the Number of Terms of Polynomial 1 : ");
    scanf("%d",&size1);
    struct poly p1[size1];
    printf("Enter the 'Coefficient Exponent' of Polynomial 1 : \n");
    input(p1,size1);

    printf("Enter the Number of Terms of Polynomial 2 : ");
    scanf("%d",&size2);
    struct poly p2[size2];
    printf("Enter the 'Coefficient Exponent' of Polynomial 2 : \n");
    input(p2,size2);

    printf("Entered Polynomial 1 : \n");
    display(p1,size1);
    printf("Entered Polynomial 2 : \n");
    display(p2,size2);

    struct poly result[size1+size2];
    int resultsize = PolynomialAddition(p1,p2,result,size1,size2);
    display(result,resultsize);

}