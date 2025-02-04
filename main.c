#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

// Definindo os pinos GPIO para os LEDs
#define LED_RED_PIN 11
#define LED_BLUE_PIN 12
#define LED_GREEN_PIN 13

// Definindo o tempo de temporização (3 segundos)
#define DELAY_MS 3000

// Variável global para controlar o estado do semáforo
int estado_led = 0;

// Função de callback do temporizador
bool semaforoCallback(struct repeating_timer *t)
{
    // Desliga todos os LEDs
    gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_BLUE_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);

    // Controla o estado do semáforo
    switch (estado_led)
    {
    case 0:
        // Liga o LED vermelho
        gpio_put(LED_RED_PIN, 1);
        estado_led = 1;
        break;
    case 1:
        // Liga o LED amarelo
        gpio_put(LED_BLUE_PIN, 1);
        estado_led = 2;
        break;
    case 2:
        // Liga o LED verde
        gpio_put(LED_GREEN_PIN, 1);
        estado_led = 0;
        break;
    }

    return true; // Mantém o temporizador ativo
}

int main()
{
    // Inicializa a UART para saída serial
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // Inicializa o temporizador repetitivo
    struct repeating_timer timer;
    add_repeating_timer_ms(DELAY_MS, semaforoCallback, NULL, &timer);
    // Loop principal
    while (true)
    {
        printf("Semáforo em operação... Estado atual: %d\n", estado_led);
        sleep_ms(1000); // Aguarda 1 segundo antes de imprimir novamente
    }

    return 0;
}
