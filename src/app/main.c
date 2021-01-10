

#include "bsp.h"

// #include "led.h"

// #include "stm32f4xx.h"
#include <stdint.h>



uint8_t loop_en = 1;

int main(void)
{
    bsp_init();

    while (loop_en){
        ;
    }

    return 0;
}



/******************** end of file ********************/
