#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, delta, x, x1, x2;
    printf("donner les valeurs de a, b et c. \n");
    scanf("%d %d %d", &a, &b, &c);

    delta = pow(b, 2) - (4 * a * c);
    if (delta < 0)
        printf("na pas de solutions dans IR.\n");
    else if (delta = 0)
    {
        x = (-b) / (2 * a);
        printf("l'equation edmet un seule solution x = %d\n", x);
    }
    else
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        printf("l'equation admet deux solutions, x1 = %d et x2 = %d\n", x1, x2);
    }

    return 0;
}