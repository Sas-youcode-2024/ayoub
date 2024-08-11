#include <stdio.h>

int main()
{
    // you can request user to enter the values of array by himself
    int tab[10] = {1, 32, 1, 4, 2, 43, 2, 0, 11, 99};
    int *p1 = tab, *p2 = tab;
    int x;
    printf("donner un nombre x: ");
    scanf("%d", &x);

    for (p1 = tab; p1 < tab + 10; p1++){
        *p2 = *p1;
        if (*p1 != x){
            p2++;
        }
    }

    printf("\napres la supression du nombre '%d': ", x);
    for (p1 = tab; p1 < p2; p1++){
        printf("%d ", *p1);
    }

    printf("\n");
    return 0;
}