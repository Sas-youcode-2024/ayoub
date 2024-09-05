#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int code;
    char nom[25];
    int quantite;
    float prix;
}Produit;

typedef struct {
    int code;
    char nom[25];
    int quantite;
    float prix;
    __time_t date;
}Vente;

Produit *produit = NULL;
int count = 0;

Vente *ventes = NULL;
int nbre_vents = 0;

void ajouterProduit(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                    AJOUTER PRODUIT                  \n");
    printf("-----------------------------------------------------\n");
    int nbre;
    printf("combien de produit voulez-vous ajouter? ");
    scanf("%d", &nbre);
    printf("-----------------------------------------------------\n");
    produit = realloc(produit, (count + nbre) * sizeof(Produit));
    if(produit == NULL){
        printf("erreur en allocation de memoire..\n");
        return;
    }
    count += nbre;
    for(int i=0; i<nbre; i++){
        printf("entrer les informations de produit.\n");
        printf("code: "); scanf("%d", &produit[count - nbre + i].code);
        printf("nom: "); getchar(); fgets(produit[count - nbre + i].nom, 25, stdin);
        produit[count - nbre + i].nom[strcspn(produit[count - nbre + i].nom, "\n")] = 0;
        printf("quantite: "); scanf("%d", &produit[count - nbre + i].quantite);
        printf("prix: "); scanf("%f", &produit[count - nbre + i].prix);

        printf("nouveau produit ajoutee sous le nom '%s' avec succes..\n", produit[count - nbre + i].nom);
    }


}

void afficherProduits(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                  AFFICHER PRODUITS                  \n");
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    }
    printf("CODE     NOM                  QUANTITE     PRIX\n");
    for(int i=0; i<count; i++){
        printf("%-8d %-20s %-12d %.2f\n", produit[i].code, produit[i].nom, produit[i].quantite, produit[i].prix);
    }
    printf("-----------------------------------------------------\n");

}

void modifierProduit(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                  MODIFIER PRODUITS                  \n");
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    }
    int code, index = -1;
    printf("Entrer le code de produit a modifier: "); scanf("%d", &code);
    for(int i=0; i<count; i++){
        if(produit[i].code == code){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("produit ne pas trouver..\n");
        return;
    }
    int choice;
    printf("-----------------------------------------------------\n");
    printf("1- modifier le nom de produit\n");
    printf("2- modifier le prix de produit\n");
    printf("3- modifier la quantite de produit\n");
    printf("4- modifier tous les informations\n");
    printf("-----------------------------------------------------\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Entrer le nouceau nom; ");
            getchar(); fgets(produit[index].nom, 25, stdin);
            produit[index].nom[strcspn(produit[index].nom, "\n")] = 0;
            printf("nom changee avec succes\n");
            break;
        case 2:
            printf("Entrer le nouveau prix: ");
            scanf("%f", &produit[index].prix);
            printf("Prix changee avec succes\n");
            break;
        case 3:
            printf("Entrer la nouveau quantite: ");
            scanf("%d", &produit[index].quantite);
            printf("quantite changee avec succes\n");
            break;
        case 4: 
            printf("Entrer le nouceau nom; ");
            getchar(); fgets(produit[index].nom, 25, stdin);
            produit[index].nom[strcspn(produit[index].nom, "\n")] = 0;
            printf("Entrer le nouveau prix: ");
            scanf("%f", &produit[index].prix);
            printf("Entrer la nouveau quantite: ");
            scanf("%d", &produit[index].quantite);
            printf("information de produit changee avec succes\n");
            break;
        default: 
            printf("choisir un choix dans le menu..\n");
            break;
    }

}

void supprimerProduit(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                 SUPPRIMER PRODUITS                  \n");
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    }
    int code, position = -1;
    printf("Entrer le code de produit a supprimer: ");
    scanf("%d", &code);

    for(int i=0; i<count; i++){
        if(produit[i].code == code){
            position = i;
            break;
        }
    }
    if(position == -1){
        printf("produit ne pas trouver..\n");
        return;
    }
    for(int i=position; i<count; i++){
        produit[i] = produit[i + 1];
    }
    count = count - 1;
    printf("un produit a ete supprimee..\n");
    return;

}

void enregistrerVente(int code, int quantite, const char *nom, float prix){
    nbre_vents += 1;
    ventes = realloc(ventes, nbre_vents * sizeof(Vente));
    ventes[nbre_vents - 1].code = code;
    ventes[nbre_vents - 1].quantite = quantite;

    strncpy(ventes[nbre_vents - 1].nom, nom, sizeof(ventes[nbre_vents - 1].nom) - 1);
    ventes[nbre_vents - 1].nom[sizeof(ventes[nbre_vents - 1].nom) - 1] = '\0';

    ventes[nbre_vents - 1].prix = prix;
    ventes[nbre_vents - 1].date = time(NULL);

    FILE *file = fopen("ventes.txt", "a");
    if(file == NULL){
        printf("erreur d'ouvrir le fichier..\n");
        return;
    }
    else{
        fprintf(file, "%d | %s | %d | %.2f | %ld\n", code, nom, quantite, prix, ventes[nbre_vents - 1].date);
    }
    
    fclose(file);
}

void acheterProduit(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                   ACHETER PRODUITS                  \n");
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    }
    int code, position = -1;
    printf("entrer le code de produit a acheter: ");
    scanf("%d", &code);
    for(int i=0; i<count; i++){
        if(produit[i].code == code){
            position = i;
            break;
        }
    }
    if(position == -1){
        printf("produit ne pas trouvez..\n");
        return;
    }
    int quantite;
    printf("entrer la quantite de produit (%s, %.2f $): ", produit[position].nom, produit[position].prix);
    scanf("%d", &quantite);
    if(quantite > produit[position].quantite){
        printf("%d pieces disponible dans stock..\n", produit[position].quantite);
        printf("en plus tu vas les achetees forcement.\n");
        quantite = produit[position].quantite;
    }
    produit[position].quantite = produit[position].quantite - quantite;
    printf("-----------------------------------------------------\n");
    printf("tu as achete %d pieces de produit '%s' avec le prix: %.2f\n", quantite, produit[position].nom, produit[position].prix);
    printf("le prix total: %.2f $\n", (double) (quantite * produit[position].prix));

    enregistrerVente(produit[position].code, quantite, produit[position].nom, produit[position].prix);


}

void statDeVentes(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("               STATISTIQUES DE VENTES                \n");
    printf("-----------------------------------------------------\n");

    if(nbre_vents == 0){
        printf("Aucun produit vendu pour l'instant...\n");
        return;
    }
    float maxPrix = 0, minPrix = ventes[0].prix, moyenneProduitsVendus = 0;
    int totalProduitsVendus = 0;

    for(int i=0; i<nbre_vents; i++){
        if(ventes[i].prix > maxPrix){
            maxPrix = ventes[i].prix;
        }
        if(ventes[i].prix < minPrix){
            minPrix = ventes[i].prix;
        }
    }

    printf("maximum des prix vendus: %.2f\n", maxPrix);
    printf("minimum des prix vendus: %.2f\n", minPrix);

    
    printf("-----------------------------------------------------\n");

}

void RchParCode(){
    int code, index = -1;
    printf("entrer le code de produit: ");
    scanf("%d", &code);
    for(int i=0; i<count; i++){
        if(produit[i].code == code){
            index = i;
            break;
        }
    }
    if(index != -1){
        printf("-----------------------------------------------------\n");
        printf("CODE     NOM                  QUANTITE     PRIX\n");
        printf("%-8d %-20s %-12d %.2f\n", produit[index].code, produit[index].nom, produit[index].quantite, produit[index].prix);
    }else {
        printf("Produit ne pas trouver..\n");
    }
}
void RchParQuantite(){
    int quantite, index = -1;
    printf("entrer la quantite de produit: ");
    scanf("%d", &quantite);
    printf("-----------------------------------------------------\n");
    printf("CODE     NOM                  QUANTITE     PRIX\n");
    for(int i=0; i<count; i++){
        if(produit[i].quantite == quantite){
            printf("%-8d %-20s %-12d %.2f\n", produit[i].code, produit[i].nom, produit[i].quantite, produit[i].prix);
            index = 0;
        }
    }
    if(index == -1) printf("Produit ne pas trouver..\n");
}
void RchParEtatDeStock(){
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    }
    printf("Les produit du quantite inferieure à 3: \n");
    printf("CODE     NOM                  QUANTITE     PRIX\n");
    for(int i=0; i<count; i++){
        if(produit[i].quantite <= 3){
            printf("%-8d %-20s %-12d %.2f\n", produit[i].code, produit[i].nom, produit[i].quantite, produit[i].prix);
        }
    }
}

void rechercherProduit(){
    system("clear");
    printf("-----------------------------------------------------\n");
    printf("                 RECHERCHER PRODUIT                  \n");
    printf("-----------------------------------------------------\n");
    if(count == 0){
        printf("non produit availible pour afficher actuellement\n");
        return;
    } 
    printf("1- rechercher par code \n");
    printf("2- rechercher par quantite \n");
    printf("3- rechercher par etat de stock \n");
    printf("-----------------------------------------------------\n");
    int choice;
    scanf("%d", &choice);
    printf("-----------------------------------------------------\n");
    do{
        switch(choice){
            case 1: RchParCode(); break;
            case 2: RchParQuantite(); break;
            case 3: RchParEtatDeStock(); break;
            default: 
                printf("-----------------------------------------------------\n");
                printf("Choisit un choix parmi les choix de menu !\n");
                printf("-----------------------------------------------------\n");
                break;
        }
    }
    while(choice > 3 || choice < 1);
}

void enregistrerProduits(){
    system("clear");
    FILE *file;
    file = fopen("produits.txt", "w");
    if(file == NULL){
        printf("erreur dans l'ouverture de fichier..\n");
        return;
    }
    else{
        for(int i=0; i<count; i++){
            fprintf(file, "%d | %s | %d | %.2f\n", produit[i].code, produit[i].nom, produit[i].quantite, produit[i].prix );
        }
    }
    fclose(file);
}

void chargerProduits(){
    system("clear");
    FILE *file;
    file = fopen("produits.txt", "r");
    int i = 0, capacity = 1;
    if(file == NULL){
        printf("erreur dans l'ouverture de fichier..\n");
        return;
    }
    else{
        produit = realloc(produit, capacity * sizeof(Produit));
        if(produit == NULL){
            printf("erreur allocation memoire..\n");
            return;
        }
        while(!feof(file)){
            fscanf(file, "%d | %[^|] | %d | %f\n", &produit[i].code, produit[i].nom, &produit[i].quantite, &produit[i].prix );
            i++;
            if(i >= capacity){
                capacity = capacity + 1;
                produit = realloc(produit, capacity * sizeof(Produit));
                if(produit == NULL){
                    printf("erreur allocation memoire..\n");
                    fclose(file);
                    return;
                }
            }
        }
    }
    count = i;
    printf("%d produits a ete chargèe avec succes..\n", count);
    fclose(file);

    FILE *file2 = fopen("ventes.txt", "r");
    if(file2 == NULL){
        printf("erreur allocation memoire..\n");
        return;
    }
    else {
        int capacity = 1, i = 0;
        ventes = realloc(ventes, capacity * sizeof(Vente));
        if(ventes == NULL){
            printf("erreur allocation memoire..\n");
            return;
        }
        while(!feof(file2)){
            fscanf(file2, "%d | %[^|] | %d | %f | %ld\n", &ventes[i].code, ventes[i].nom, &ventes[i].quantite, &ventes[i].prix, &ventes[i].date);
            i++;
            if(i >= capacity){
                capacity = capacity + 1;
                ventes = realloc(ventes, capacity * sizeof(Vente));
                if(ventes == NULL){
                    printf("erreur allocation memoire..\n");
                    fclose(file2);
                    return;
                }
            }
        }     
    }
    nbre_vents = i;

}

int main(){
    int choice;
    do{
        printf("-----------------------------------------------------\n");
        printf("                GESTION DE PHARMACIE                 \n");
        printf("-----------------------------------------------------\n");
        printf("1- ajouter produit \n");
        printf("2- afficher produits \n");
        printf("3- modifier produit ou allimenter le stock \n");
        printf("4- supprimer produit \n");
        printf("5- acheter produit \n");
        printf("6- statistiques de ventes \n");
        printf("7- rechercher produit \n");
        printf("8- enregistrer les produits \n");
        printf("9- charger les produits \n");
        printf("0- quitter \n");
        printf("-----------------------------------------------------\n");
        printf("entrer votre choix: ");
        scanf("%d", &choice);
        printf("-----------------------------------------------------\n");

        switch(choice){
            case 0: 
                system("clear");
                printf("Merci pour votre visite..\n"); 
                printf("-----------------------------------------------------\n");
                break;
            case 1: ajouterProduit(); break;
            case 2: afficherProduits(); break;
            case 3: modifierProduit(); break;
            case 4: supprimerProduit(); break;
            case 5: acheterProduit(); break;
            case 6: statDeVentes(); break;
            case 7: rechercherProduit(); break;
            case 8: enregistrerProduits(); break;
            case 9: chargerProduits(); break;
            default: 
                system("clear");
                printf("choix ne pas trouver dans menu, repeter..\n");
                printf("-----------------------------------------------------\n");
                break;
        }
    }
    while(choice != 0);


    printf("\n");
    return 0;
}
