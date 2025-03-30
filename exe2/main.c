#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_BLUE = 7;
const int BTN_GREEN = 26;

int main() {
  stdio_init_all();

  gpio_init(BTN_BLUE);
  gpio_init(BTN_GREEN);

  gpio_set_dir(BTN_BLUE, GPIO_IN );
  gpio_set_dir(BTN_GREEN, GPIO_IN );

  gpio_pull_up(BTN_BLUE);
  gpio_pull_up(BTN_GREEN);

  while (true) {
    if (!gpio_get(BTN_BLUE)){
      printf("Botao 1 \n");
      while(!gpio_get(BTN_BLUE)){

      }

    }
    if (!gpio_get(BTN_GREEN)){
      printf("Botao 2 \n");
      while(!gpio_get(BTN_GREEN)){
        
      }
    }
  }
}





















// #include "hardware/gpio.h"
// #include "pico/stdlib.h"
// #include <stdio.h>

// const int BTN_VERDE = 26;
// const int BTN_AZUL = 7;

// int main() {
//   stdio_init_all();

//   gpio_init(BTN_VERDE);
//   gpio_init(BTN_AZUL);

//   gpio_set_dir(BTN_VERDE, GPIO_IN);
//   gpio_set_dir(BTN_AZUL, GPIO_IN);

//   gpio_pull_up(BTN_VERDE);
//   gpio_pull_up(BTN_AZUL);

//   while (true) {
//     if (!gpio_get(BTN_VERDE)) {
//       printf("Botao 1\n");
//       while (!gpio_get(BTN_VERDE)) {
//       };
//     }
//     if (!gpio_get(BTN_AZUL)){
//       printf("Botao 2\n");
//       while (!gpio_get(BTN_AZUL)) {
//       };
//     }
//   }
// }
