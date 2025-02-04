#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

TrafficLightState current_state = RED;

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os estados do semáforo
    switch (current_state) {
        case RED:
            gpio_put(LED_PIN_RED, 1);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = YELLOW;
            printf("Semáforo: Vermelho\n");
            break;
        case YELLOW:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 1);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = GREEN;
            printf("Semáforo: Amarelo\n");
            break;
        case GREEN:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 1);
            current_state = RED;
            printf("Semáforo: Verde\n");
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Configuração do temporizador de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (1) {
        sleep_ms(1000); // Aguarda 1 segundo
        printf("Sistema rodando...\n");
    }
}
