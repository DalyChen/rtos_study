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


void bsp_init(void);

void inc_tick(void);
CPU_INT32U  BSP_CPU_ClkFreq(void);



#ifdef __cplusplus
}
#endif
#endif    /* _BSP_H_ */

/******************** end of file ********************/
