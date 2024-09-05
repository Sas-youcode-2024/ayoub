#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char chaine[50];
    printf("donner une chaine de caractere: ");
    scanf(" %[^\n]s", chaine);
    int i=0;
    while(chaine[i] != '\0'){
        // travaille avec les codes ASCII
    }
    printf("%s", chaine);
    
    
    
    printf("\n");
    return 0;
}