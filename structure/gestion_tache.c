#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 255

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct{
    int code;
    char nom[25];
    char description[MAX_LENGTH];
}Tache;

Tache *tache = NULL;
int size = 0;

void afficher(){
    system("clear");
    if(size == 0){
        printf("non taches availible pour afficher..\n");
        return;
    }
    for(int i=0; i<size; i++){
        printf("code: %d, nom: '%s', description: '%s'.\n", tache[i].code, tache[i].nom, tache[i].description);
    }
}

void ajouter(){
    system("clear");
    int nbre;
    printf("combien de tache voulez-vous ajouter? ");
    scanf("%d", &nbre);

    tache = realloc(tache, (nbre + size) * sizeof(Tache));
    size = size + nbre;

    for(int i=0; i<nbre; i++){
        printf("entrer les infos du tache.\n");
        printf("code: "); scanf("%d", &tache[size - nbre + i].code);
        printf("nom: "); getchar(); fgets(tache[size - nbre + i].nom, 25, stdin);
        tache[size - nbre + i].nom[strcspn(tache[size - nbre + i].nom, "\n")] = 0;

        printf("description: "); fgets(tache[size - nbre + i].description, MAX_LENGTH, stdin);
        tache[size - nbre + i].description[strcspn(tache[size - nbre + i].description, "\n")] = 0;

        printf("nouvelle tache ajoutee avec succes sous le nom '%s'..\n", tache[size - nbre + i].nom);
    }
}

void supprimer(){
    system("clear");
    int code, position = -1;
    printf("entrer le code du tache a supprimer: ");
    scanf("%d", &code);

    for(int i=0; i<size; i++){
        if(tache[i].code == code){
            position = i;
        }
    }
    if(position == -1){
        printf("tache n'a pas trouver..\n");
        return;
    }
    // 1 3 5 4 6 45 54 23
    for(int i=position; i<size; i++){
        tache[i] = tache[i+1];
    }
    size = size - 1;
    printf("tache avec le code %d est supprimèe..\n", code);
}

void modifier(){
    system("clear");
    int code, position = -1;
    printf("entrer le code du tache a modifier: ");
    scanf("%d", &code);

    for(int i=0; i<size; i++){
        if(tache[i].code == code){
            position = i;
        }
    }
    if(position == -1){
        printf("tache n'a pas trouver..\n");
        return;
    }
    printf("tache: %d\n", tache[position].code);
    printf("nom: '%s', description: '%s'\n", tache[position].nom, tache[position].description);

    printf("Entrer un nouveau nom: "); getchar(); fgets(tache[position].nom, 25, stdin);
    tache[position].nom[strcspn(tache[position].nom, "\n")] = 0;
    
    printf("Entrer une nouvelle description: "); fgets(tache[position].description, MAX_LENGTH, stdin);
    tache[position].description[strcspn(tache[position].description, "\n")] = 0;

    printf("tache avec le code %d est modifièe..\n", code);
}

int main(){
    int choice;
    do{
        printf("======================================\n");
        printf("=======     Menu principale    =======\n");
        printf("======================================\n");
        printf("1- afficher les taches \n");
        printf("2- ajouter une tache \n");
        printf("3- supprimer une tache \n");
        printf("4- modifier une tache \n");
        printf("5- sortir... \n");
        printf("======================================\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: afficher(); break;
            case 2: ajouter(); break;
            case 3: supprimer(); break;
            case 4: modifier(); break;
            case 5: 
                printf("======================================\n"); 
                printf("===========    au revoir   ===========\n"); 
                printf("======================================\n"); 
                break;
        }
    }
    while(choice >= 1 && choice <= 4);

    printf("\n");
    return 0;
}