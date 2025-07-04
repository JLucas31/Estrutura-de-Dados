#include <stdio.h>
#include <math.h>
#define pi 3.14

void calc_esfera(float r, float* area, float* volume) {
   
    *area = (4 * pi * pow(r, 2));
    *volume = ((4 * pi * pow(r,3))/3);
}

int main() {
   
    float raio, Area, Volume;

    scanf("%f", &raio);

    calc_esfera(raio, &Area, &Volume);

    printf("Area = %.2f", Area);
    printf("\nVolume = %.2f", Volume);

    return 0;
}
