#ifndef HAL_GPIO
#define HAL_GPIO

#define HIGH 1
#define LOW 0

int gpio_init();

void gpio_export(unsigned int pin);
void gpio_unexport(unsigned int pin);

void gpio_get(unsigned int pin, unsigned int* out_value);
void gpio_set(unsigned int pin, unsigned int in_value);

#endif