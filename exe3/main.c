#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_GREEN = 26;
const int BTN_RED = 28;
const int LED_GREEN = 6;
const int LED_RED = 4;

int main() {
  stdio_init_all();

  gpio_init(BTN_GREEN);
  gpio_init(BTN_RED);
  gpio_init(LED_GREEN);
  gpio_init(LED_RED);

  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);
  gpio_set_dir(LED_RED, GPIO_OUT);

  gpio_pull_up(BTN_GREEN);
  gpio_pull_up(BTN_RED);

  int estado_atual_led = 0;
  int estado_atual_botao;
  int ultimo_estado_botao = 1;

  int estado_atual_led_red = 0;
  int estado_atual_botao_red;
  int ultimo_estado_botao_red = 1;

  while (true) {
    estado_atual_botao = gpio_get(BTN_GREEN);
    if (ultimo_estado_botao == 1 && estado_atual_botao == 0) {
      if (estado_atual_led == 0) {
        estado_atual_led = 1;
      } else {
          estado_atual_led = 0;
      }
      gpio_put(LED_GREEN, estado_atual_led);
      sleep_ms(50);
    }
    ultimo_estado_botao = estado_atual_botao;

    estado_atual_botao_red = gpio_get(BTN_RED);
    if (ultimo_estado_botao_red == 1 && estado_atual_botao_red == 0) {
      if (estado_atual_led_red == 0) {
        estado_atual_led_red = 1;
      } else {
          estado_atual_led_red = 0;
      }
      gpio_put(LED_RED, estado_atual_led_red);
      sleep_ms(50);
    }
    ultimo_estado_botao_red = estado_atual_botao_red;
  }
}
