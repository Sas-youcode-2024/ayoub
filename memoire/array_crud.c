#include <stdio.h>
#include <stdlib.h>

void add(int *tab, int *taille){
    int new_taille;
    printf("combien des elements voulez-vous ajouter? ");
    scanf("%d", &new_taille);
    tab = realloc(tab, new_taille * sizeof(int));

    printf("ajouter votre nouveau elements: \n");
    for(int i=*taille; i<(new_taille + *taille); i++){
        scanf("%d", tab+i);
    }
    *taille = *taille + new_taille;
    printf("votre element a ete ajoutee avec succes.\n");

}
void delete(int *tab, int *taille){
    int pos;
    printf("quelle est la position voulez-vous supprimer? ");
    scanf("%d", &pos);
    
    if(pos < 1 || pos > *taille){
        printf("cette position n'a pas valide.\n");
    }
    else{
        for(int i=pos-1; i<*taille; i++){
            *(tab+i) = *(tab+i+1);
        }
        *taille = *taille - 1;
        printf("element supprimee avec succes.\n");
    }

}
void update(int *tab, int *taille){
    int pos;
    printf("quelle est le position voulez-vous changer? ");
    scanf("%d", &pos);

    if(pos < 1 || pos > *taille){
        printf("cette position n'a pas valide.\n");
    }
    else{
        int value;
        printf("entrer la nouvelle valeur: ");
        scanf("%d", &value);
        *(tab+pos-1) = value;
        printf("element changee avec succes.\n");
    }

}
void search(int *tab, int *taille){
    int pos;
    printf("quelle est le position voulez-vous chercher? ");
    scanf("%d", &pos);

    if(pos < 1 || pos > *taille){
        printf("cette position n'a pas valide.\n");
    }
    else{
        printf("l'element dans la position %d est: %d\n", pos, *(tab+pos-1));
    }

}
void affiche(int *tab, int *taille){
    printf("les element de votre tableau: ");
    for(int i=0; i<*taille; i++){
        printf("%d ", *(tab+i));
    }
    printf("\n");
}

int main(){
    int taille;
    printf("donner le nombre d'elements a inserer: ");
    scanf("%d", &taille);

    int *tab = malloc(taille * sizeof(int));
    printf("remplir le tableau: \n");
    for(int i=0; i<taille; i++){
        scanf("%d", (tab+i));
    }

    int reply;
    do{
        printf("\n\n*************************************\n");
        printf("*          menu principale          *\n");
        printf("*************************************\n");
        printf("******** 1- ajouter elements ********\n");
        printf("******** 2- updater element *********\n");
        printf("******** 3- supprimer element *******\n");
        printf("******** 4- chercher element ********\n");
        printf("******** 5- afficher elements *******\n");
        printf("******** 6- quiter ******************\n");
        printf("*************************************\n\n");
        scanf("%d", &reply);

        switch(reply){
            case 1: add(tab, &taille); break;
            case 2: update(tab, &taille); break;
            case 3: delete(tab, &taille); break;
            case 4: search(tab, &taille); break;
            case 5: affiche(tab, &taille); break;
            default: printf("Merci pour votre visit.\n"); return 0;
        }

    }while(reply >= 1 && reply <= 5);

    printf("\n");
    return 0;
}