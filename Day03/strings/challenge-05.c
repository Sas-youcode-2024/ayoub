#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char chaine[50];
    printf("donner une chaine de caractere: ");
    scanf(" %[^\n]s", chaine);

    // inverse une chaine de caractere
    printf("l'inverse est: ");
    int len = strlen(chaine);
    for(int i=len-1; i>=0; i--){
        printf("%c", chaine[i]);
    }
    
    
    printf("\n");
    return 0;
}