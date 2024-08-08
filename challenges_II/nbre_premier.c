#include <stdio.h>

int main()
{
    int nbre;
    printf("enter a number: ");
    scanf("%d", &nbre);

    int tmp = 0;

    for (int i = 2; i < nbre; i++)
    {
        if (nbre % i == 0)
        {
            tmp++;
            break;
        }
    }
    if (tmp == 0)
        printf("%d is a premier\n", nbre);
    else
        printf("%d is not a premier\n", nbre);

    printf("\n");
    return 0;
}