#include <stdio.h>

int main()
{
    int nbre;
    printf("enter a number: ");
    scanf("%d", &nbre);

    if(nbre < 0) printf("number negative \n");
    else if(nbre > 0) printf("number positive \n");
    else printf("number null \n");

    printf("\n");
    return 0;
}