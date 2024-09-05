#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char chaine[50], chaine2[50];
    printf("donner une chaine de caractere: ");
    scanf(" %[^\n]s", chaine);
    printf("donner une autre chaine de caractere: ");
    scanf(" %[^\n]s", chaine2);

    strncat(chaine, chaine2, 50);

    printf("chaine total: %s", chaine);
    
    printf("\n");
    return 0;
}