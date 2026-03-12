#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int semaforo = 0; // 0 es rojo, 1 es verde
    while(1){
        if(semaforo == 0){
            printf("El semaforo esta en verde, pase... \n");
            sleep(5); // espera 5 segundos
            semaforo = 1; // cambia a amarillo
        } else if (semaforo == 1) {
            printf("El semaforo esta en amarillo, prepárese para detenerse... \n");
            sleep(5); // espera 5 segundos
            semaforo = 2; // cambia a rojo
        }
        else{
            printf("El semaforo esta en rojo, espere... \n");
            sleep(5); // espera 5 segundos
            semaforo = 0; // cambia a verde
        }
    }
    return 0;
}