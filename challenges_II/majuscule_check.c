#include <stdio.h>

int main()
{
    char charactere;
    printf("enter a charactere: ");
    scanf(" %c", &charactere);

    if (charactere <= 90 && charactere >= 65)
        printf("%c is majuscule", charactere);
    else
        printf("%c is minuscule", charactere);

    printf("\n");
    return 0;
}