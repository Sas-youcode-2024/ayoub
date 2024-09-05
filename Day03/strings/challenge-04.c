#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char chaine[50], chaine2[50];
    printf("donner une chaine de caractere: ");
    scanf(" %[^\n]s", chaine);
    printf("donner une autre chaine de caractere: ");
    scanf(" %[^\n]s", chaine2);

    int res = strcmp(chaine, chaine2);
    if(res == 0)
    printf("chaines de caractere sont egaux");
    else 
    printf("chaines de caractere ne pas egaux");
    
    printf("\n");
    return 0;
}