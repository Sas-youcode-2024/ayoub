#include <stdio.h>
#include <stdlib.h>

int main(){
    int taille;
    printf("entrer le nombre des elements: ");
    scanf("%d", &taille);
    int *tab = malloc(taille * sizeof(int));

    for(int i=0; i<taille; i++){
        printf("tab[%d]= ", i+1);
        scanf("%d", tab+i);
    }

    int min = *tab;
    for(int i=1; i<taille; i++){
        if(min > *(tab + i)){
            min = *(tab + i);
        }
    }
    printf("la valeur plus petite est %d", min);

    printf("\n");
    return 0;

}
