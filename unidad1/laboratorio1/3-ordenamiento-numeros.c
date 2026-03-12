#include <stdio.h>

int main()
{
    int numeros[5];
    int opcion = 0;
    printf("Ingrese 5 numeros: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Ingrese si quiere ordenarlos de forma ascendente (1) o descendente (2): \n");
    scanf("%d", &opcion);

    // bubble sort
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++) // en cada fin de ciclo el numero mas chico o grande ya esta en el final, entonces no tiene sentido compararlo
        {
            if (opcion == 1)
            { // orden ascendente

                if (numeros[j] > numeros[j + 1])
                {
                    int temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
            else if (opcion == 2)
            { // orden descendente

                if (numeros[j] < numeros[j + 1])
                {
                    int temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
        }
    }
    printf("Los numeros ordenados son: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", numeros[i]);
    }
    return 0;
}