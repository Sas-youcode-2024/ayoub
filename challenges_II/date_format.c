#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jour, mois, annee;
    char mois_name[12][10] = {"janvier", "fevrier", "mars", "avril", "may", "june", "juillet", "aout", "septembre", "novembre", "october", "december"};

    printf("donner un date au format(jj/mm/yyyy): ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    if(mois < 1 || mois > 12){
        printf("mois n'a pas trouver!\n");
        return 0;
    }

    printf("%d-%s-%d", jour, mois_name[mois - 1], annee);

    printf("\n");
    return 0;
}