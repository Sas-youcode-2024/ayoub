#include <stdio.h>

int main()
{
    int a;
    printf("entrer un nombre: ");
    scanf("%d", &a);

    int *p = &a;

    if (*p % 2 == 0)
        printf("nombre pair");
    else
        printf("nombre impair");

    printf("\n");
    return 0;
}