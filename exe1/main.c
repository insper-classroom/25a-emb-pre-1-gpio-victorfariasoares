#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_RED = 5;
const int LED_YELLOW = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_RED);
  gpio_init(LED_YELLOW);

  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_set_dir(LED_YELLOW, GPIO_OUT);

  while (true) {
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 1);

    sleep_ms(500);

    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    
    sleep_ms(500);

  }
}
