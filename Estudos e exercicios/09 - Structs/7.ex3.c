/* 
3. Considerando a estrutura que representa um vetor R3:
struct Vetor{
float x;
float y;
float z;
};
Implemente um programa que receba, calcule e apresente a soma de dois vetores.
*/

#include <stdio.h>

struct st_vector{
    float x;
    float y;
    float z;
}vectors[3];

int main(){
    for(int i = 0; i < 2; i++){
        printf("Enter vector %d values\n", i+1);

        printf("Enter x value: ");
        scanf("%f", &vectors[i].x);

        printf("Enter y value: ");
        scanf("%f", &vectors[i].y);

        printf("Enter z value: ");
        scanf("%f", &vectors[i].z);

    }

    vectors[2].x = vectors[0].x + vectors[1].x;
    vectors[2].y = vectors[0].y + vectors[1].y;
    vectors[2].z = vectors[0].z + vectors[1].z;

    printf("The sum of the vector are X: %.2f, Y: %.2f and Z: %.2f", vectors[2].x, vectors[2].y, vectors[2].z);

    return 0;
}