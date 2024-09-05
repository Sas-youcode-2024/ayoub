#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char chaine[50], caractere;
    printf("donner une chaine de caractere: ");
    scanf(" %[^\n]s", chaine);
    printf("donner un caractere pour compter leur occurences: ");
    scanf(" %c", &caractere);
    int nbre = 0;

    int len = strlen(chaine);
    for(int i=0; i<len; i++){
        if(strcmp(chaine[i], caractere) == 0)
        nbre++;
    }
    printf("le nombre d'occurence de '%c' est %d", caractere, nbre);
    
    
    printf("\n");
    return 0;
}