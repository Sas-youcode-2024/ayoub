#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[10];
    char nom[25];
    int quantite;
    float prix;
} Produit;

void menu(){
    int choice;
    do{
        printf("\n**********************************************************\n");
        printf("                     menu principale                      \n");
        printf("**********************************************************\n");
        printf("1- ajouter un ou plusieurs produits\n");
        printf("2- afficher les produits\n");
        printf("3- rechercher un produit\n");
        printf("4- supprimer produit\n");
        printf("0- quitter\n");
        printf("**********************************************************\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: ajouterProduit(); break;
            case 2: afficherProduits(); break;
            case 3: rechercherProduit(); break;
            case 4: supprimerProduit(); break;
            case 0: 
                printf("**********************************************************\n");
                printf("                 tu es quitter le programme               \n");
                printf("**********************************************************\n");
                break;
            default: 
                printf("choisit un choix valid..\n");
                break;
        }

    }while(choice <= 5);
}


int main(){
    menu();
    // free(produits);

    printf("\n");
    return 0;
}