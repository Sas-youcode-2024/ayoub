#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[25], prenom[25];
    int notes[3];

}Etudiant;

int main(){
    Etudiant etudiant;
    etudiant.nom[] = "ayoub";
    etudiant.prenom[] = "ahnaou";
    etudiant.notes[0] = 12;
    etudiant.notes[1] = 10;
    etudiant.notes[2] = 9;

    printf("les informations sont: \n");
    printf("%s %s, notes: %d, %d, %d.", etudiant.nom, etudiant.prenom, etudiant.notes[0], etudiant.notes[1], etudiant.notes[2]);

    printf("\n");
    return 0;
}