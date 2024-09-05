#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type[20];
    int nbreJour;
    __time_t date;
}Vaccin;

typedef struct {
    char cin[20], nom[20], prenom[20];
    int age;
    Vaccin vaccin;
}Person;



int main(){
    menu();

    printf("\n");
    return 0;
}

void menu(){
    int choice;
    do{
        printf("1- ajouter un citoyen\n");
        printf("2- afficher citoyens\n");
        printf("3- total vaccins\n");
    }
    while(choice != 0);
}