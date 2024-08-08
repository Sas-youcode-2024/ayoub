#include <stdio.h>

int main(){
    int nbre;
    printf("donner un nombre: ");
    scanf("%d", &nbre);

    for(int i=1; i<=10; i++){
        printf("%d x %d = %d \n", nbre, i, nbre * i);
    }


    printf("\n");
    return 0;
}