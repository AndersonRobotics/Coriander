#include "hal_gpio.h"

int main(void){

    gpio_init();

    gpio_export(10);

    gpio_set(10, HIGH);
    gpio_set(10, LOW);

    pwm_init(13);
    pwm_set(13, 1024);

    return 0;
}