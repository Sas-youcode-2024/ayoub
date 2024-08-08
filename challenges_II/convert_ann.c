#include <stdio.h>

int main()
{
    int annee;
    printf("donner une annee: ");
    scanf("%d", &annee);

    int mois, jour, heure, minute, second;
    mois = annee * 12;
    jour = mois * 30;
    heure = jour * 24;
    minute = heure * 60;
    second = minute * 60;

    printf("%d mois \n%d jour \n%d heures \n%d minutes \n%d seconds",
           mois, jour, heure, minute, second);

    printf("\n");
    return 0;
}
