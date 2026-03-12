#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    while(1){
        time_t tiempo = time(NULL); // obtiene el tiempo actual en segundos desde el 1 de enero de 1970
        struct tm *tm = localtime(&tiempo); // convierte el tiempo a una estructura tm que contiene la fecha y hora desglosada
        printf("%02d:%02d:%02d \n", tm->tm_hour, tm->tm_min, tm->tm_sec); // imprime la hora, minutos y segundos con formato de dos digitos
        sleep(1); // espera 1 segundo antes de actualizar la hora
    }
    return 0;
}