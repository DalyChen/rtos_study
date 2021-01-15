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

#include "stm32f4xx.h"

#include <os_cpu.h>


__weak void systick_freq_config(void)
{
    SysTick_Config(SystemCoreClock / 1000);
}

__weak void peripheral_init(void)
{
    OS_CPU_SR cpu_sr = OS_CPU_SR_Save();        // 保存中断状态，并禁中断

    ;   // periph  init

    OS_CPU_SR_Restore(cpu_sr);                  // 回复中断状态
}


__weak CPU_INT32U  BSP_CPU_ClkFreq(void)
{
    CPU_INT32U sys_freq;

    sys_freq = SystemCoreClock;

    return sys_freq;
}


static __IO uint32_t systick_cnt;

__weak void inc_tick(void)
{
    systick_cnt++;
}

/******************** end of file ********************/
