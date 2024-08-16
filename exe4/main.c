#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
const int red_pin = 28;

const int red_led = 5;
const int purple_led = 8;
const int blue_led = 11;
const int yellow_led = 15;

int main() {
  stdio_init_all();

  gpio_init(red_pin);
  gpio_set_dir(red_pin, GPIO_IN);
  gpio_pull_up(red_pin);

  gpio_init(red_led);
  gpio_set_dir(red_led, GPIO_OUT);

  gpio_init(purple_led);
  gpio_set_dir(purple_led, GPIO_OUT);

  gpio_init(blue_led);
  gpio_set_dir(blue_led, GPIO_OUT);

  gpio_init(yellow_led);
  gpio_set_dir(yellow_led, GPIO_OUT);

  while (true) {
    // oda vez que o Btn Vermelho for apertado, faca os LEDs acenderem na ordem: Vermelho, Roxo, Azul e Verde. Só acenda um LED por vez!.
    // Use delay de 300 ms entre os estados!

    if (!gpio_get(red_pin)) {
      gpio_put(red_led, 1);
      sleep_ms(300);
      gpio_put(red_led, 0);

      gpio_put(purple_led, 1);
      sleep_ms(300);
      gpio_put(purple_led, 0);

      gpio_put(blue_led, 1);
      sleep_ms(300);
      gpio_put(blue_led, 0);

      gpio_put(yellow_led, 1);
      sleep_ms(300);
      gpio_put(yellow_led, 0);

      while (!gpio_get(red_pin)) {
      };
    }
  }
}
