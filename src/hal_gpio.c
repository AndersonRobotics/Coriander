#include "hal_gpio.h"

int memory_descriptor;

unsigned int *gpio;

#define PERIPHERAL_BASE 0x20000000 //Might be 0x3F000000
#define GPIO_BASE (PERIPHERAL_BASE + 0x200000)

#define GPIO_REGISTER(g) (g/10)
#define GPIO_SHIFT(g) ((g % 10) * 3)

int gpio_init(){
    if((memory_descriptor = open("/dev/mem", O_RDWR|O_SYNC)) < 0){
        //Error handling for opening /dev/mem for GPIO
        return -1;
    }

    gpio = (unsigned int*)mmap(0, len, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_LOCKED, fd, addr);

    close(memory_descriptor);

    if(gpio == MAP_FAILED){
        //Error handling for mapping /dev/mem at gpio_base to virtual memory
        return -2;
    }

    return 0;
}

void gpio_export(unsigned int pin){
    *(gpio + GPIO_REGISTER(pin)) &= ~(7 << GPIO_SHIFT(pin));
    *(gpio + GPIO_REGISTER(pin)) |= (1 << GPIO_SHIFT(pin));
}

void gpio_unexport(unsigned int pin){
    *(gpio + GPIO_REGISTER(pin)) &= ~(7 << GPIO_SHIFT(pin));
    *(gpio + GPIO_REGISTER(pin)) &= ~(1 << GPIO_SHIFT(pin));
}

void gpio_get(unsigned int pin, unsigned int* out_value){
    *out_value = (*(gpio + 13) & (1 << pin)) == (1 << pin);
}

void gpio_set(unsigned int pin, unsigned int in_value){
    if(in_value == 0){
        *(gpio + 10) |= 1 << pin;
    }else if(in_value == 1){
        *(gpio + 7) |= 1 << pin;
    }else{

    }
}