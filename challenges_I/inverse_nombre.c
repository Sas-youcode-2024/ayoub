#include <stdio.h>
#include <math.h>

int main()
{
    int nbre, inverse = 0;
    printf("enter number with 3 chiffres. ");
    scanf("%d", &nbre);

    do
    {
        inverse = inverse * 10 + nbre % 10;
        nbre = nbre / 10;
    } while (nbre != 0);

    printf("inverse is: %d", inverse);

    printf("\n");
    return 0;
}