#ifndef HAL_PWM
#define HAL_PWM

#include "hal_gpio.h"

#include <pthread.h>

int pwm_init(unsigned int pin);
void pwm_set(unsigned int pin, unsigned int sample);
void pwm_clear(unsigned int pin);

void pwm_wipe();

#endif