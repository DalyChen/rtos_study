/**********************************************************************
 * FilePath: main.c
 * Author: zhwchen
 * Date: 2021-01-10 13:37
 * Version: V1
 * Brief: 
 * Note: Copyright c 2021 FORWARDX ROBOTICS, Inc. All rights reserved
 * Remarks: 
 **********************************************************************/

#include "bsp.h"
#include "bsp_int.h"

#include <os.h>
#include <lib_math.h>
#include <os_cfg.h>
#include <stdint.h>


static OS_STK  app_task_start_stk[APP_CFG_TASK_START_STK_SIZE];

static void app_task_start(void *p_arg);



uint8_t loop_en = 1;    /* Prevent compiler warning for 'main return' is unreachable! */

int main(void)
{
#if (OS_TASK_NAME_EN > 0)
    CPU_INT08U  err;
#endif

    bsp_int_dis_all();                /* Disable all Interrupts.              */

    systick_freq_config();

    Mem_Init();                     /* Initialize Memory Managment Module   */
    Math_Init();                    /* Initialize Mathematical Module       */

    OSInit();                       /* Init uC/OS-II.                       */

    OSTaskCreateExt(                /* Create the start task                */
        app_task_start,
        0,
        &app_task_start_stk[APP_CFG_TASK_START_STK_SIZE - 1],
        APP_CFG_TASK_START_PRIO,
        APP_CFG_TASK_START_PRIO,
        &app_task_start_stk[0],
        APP_CFG_TASK_START_STK_SIZE,
        0,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

#if (OS_TASK_NAME_EN > 0)
    OSTaskNameSet(
        APP_CFG_TASK_START_PRIO,
        (INT8U *)"Start Task",
        &err);
#endif

    OSStart();                      /* Start multitasking (i.e. give control to uC/OS-II).  */

    while (loop_en) {
        ;
    }

    return 0;
}

static void app_task_start(void *p_arg)
{
    peripheral_init();
    bsp_int_init();

    CPU_Init();                     /* Initialize the uC/CPU services */

#if (OS_TASK_STAT_EN > 0)
    OSStatInit();                   /* Determine CPU capacity */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

    ;   // Creat your task here

    while (DEF_TRUE) {              /* Task body, always written as an infinite loop. */
        OSTimeDly (1000);
        ;   // do nothing
    }
}


/******************** end of file ********************/
