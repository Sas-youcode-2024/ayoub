#include <stdio.h>

int main()
{
    int tab[10] = {1, 32, 3, 4, 20, 43, 12, 0, 11, 99};
    int *p1 = tab, *p2 = tab + 9, tmp;

    for(p1 = tab; p1 < tab + 5; p1++){
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p2--;
    }

    printf("l'inverse c'est: ");
    for(p1 = tab; p1 < tab + 10; p1++){
        printf("%d ", *p1);
    }
    


    printf("\n");
    return 0;
}