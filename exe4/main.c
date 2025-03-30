#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>



int main() {
  stdio_init_all();

  
  gpio_pull_up(BTN_RED);

  while (true) {
    
      while (!gpio_get(BTN_RED)) {
      };
    }
  }
}
