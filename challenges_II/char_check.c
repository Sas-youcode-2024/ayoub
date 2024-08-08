#include <stdio.h>

int main()
{
    char charactere;
    printf("enter a charactere: ");
    scanf(" %c", &charactere);

    if (charactere >= 65 && charactere <= 90)
        printf("'%c' is a charactere and it's majuscule \n", charactere);
    else if (charactere >= 97 && charactere <= 122)
        printf("'%c' is a charactere and it's miniscule \n", charactere);
    else
        printf("'%c' not a charactere \n", charactere);

    printf("\n");
    return 0;
}