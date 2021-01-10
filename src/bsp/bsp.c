/**********************************************************************
 * FilePath: bsp.h
 * Author: zhwchen
 * Date: 2021-01-09 15:40
 * Version: V1
 * Brief: 
 * Note: 
 * Remarks: 
 **********************************************************************/


#include "bsp.h"

#include "led.h"
#include "stm32f4xx.h"

#include <os_cpu.h>



void bsp_init(void)
{
    OS_CPU_SR cpu_sr = OS_CPU_SR_Save();        // 保存中断状态，并禁中断

    SysTick_Config(SystemCoreClock / 1000);

    led_config();
    led0_on();
    led1_on();

    OS_CPU_SR_Restore(cpu_sr);                  // 回复中断状态
}


CPU_INT32U  BSP_CPU_ClkFreq(void)
{
    CPU_INT32U sys_freq;

    sys_freq = SystemCoreClock;

    return sys_freq;
}


static __IO uint32_t systick_cnt;

void inc_tick(void)
{
    systick_cnt++;
}


void SysTick_Handler(void)
{
#if 0
    static uint16_t cnt = 0;
    if (cnt < 1000) {
        cnt++;
        if (cnt == 1000) {
            led1_toggle();
            cnt = 0;
        }
    }
#endif
}


/******************** end of file ********************/
