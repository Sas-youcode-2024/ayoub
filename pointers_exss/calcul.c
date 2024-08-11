#include <stdio.h>

void calc(float *a, float *b){
    printf("somme= %.2f \n", *a + *b);
    printf("produit= %.2f \n", *a * *b);
    printf("soustraction= %.2f \n", *a - *b);
    printf("dividion= %f \n", (float) *a / *b);

}

int main(){
    float a, b;
    printf("entrer la valeur de A: ");
    scanf("%f", &a);
    printf("entrer la valeur de B: ");
    scanf("%f", &b);
    printf("\n");

    calc(&a, &b);


    printf("\n");
    return 0;
}