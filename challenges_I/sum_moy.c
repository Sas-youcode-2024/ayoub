#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notes[3];
    float sum = 0, moy;
    int index = 0;

    do
    {
        printf("enter your note: ");
        scanf("%f", &notes[index]);
        if (notes[index] <= 20 && notes[index] >= 0)
            index++;
        else
            printf("note must be between 0 and 20 \n");

    } while (index < 3);

    for (int i = 0; i < 3; i++)
    {
        sum += notes[i];
    }
    moy = sum / 3;
    printf("sum = %.2f \n", sum);
    printf("moyenne = %.2f \n", moy);


    printf("\n");
    return 0;
}