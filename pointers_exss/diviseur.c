#include <stdio.h>

int main()
{
    int n;
    int *p = &n;

    do{
        printf("entrer un nombre positif non null: ");
        scanf("%d", p);
    } while (*p <= 0);

    printf("les diviseurs sont: { ");
    for (int i = 1; i <= *p; i++)
    {
        if (*p % i == 0)
            printf("%d ", i);
    }
    printf("}");

    printf("\n");
    return 0;
}