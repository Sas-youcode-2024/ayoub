#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nom[10], phone[10];
    int age;
}Contact;

int main(){
    Contact contact;
    FILE *file, *newFile;
    bool deleted = false;
    char nom[10];
    printf("entrer le nom a supprimer: ");
    scanf("%s", nom);
    file = fopen("contact.txt", "r");
    if(file == NULL){
        printf("error opening file");
    }
    else{
        newFile = fopen("newContact.txt", "w");
        if(newFile == NULL){
            printf("error opening file");
        }
        else {
            while(!feof(file)){
                fscanf(file, "%s %d, %s", contact.nom, &contact.age, contact.phone);
                if(strcmp(nom, contact.nom) != 0){
                    fprintf(newFile, "%s %d, %s\n", contact.nom, contact.age, contact.phone);
                }else{
                    deleted = true;
                }
            }
            if(deleted) printf("contact deleted successfuly.");
            else printf("contact didn't exist.");
        }
        fclose(newFile);
        fclose(file);
    }

    // copie all contacts from newContact file to contact file
    file = fopen("contact.txt", "w");
    if(file == NULL){
        printf("error opening file");
    }
    else {
        newFile = fopen("newContact.txt", "r");
        if(newFile == NULL){
            printf("error opening file");
        } else {
            while(!feof(newFile)){
                fscanf(newFile, "%s %d, %s", contact.nom, &contact.age, contact.phone);
                fprintf(file, "%s %d, %s\n", contact.nom, contact.age, contact.phone);
            }
        }
        fclose(newFile);
        fclose(file);
    }

    printf("\n");
    return 0;
}