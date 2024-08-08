#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int day = (rand() % 7) + 1;

    switch(day){
        case 1: printf("monday"); break;
        case 2: printf("thusday"); break;
        case 3: printf("wedensday"); break;
        case 4: printf("thursday"); break;
        case 5: printf("friday"); break;
        case 6: printf("sunday"); break;
        case 7: printf("saturday"); break;
    }

    printf("\n");
    return 0;
}