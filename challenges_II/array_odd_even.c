#include <stdio.h>

int main(){
    int tab[10] = {1,2,3,4,5,6,7,8,9,10};
    int odd[10], even[10];
    int index1 = 0, index2 = 0;

    for(int i=0; i<10; i++){
        if(tab[i] % 2 == 0){
            even[index1++] = tab[i];
        }
        else 
            odd[index2++] = tab[i];
    }

    printf("element pair: ");
    for(int i=0; i<index1; i++){
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("element impair: ");
    for(int i=0; i<index1; i++){
        printf("%d ", odd[i]);
    }

    printf("\n");
    return 0;
}