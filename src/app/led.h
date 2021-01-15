/**********************************************************************
 * FilePath: led.h
 * Author: zhwchen
 * Date: 2021-01-06 23:17
 * Version: V1
 * Brief: 
 * Note: Copyright c 2021 FORWARDX ROBOTICS, Inc. All rights reserved
 * Remarks: 
 **********************************************************************/
#ifndef _LED_H_
#define _LED_H_

#ifdef __cplusplus
 extern "C" {
#endif


void led_config(void);
void led0_on(void);
void led0_off(void);
void led1_on(void);
void led1_off(void);
void led0_toggle(void);
void led1_toggle(void);

#ifdef __cplusplus
}
#endif
#endif    /* _LED_H_ */

/******************** end of file ********************/
