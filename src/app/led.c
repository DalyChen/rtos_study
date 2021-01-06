/**********************************************************************
 * FilePath: led.c
 * Author: zhwchen
 * Date: 2021-01-06 23:17
 * Version: V1
 * Brief: 
 * Note: Copyright c 2021 FORWARDX ROBOTICS, Inc. All rights reserved
 * Remarks: 
 **********************************************************************/

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"


#define LED0_PORT   GPIOF
#define LED0_PIN    GPIO_Pin_9

#define LED1_PORT   GPIOF
#define LED1_PIN    GPIO_Pin_10


void led_config(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    /* GPIOG Peripheral clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    /* Configure PG6 and PG8 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = LED0_PIN | LED1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LED0_PORT, &GPIO_InitStructure);

}


void led0_on(void)
{
    GPIO_ResetBits(LED0_PORT, LED0_PIN);
}

void led0_off(void)
{
    GPIO_SetBits(LED0_PORT, LED0_PIN);
}

void led1_on(void)
{
    GPIO_ResetBits(LED1_PORT, LED1_PIN);
}

void led1_off(void)
{
    GPIO_SetBits(LED1_PORT, LED1_PIN);
}

/******************** end of file ********************/
