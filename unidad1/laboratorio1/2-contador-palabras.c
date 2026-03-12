#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    int contador = 0;
    printf("Ingrese una frase: \n");
    fgets(frase, sizeof(frase), stdin);
    // frase es donde va a guardar lo que escriba el user
    // sizeof(frase) es el tamaño del array, para evitar que se desborde
    //stdin es la entrada estandar, es decir, el teclado
    for(int i = 0; i < strlen(frase); i++){ 
        if(frase[i] == ' ' || frase[i] == '\n'){ //si detecta un espacio es porque termino una palabra y empieza otra
            contador++;
        }
    }
    printf("La cantidad de palabras es: %d \n", contador);
    return 0;
}