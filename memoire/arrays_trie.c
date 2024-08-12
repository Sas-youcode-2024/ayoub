#include <stdio.h>
#include <stdlib.h>

void croissant(int *tab, int taille)
{
    int tmp;
    for (int i = 0; i < taille; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (*(tab + i) > *(tab + j))
            {
                tmp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = tmp;
            }
        }
    }
    printf("trie en ordre croissant: ");
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}
void decroissant(int *tab, int taille)
{
    int tmp;
    for (int i = 0; i < taille; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (*(tab + i) < *(tab + j))
            {
                tmp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = tmp;
            }
        }
    }
    printf("trie en ordre decroissant: ");
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

int main()
{
    int taille;
    printf("donner le nombre d'element pour inserer: ");
    scanf("%d", &taille);

    int *tab = malloc(taille * sizeof(int));
    printf("remplir le tableau: \n");
    for (int i = 0; i < taille; i++)
    {
        scanf("%d", (tab + i));
    }

    croissant(tab, taille);
    decroissant(tab, taille);

    printf("\n");
    return 0;
}