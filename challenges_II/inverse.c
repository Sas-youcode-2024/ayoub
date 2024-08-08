#include <stdio.h>
#include <math.h>

int main()
{
    int nbre, inverse = 0;
    printf("enter number de votre choix: ");
    scanf("%d", &nbre);
    int tmp = nbre;
    do
    {
        inverse = (inverse * 10) + (nbre % 10);
        nbre = nbre / 10;
    } while (nbre != 0);

    printf("l'inverse de %d est %d", tmp, inverse);

    printf("\n");
    return 0;
}