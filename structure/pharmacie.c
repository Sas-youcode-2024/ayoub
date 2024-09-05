// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct {
//     int code;
//     char nom[25];
//     int quantite;
//     float prix;
// }Produit;

// Produit *produit = NULL;
// int count = 0;

// // TODO ==> 

// // ajouter un ou plusieur produits
// void ajouterProduit() {
//     system("clear");
//     printf("------------------------------------------------------\n\n");
//     printf("           Ajouter un ou plusieurs produits           \n\n");
//     printf("------------------------------------------------------\n");
//     int nbre;
//     printf("Combien de produit voulez-vous ajoutez? ");
//     scanf("%d", &nbre);

//     produit = realloc(produit, (nbre + count) * sizeof(Produit));
//     if(produit == NULL){
//         printf("erreur allocation du memoire..");
//         return;
//     }
//     count += nbre;
//     for(int i=0; i<nbre; i++){
//         printf("entrer les informations de produit.\n");
//         printf("code: "); scanf("%d", &produit[count - nbre + i].code);

//         printf("nom: "); getchar(); fgets(produit[count - nbre + i].nom, 25, stdin);
//         produit[count - nbre + i].nom[strcspn(produit[count - nbre + i].nom, "\n")] = 0;

//         printf("quantite: "); scanf("%d", &produit[count - nbre + i].quantite);

//         printf("prix: "); scanf("%f", &produit[count - nbre + i].prix);
//         printf("un nouveau produit est ajoutèe sous le nom '%s' avec succes.\n", produit[count - nbre + i].nom);
//     }

// }

// // rechercher produit par: code, Quantite, etate de stock(quantite < 3),
// void rechercherProduitParCode() {

// }
// void rechercherProduit() {
//     system("clear");
//     printf("------------------------------------------------------\n\n");
//     printf("               rechercher des produits                \n\n");
//     printf("------------------------------------------------------\n");
//     int choice;
//     printf("1- rechercher produits par code\n");
//     printf("2- rechercher produits par quantite\n");
//     printf("3- rechercher produits par etat de stock\n");
//     printf("------------------------------------------------------\n");
//     scanf("%d", &choice);
//     printf("------------------------------------------------------\n");

//     switch(choice){
//         case 1: rechercherProduitParCode(); break;
//         case 2: break;
//         case 3: break;
//         default: break;
//     }

    
// }

// // allimenter la quantite d'un produit, par code de produit

// // supprimer un produit par: Code, state de vente
// void supprimerProduitParCode(){
//     int code, index = -1;
//     printf("------------------------------------------------------\n");
//     printf("entrer le code de produit a supprimer: ");
//     scanf("%d", &code);
//     printf("------------------------------------------------------\n");
//     for(int i=0; i<count; i++){
//         if(produit[i].code == code){
//             index = i;
//             break;
//         }
//     }
//     if(index == -1){
//         printf("produit avec le code %d n'exist pas..\n", code);
//         return;
//     }
//     for(int i=index; i<count; i++){
//         produit[i] = produit[i + 1];
//     }
//     count = count - 1;
//     printf("Produit supprimee avec succes..\n");

// }
// void supprimerProduitParStatusDeVente(){
//     // TODO ==> I need to understand this func more
//     system("clear");
//     printf("------------------------------------------------------\n");
//     printf("                     comming soon                     ");
//     printf("------------------------------------------------------\n");

// }
// void supprimerProduit() {
//     system("clear");
//     printf("------------------------------------------------------\n\n");
//     printf("                  supprimer produit                   \n\n");
//     printf("------------------------------------------------------\n");
//     if(count == 0){
//         printf("Aucun produits pour le supprimer maintenant..\n");
//         return;
//     }
//     int choice;
//     printf("1- supprimer produit par code\n");
//     printf("2- supprimer produit par status de vente\n");
//     scanf("%d", &choice);
//     switch(choice){
//         case 1: supprimerProduitParCode(); break;;
//         case 2: supprimerProduitParStatusDeVente(); break;
//         default: return;
//     }

// }

// // lister les produits en ordre:
// // croissant par nom
// void listerProduitParNomCroissant() {
//     Produit *tmp;
//     tmp = malloc(count * sizeof(Produit));

//     for(int i=0; i<count; i++){
//         for(int j=i+1; j<count; j++){
//             if(strcmp(produit[j].nom, produit[i].nom) < 0){
//                 *tmp = produit[i];
//                 produit[i] = produit[j];
//                 produit[j] = *tmp;
//             }
//         }
//     }
// }
// // decroissant par prix
// void listerProduitParPrixDecroissant() {
//     Produit *tmp;
//     tmp = malloc(count * sizeof(Produit));

//     for(int i=0; i<count; i++){
//         for(int j=i+1; j<count; j++){
//             if(produit[j].prix > produit[i].prix){
//                 *tmp = produit[i];
//                 produit[i] = produit[j];
//                 produit[j] = *tmp;
//             }
//         }
//     }
// }
// // normal listing
// void listerProduitNormal() {
//     Produit *tmp;
//     tmp = malloc(count * sizeof(Produit));

//     for(int i=0; i<count; i++){
//         for(int j=i+1; j<count; j++){
//             if(produit[j].code < produit[i].code){
//                 *tmp = produit[i];
//                 produit[i] = produit[j];
//                 produit[j] = *tmp;
//             }
//         }
//     }
// }
// // function which list products
// void listerProduit() {
//     system("clear");
//     printf("------------------------------------------------------\n\n");
//     printf("                  Affichage produits                  \n\n");
//     printf("------------------------------------------------------\n");
//     if(count == 0){
//         printf("Aucun produits pour l'afficher maintenant..\n");
//         return;
//     }
//     int choice;
//     printf("1- lister les produits en ordre croissant par nom\n");
//     printf("2- lister les produits en ordre decroissant par prix\n");
//     printf("3- lister les produits sans ordre\n");
//     scanf("%d", &choice);
//     printf("------------------------------------------------------\n");
//     if(choice == 1) listerProduitParNomCroissant();
//     else if(choice == 2) listerProduitParPrixDecroissant();
//     else if(choice == 3) listerProduitNormal();
//     printf("CODE     NOM                      QUANTITE   PRIX\n");
//     for(int i=0; i<count; i++){
//         printf("%-8d %-24s %-10d %.2f\n", produit[i].code, produit[i].nom, produit[i].quantite, produit[i].prix);
//     }
//     printf("------------------------------------------------------\n");
// }

// // afficher le total de produits vendus dans un date donnee
// // afficher la moyenne de prix de produits vendus dans un date donnee
// // afficher le maximun de prix de produits vendus dans un date donnee
// // afficher le minimum de prix de produits vendus dans un date donnee
// // decrementer la quantite de produit apres l'achat 

// void menu(){
//     int choice;
//     do{
//         // system("clear");
//         printf("------------------------------------------------------\n\n");
//         printf("                 gestion de pharmacie                 \n\n");
//         printf("------------------------------------------------------\n");
//         printf("1- afficher produit\n");
//         printf("2- ajouter produit\n");
//         printf("3- rechercher produit\n");
//         printf("4- supprimer produit\n");
//         printf("5- lister produits\n");
//         printf("6- acheter produit\n");
//         printf("7- sortir...\n");
//         printf("------------------------------------------------------\n\n");
//         scanf("%d", &choice);
//         printf("\n");

//         switch(choice){
//             case 1: listerProduit(); break;
//             case 2: ajouterProduit(); break;
//             case 3: rechercherProduit(); break;
//             case 4: supprimerProduit(); break;
//             // case 5: afficher(); break;
//             // case 6: acheterProduit(); break;
//             default: 
//                 printf("------------------------------------------------------\n");
//                 printf("                 Merci pour votre visit               \n");
//                 printf("------------------------------------------------------\n");
//                 break;
//         }

//     }while(choice >= 1 && choice <= 6);
// }

// int main(){
//     menu();
//     free(produit);

//     printf("\n");
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100

typedef struct {
    char code[10];
    char nom[50];
    int quantite;
    float prix;
    float prix_ttc;
    time_t date_achat;
} Produit;

Produit produits[MAX_PRODUCTS];
int nombre_produits = 0;

void ajouter_produit() {
    system("clear");
    if (nombre_produits >= MAX_PRODUCTS) {
        printf("Stock plein ! Impossible d'ajouter de nouveaux produits.\n");
        return;
    }

    Produit p;
    printf("Entrez le code du produit: ");
    scanf("%s", p.code);
    printf("Entrez le nom du produit: ");
    scanf("%s", p.nom);
    printf("Entrez la quantite du produit: ");
    scanf("%d", &p.quantite);
    printf("Entrez le prix du produit: ");
    scanf("%f", &p.prix);

    p.prix_ttc = p.prix + (p.prix * 0.15); // Calcul du prix TTC
    produits[nombre_produits++] = p;

    printf("Produit ajoute avec succes !\n");
}

void lister_produits() {
    system("clear");
    if (nombre_produits == 0) {
        printf("Aucun produit disponible.\n");
        return;
    }

    printf("Liste des produits :\n");
    for (int i = 0; i < nombre_produits; i++) {
        printf("Code: %s, Nom: %s, Quantite: %d, Prix: %.2f, Prix TTC: %.2f\n",
               produits[i].code, produits[i].nom, produits[i].quantite, produits[i].prix, produits[i].prix_ttc);
    }
}

void acheter_produit() {
    system("clear");
    char code[10];
    int quantite;

    printf("Entrez le code du produit a acheter: ");
    scanf("%s", code);
    printf("Entrez la quantite achetee: ");
    scanf("%d", &quantite);

    for (int i = 0; i < nombre_produits; i++) {
        if (strcmp(produits[i].code, code) == 0) {
            if (produits[i].quantite >= quantite) {
                produits[i].quantite -= quantite;
                produits[i].date_achat = time(NULL);
                printf("Produit achete avec succes !\n");
            } else {
                printf("Quantite insuffisante en stock.\n");
            }
            return;
        }
    }
    printf("Produit non trouve.\n");
}

void rechercher_par_code() {
    system("clear");
    char code[10];
    printf("Entrez le code du produit a rechercher: ");
    scanf("%s", code);

    for (int i = 0; i < nombre_produits; i++) {
        if (strcmp(produits[i].code, code) == 0) {
            printf("Produit trouve : Code: %s, Nom: %s, Quantite: %d, Prix: %.2f, Prix TTC: %.2f\n",
                   produits[i].code, produits[i].nom, produits[i].quantite, produits[i].prix, produits[i].prix_ttc);
            return;
        }
    }
    printf("Produit non trouve.\n");
}

void afficher_statistiques() {
    system("clear");
    float total = 0, max = 0, min = 1e9, moyenne = 0;
    int nombre_vendus = 0;

    for (int i = 0; i < nombre_produits; i++) {
        if (produits[i].date_achat != 0) {  // Vérifier si le produit a été acheté
            float prix_ttc = produits[i].prix_ttc;
            total += prix_ttc;
            nombre_vendus++;
            if (prix_ttc > max) max = prix_ttc;
            if (prix_ttc < min) min = prix_ttc;
        }
    }

    if (nombre_vendus > 0) {
        moyenne = total / nombre_vendus;
        printf("Total des prix vendus: %.2f\n", total);
        printf("Moyenne des prix vendus: %.2f\n", moyenne);
        printf("Max des prix vendus: %.2f\n", max);
        printf("Min des prix vendus: %.2f\n", min);
    } else {
        printf("Aucun produit vendu pour l'instant.\n");
    }
}

void menu() {
    int choix;
    do {
        printf("\n--- Menu de gestion de pharmacie ---\n");
        printf("1. Ajouter un nouveau produit\n");
        printf("2. Lister les produits\n");
        printf("3. Acheter un produit\n");
        printf("4. Rechercher un produit par code\n");
        printf("5. Afficher les statistiques de vente\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_produit();
                break;
            case 2:
                lister_produits();
                break;
            case 3:
                acheter_produit();
                break;
            case 4:
                rechercher_par_code();
                break;
            case 5:
                afficher_statistiques();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

int main() {
    menu();
    return 0;
}
