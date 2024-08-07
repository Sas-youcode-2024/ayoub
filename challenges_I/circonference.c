#include <stdio.h>
#include <math.h>

int main(){
    float rayon;
    printf("donner le rayon de cercle: ");
    scanf("%f", &rayon);

    float c = 2 * rayon * 3.14159;
    printf("C = %.2f ", c);

    printf("\n");
    return 0;
}