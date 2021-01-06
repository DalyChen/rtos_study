
#include "led.h"

#include "stm32f4xx.h"
#include <stdint.h>

uint8_t loop_en = 1;

int main(void)
{
    SysTick_Config(SystemCoreClock / 1000);
    led_config();

    led0_on();
    led1_on();

    while (loop_en){
        ;
    }

    return 0;
}

uint16_t cnt = 0;

void SysTick_Handler(void)
{
    if (cnt < 2000) {
        cnt++;
        if (cnt == 1000) {
            led0_on();
        } else if (cnt == 2000) {
            led0_off();
            cnt = 0;
        }
    }
}


/******************** end of file ********************/
