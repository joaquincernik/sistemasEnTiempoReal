#include <stdio.h>
#include <pigpio.h>

#define LED_BLINK_PIN 17   
#define LED_BOTON_PIN 18   
#define BUTTON_PIN 27     
#define INTERVALO 500000   


void manejar_boton(int gpio, int level, uint32_t tick_evento) {

    uint32_t t_inicio_led = gpioTick();

    if (level == 1) { 
        gpioWrite(LED_BOTON_PIN, 1);
        printf("BOTÓN_PRESIONADO\n");
    } else if (level == 0) { 
        gpioWrite(LED_BOTON_PIN, 0);
        printf("BOTÓN_LIBERADO\n");
    }

    uint32_t latencia = t_inicio_led - tick_evento;
    printf("Latencia medida: %u μs\n", latencia);
}

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Error al inicializar pigpio\n");
        return 1;
    }


    gpioSetMode(LED_BLINK_PIN, PI_OUTPUT);
    gpioSetMode(LED_BOTON_PIN, PI_OUTPUT);
    gpioSetMode(BUTTON_PIN, PI_INPUT);
    
    gpioSetPullUpDown(BUTTON_PIN, PI_PUD_DOWN);
    gpioSetAlertFunc(BUTTON_PIN, manejar_boton);

    uint32_t tiempoUltimoCambio = gpioTick();
    int estadoLedBlink = 0;

    printf("Sistema Iniciado. Blink en GPIO 17, Botón en GPIO 27 controlando LED 18.\n");
    printf("Presiona Ctrl+C para salir.\n");

    while (1) {
        // Lógica del Blink No Bloqueante (Tu código original) [3]
        uint32_t tiempoActual = gpioTick();

        if (tiempoActual - tiempoUltimoCambio >= INTERVALO) {
            estadoLedBlink = !estadoLedBlink;
            gpioWrite(LED_BLINK_PIN, estadoLedBlink);
            if (estadoLedBlink) {
                printf("LED_ON\n");
            } else {
                printf("LED_OFF\n");
            }
            tiempoUltimoCambio = tiempoActual;
        }
    }

    gpioTerminate();
    return 0;
}