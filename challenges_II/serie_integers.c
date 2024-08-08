#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max, sum = 0, index = 0, tmp;
    int tab[100];

    printf("entrer un nombre entier, entrer 0 pour finir: \n");
    // get numbers from user until he enter 0
    do{
        scanf("%d", &tab[index++]);
    }while(tab[index - 1] != 0);

    printf("\n\n");
    // find the maximum value in tab[] except value upper than 100
    for(int i=0; i<index; i++){
        if(tab[i] < 100){
            max = tab[i];
            break;
        }
    }
    for (int i = 0; i < index; i++){
        for (int j = i + 1; j < index; j++){
            if (max < tab[j] && tab[j] < 100){
                max = tab[j];
                tab[j] = tab[i];
                tab[i] = max;
            }
        }
    }
    printf("max = %d\n", max);

    // sum of number less than 100
    for(int i=0; i<index; i++){
        if(tab[i] < 100)
        sum += tab[i];
    }
    printf("sum = %d\n", sum);


    printf("\n");
    return 0;
}
