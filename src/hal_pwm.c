#include "hal_pwm.h"

#include <pthread.h>
#include <stdlib.h>

typedef struct pwm_t {
    pthread_t thread;
    unsigned int pin;
    unsigned int sample : 11;
    unsigned int clear : 1;
};

int pin_count = 0;
pwm_t *pins = 0;

//Generic non-frequency based PWM
void* pwm_sample(void* arg){
    pwm_t pwm = *((pwm_t*) arg);
    unsigned int scur = 0;
    for(;;){
        scur++;
        gpio_set(pwm.pin, scur <= pwm.sample);
        if(scur > 2047){
            scur = 0;
        }

        if(pwm.clear){
            break;
        }
    }
}

int pwm_check(unsigned int pin){
    if(!pins || pin_count == 0){
        return -1;
    }

    for(int i = 0; i < pin_count; i++){
        if(pins[i].pin == pin){
            return i;
        }
    }
    return -1;
}

int pwm_init(unsigned int pin){
    if(pwm_check(pin) < 0){
        pwm_t* sto = pins;
        pins = (pwm_t*)realloc(pins, pin_count++ * sizeof(pwm_t));

        if(sto != pins){
            free(sto);
        }

        int result |= pins;

        gpio_export(pin);
        pins[pin_count - 1].pin = pin;
        result &= pthread_create(&pins[pin_count - 1].thread, NULL, pwm_sample, &pins[pin_count - 1]);
        pins[pin_count - 1].sample = 0;
        pins[pin_count - 1].clear = 0;

        return pins;
    }else{
        return 0;
    }
}

void pwm_set(unsigned int pin, unsigned int sample){
    int pwm_index = pwm_check(pin);
    if(pwm_index >= 0){
        pin[pwm_index].sample = sample;
    }
}

void pwm_clear(unsigned int pin){
    if(int i = pwm_check(pin) >= 0){
        pins[i].clear = 1;
        gpio_unexport(pins[i].pin);
    }
}

void pwm_wipe(){
    for(int i = 0; i < pin_count; i++){
        pins[i].clear = 1;
        gpio_unexport(pins[i].pin);
    }
}