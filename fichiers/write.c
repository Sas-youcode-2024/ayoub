#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[10], phone[10];
    int age;
}Contact;

int main(){
    Contact contact;
    FILE *file;
    file = fopen("contact.txt", "a");
    if(file == NULL){
        printf("Erreur en ouverture du fichier");
        return 0;
    }
    else{
        int nbre;
        printf("Combien de contact voulez-vous ajoutee? ");
        scanf("%d", &nbre);
        for(int i=0; i<nbre; i++){
            printf("contact %d \n", i+1);
            printf("votre nom: ");
            scanf("%s", contact.nom);
            printf("votre age: ");
            scanf("%d", &contact.age);
            printf("votre telephone: ");
            scanf("%s", contact.phone);

            fprintf(file, "%s %d %s\n", contact.nom, contact.age, contact.phone);
        }
        fclose(file);
    }
    printf("\n*****************\n\n");
    // open file to read data
    file = fopen("contact.txt", "r");
    if(file == NULL){
        printf("Erreur en ouverture du fichier");
        return 0;
    }
    else{
        while(!feof(file)){
            fscanf(file, "%s %d, %s", contact.nom, &contact.age, contact.phone);
            printf("%s %d, %s\n", contact.nom, contact.age, contact.phone);
        }
        fclose(file);
    }

    printf("\n");
    return 0;
}