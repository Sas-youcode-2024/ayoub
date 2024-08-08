#include <stdio.h>

int main()
{
    int nbre;
    printf("enter a number: ");
    scanf("%d", &nbre);
    if (nbre % 2 == 0)
        printf("%d is pair\n", nbre);
    else
        printf("%d is impair\n", nbre);

    return 0;
}