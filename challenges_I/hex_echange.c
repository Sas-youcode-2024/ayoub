#include <stdio.h>
#include <string.h>

int main()
{
    int nbre, octal, rest;
    char hexa[10];
    printf("enter a number: ");
    scanf("%d", &nbre);

    //! decimal = 8 ==> octal = 10
    // octal = nbre;
    // rest = nbre % 8;
    // if (rest == 0) octal = (nbre / 8) * 10;
    // else octal = (nbre / 8) * 10 + rest;
    // printf("octal = %d \n", octal);

    //! decimal = 10 ==> hexa = A
    // ASCII: 65 = A --> ... --> 70 = F & 48 = 0
    int quotion = nbre, j = 0;
    while (quotion != 0)
    {
        rest = quotion % 16;
        if (rest < 10)
            hexa[j++] = 48 + rest;
        else
            hexa[j++] = 55 + rest;

        quotion = quotion / 16;
    }
    printf("hexadecimal = ");
    for (int i = j; i >= 0; i--)
    {
        printf("%c", hexa[i]);
    }

    printf("\n");
    return 0;
}
