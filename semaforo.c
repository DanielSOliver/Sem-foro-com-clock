#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definindo os pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Variáveis para controlar o estado do semáforo e o tempo
volatile int estado_semaforo = 0;
volatile int contador_tempo = 0; // Contador para o tempo

// Função de callback para o temporizador periódico
bool repetir_callback(struct repeating_timer *t) {
    printf("Passaram 3 segundos\n");

    // Alterna o estado do semáforo
    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            estado_semaforo = 1;
            break;
        case 1:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            estado_semaforo = 0;
            break;
    }

    contador_tempo++; // Incrementa o contador a cada 3 segundos
    return true;      // Mantém o temporizador repetindo
}

int main() {
    stdio_init_all(); // Inicializa comunicação serial

    // Configurando os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Configurando o temporizador periódico
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repetir_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Quando o contador atingir 3 (9 segundos), executa a rotina
        if (contador_tempo >= 3) {
            printf("Repetição da rotina após 9 segundos...\n");
            contador_tempo = 0; // Reseta o contador
        }

        sleep_ms(100); // Pequena espera para evitar ocupação total da CPU
    }

    return 0;
}
