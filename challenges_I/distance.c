#include <stdio.h>
#include <math.h>

int main()
{
    float Mx, My, Nx, Ny;
    printf("enter Mx and My. \n");
    scanf("%f %f", &Mx, &My);
    printf("enter Nx and Ny. \n");
    scanf("%f %f", &Nx, &Ny);

    float MN = sqrt(pow((Mx - Nx), 2.00) + pow((My - Ny), 2.00));
    printf("distance MN = %.2f", MN);
    

    printf("\n");
    return 0;
}