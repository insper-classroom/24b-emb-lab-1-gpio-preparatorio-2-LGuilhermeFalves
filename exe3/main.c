#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int red_pin = 28;
const int green_pin = 26;

const int red_led = 4;
const int green_led = 6;



int main() {
  stdio_init_all();

  gpio_init(red_pin);
  gpio_set_dir(red_pin, GPIO_IN);
  gpio_pull_up(red_pin);

  gpio_init(green_pin);
  gpio_set_dir(green_pin, GPIO_IN);
  gpio_pull_up(green_pin);

  gpio_init(red_led);
  gpio_set_dir(red_led, GPIO_OUT);

  gpio_init(green_led);
  gpio_set_dir(green_led, GPIO_OUT);

  while (true) {
    if (!gpio_get(red_pin)) {
      if (gpio_get(red_led) == 0) {
        gpio_put(red_led, 1);
      } else {
        gpio_put(red_led, 0);
      }
      while (!gpio_get(red_pin)) {
      };
    } else if (!gpio_get(green_pin)) {
        if (gpio_get(green_led) == 0) {
        gpio_put(green_led, 1);
      } else {
        gpio_put(green_led, 0);
      }
      while (!gpio_get(green_pin)) {
      };
    }
  }
}
