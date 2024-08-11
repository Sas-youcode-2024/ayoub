#include <stdio.h>
#include <stdlib.h>

int main(){
    int taille, taille2;
    printf("entrer la taille de tableau: ");
    scanf("%d", &taille);
    int *tab = malloc(taille * sizeof(int));
    if(tab == NULL){
        printf("memoire suffisant!");
        return 0;
    } 
    else {
        int somme = 0;
        // remplissage de tableau
        printf("remplir le tableau: \n");
        for(int i=0; i<taille; i++){
            printf("Note%d ", i+1);
            scanf("%d", (tab+i));
            somme += *(tab+i);
        }
        printf("la moyenne c'est %.2f\n", (float) (somme / taille));

        AGAIN:
        char again;
        printf("voulez-vous repeter encore une autre fois (y/n): ");
        scanf(" %c", &again);
        if(again == 'y'){
            printf("combien de notes voulez-vous ajouter? ");
            scanf("%d", &taille2);
            tab = realloc(tab, (taille + taille2) * sizeof(int));

            for(int i=0; i<taille; i++){
                printf("Note%d %d\n", i+1, *(tab + i));
            }
            for(int i=taille; i<taille + taille2; i++){
                printf("Note%d ", i+1);
                scanf("%d", (tab+i));
                somme += *(tab+i);
            }
            printf("la nouvelle moyenne c'est %.2f\n", (float) (somme / (taille + taille2)));
            taille = taille + taille2;
            goto AGAIN;
        }
        else {
            printf("\nMerci de votre visit\n");
            return 0;
        }

    }

    printf("\n");
    return 0;
}