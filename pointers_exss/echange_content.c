#include <stdio.h>

void echange(int *A, int *B)
{
    if (*A * *B > 0)
    {
        int tmp = *A;
        *A = *B;
        *B = tmp;
    }
    else
    {
        int tmp = *A;
        *A = *A + *B;
        *B = tmp * *B;
    }
}

int main()
{
    int a, b;
    printf("donner les valeur de A et B: \n");
    scanf("%d %d", &a, &b);

    echange(&a, &b);
    printf("A = %d, B = %d", a, b);

    printf("\n");
    return 0;
}