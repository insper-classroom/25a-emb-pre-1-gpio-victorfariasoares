#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_VERDE = 26;
const int BTN_BLUE = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_VERDE);
    gpio_set_dir(BTN_VERDE, GPIO_IN);
    gpio_pull_up(BTN_VERDE);

    gpio_init(BTN_BLUE);
    gpio_set_dir(BTN_BLUE, GPIO_IN);
    gpio_pull_up(BTN_BLUE);
    
    int cnt_verde = 0;
    int cnt_blue = 0;

    while (true) {

        if (!gpio_get(BTN_VERDE)) {
            sleep_ms(100);
            printf("Botao 1: %d\n", cnt_verde++);
            while(!gpio_get(BTN_VERDE)){
                sleep_ms(10);

            }
        }

        if (!gpio_get(BTN_BLUE)) {
            sleep_ms(100);
            printf("Botao 2: %d\n", cnt_blue++);
            while(!gpio_get(BTN_BLUE)){
                sleep_ms(10);

            }
        }
    }
}
