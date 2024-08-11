#include <stdio.h>

int main()
{
    int tab[4];
    int *p = tab;

    printf("remplir le tableau: \n");
    for (p = tab; p < tab + 4; p++)
    {
        printf("tab[%d]= ", (int) (p - tab + 1));
        scanf("%d", p);
    }
    printf("\n");
    for (p = tab; p < tab + 4; p++)
    {
        printf("%d ", *p);
    }

    printf("\n");
    return 0;
}