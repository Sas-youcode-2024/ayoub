#include <stdio.h>

int main()
{
    int tab[100]; // 43, 12, -6, 0, 4
    int *p1 = tab, *p2 = tab, taille, tmp;
    char type;
    printf("donner la taille du tableau: ");
    scanf("%d", &taille);

    for(p1 = tab; p1 < tab + taille; p1++){
        printf("tab[%ld]= ", p1 - tab + 1);
        scanf("%d", p1);
    }
    printf("trie croissant (y/n)? ");
    scanf(" %c", &type);
    if(type == 'y'){
        for(p1 = tab; p1 < tab + taille; p1++){
            for(p2 = p1 + 1; p2 < tab + taille; p2++){
                if(*p1 > *p2){
                    tmp = *p2;
                    *p2 = *p1;
                    *p1 = tmp;
                }
            }
        }
        printf("\ntrie en ordre croissant est: ");
        for(p1 = tab; p1 < tab + taille; p1++){
        printf("%d ", *p1);
    }
    }else {
        for(p1 = tab; p1 < tab + taille; p1++){
            for(p2 = p1 + 1; p2 < tab + taille; p2++){
                if(*p1 < *p2){
                    tmp = *p2;
                    *p2 = *p1;
                    *p1 = tmp;
                }
            }
        }
        printf("\ntrie en ordre decroissant est: ");
        for(p1 = tab; p1 < tab + taille; p1++){
        printf("%d ", *p1);
    }   
    }

    

    printf("\n");
    return 0;
}