#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[20], prenom[20];
    int age;
}Person;

int main(){
    Person person;
    printf("nom: "); scanf("%s", person.nom);
    printf("prenom: "); scanf("%s", person.prenom);
    printf("age: "); scanf("%d", &person.age);

    printf("vos information sont: ");
    printf("%s %s %d ans", person.nom, person.prenom, person.age);

    printf("\n");
    return 0;
}