#include <stdio.h>


int sumar(int numero1, int numero2){
    return numero1 + numero2;
}

int restar(int numero1, int numero2){
    return numero1 - numero2;
}

int dividir(int numero1, int numero2){
    return numero1 / numero2;
}

int multiplicar(int numero1, int numero2){
    return numero1 * numero2;
}

int main(){
    int numero1, numero2 = 0;
    printf("Ingrese el primer numero: \n");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &numero2);
    printf("La suma es: %d \n", sumar(numero1, numero2));
    printf("La resta es: %d \n", restar(numero1, numero2));
    printf("La division es: %d \n", dividir(numero1, numero2));
    printf("La multiplicacion es: %d \n", multiplicar(numero1, numero2));
    return 0;
}
