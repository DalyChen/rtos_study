/**********************************************************************
 * FilePath: bsp.h
 * Author: zhwchen
 * Date: 2021-01-09 15:40
 * Version: V1
 * Brief: 
 * Note: 
 * Remarks: 
 **********************************************************************/
#ifndef _BSP_H_
#define _BSP_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include <cpu.h>



void systick_freq_config(void);
/* example:
__weak void systick_freq_config(void)
{
    SysTick_Config(SystemCoreClock / 1000);
}
*/
 
void peripheral_init(void);
/* example:
void bsp_init(void)
{
    OS_CPU_SR cpu_sr = OS_CPU_SR_Save();

    ;   // periph  init

    OS_CPU_SR_Restore(cpu_sr);
}
*/

void inc_tick(void);
/* example:
CPU_INT32U  BSP_CPU_ClkFreq(void)
{
    CPU_INT32U sys_freq;

    sys_freq = SystemCoreClock;     // defined in system_stm32f4xx.c

    return sys_freq;
}
*/

CPU_INT32U  BSP_CPU_ClkFreq(void);
/* example:
static __IO uint32_t systick_cnt;

void inc_tick(void)
{
    systick_cnt++;
}
*/


#ifdef __cplusplus
}
#endif
#endif    /* _BSP_H_ */

/******************** end of file ********************/
