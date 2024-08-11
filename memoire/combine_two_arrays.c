#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A, *B;
    int n, m, i, j;

    // remplir les elements de tableau A
    printf("donner la taille du tableau A: ");
    scanf("%d", &m);
    A = malloc(m * sizeof(int));
    printf("remplir le tableau: \n");
    for(i = 0; i < m; i++){
        scanf("%d", A + i);
    }
    printf("\n");
    // remplir les elements de tableau B
    printf("donner la taille du tableau B: ");
    scanf("%d", &n);
    B = malloc(n * sizeof(int));
    printf("remplir le tableau: \n");
    for(i = 0; i < n; i++){
        scanf("%d", B + i);
    }
    A = realloc(A, n * sizeof(int));
    for(i = m, j = 0; i < (m + n); i++, j++){
        *(A + i) = *(B + j);
    }

    printf("\napres la combinaison de A et B: ");
    for(i = 0; i < (m + n); i++){
        printf("%d ", *(A + i));
    }


    printf("\n");
    return 0;
}