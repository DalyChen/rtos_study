/**********************************************************************
 * FilePath: bsp_int.c
 * Author: zhwchen
 * Date: 2021-01-09 15:40
 * Version: V1
 * Brief: 硬中断管理
 * Note: 
 * Remarks: 
 **********************************************************************/

#include  "bsp_int.h"

#include  <cpu.h>
#include  <os.h>



static  CPU_FNCT_VOID  BSP_IntVectTbl[BSP_INT_SRC_NBR];


static  void  BSP_IntHandler     (CPU_DATA  int_id);
static  void  BSP_IntHandlerDummy(void);



/**********************************************************************************************************
* Description : Clear interrupt.
* Argument(s) : int_id      Interrupt to clear.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : (1) An interrupt does not need to be cleared within the interrupt controller.
**********************************************************************************************************/
void bsp_int_clr(CPU_DATA  int_id)
{

}

/**********************************************************************************************************
* Description : Disable interrupt.
* Argument(s) : int_id      Interrupt to disable.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_dis(CPU_DATA  int_id)
{
    if (int_id < BSP_INT_SRC_NBR) {
        CPU_IntSrcDis(int_id + 16u);
    }
}

/**********************************************************************************************************
* Description : Disable ALL interrupts.
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void  bsp_int_dis_all(void)
{
    CPU_IntDis();
}

/**********************************************************************************************************
* Description : Enable interrupt.
* Argument(s) : int_id      Interrupt to enable.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void  bsp_int_en(CPU_DATA  int_id)
{
    if (int_id < BSP_INT_SRC_NBR) {
        CPU_IntSrcEn(int_id + 16u);
    }
}


/**********************************************************************************************************
* Description : Assign ISR handler.
* Argument(s) : int_id      Interrupt for which vector will be set.
*               isr         Handler to assign
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void  bsp_int_vect_set(CPU_DATA int_id, CPU_FNCT_VOID isr)
{
    CPU_SR_ALLOC();

    if (int_id < BSP_INT_SRC_NBR) {
        CPU_CRITICAL_ENTER();
        BSP_IntVectTbl[int_id] = isr;
        CPU_CRITICAL_EXIT();
    }
}

/**********************************************************************************************************
* Description : Assign ISR priority.
* Argument(s) : int_id      Interrupt for which vector will be set.
*               prio        Priority to assign
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_prio_set(CPU_DATA int_id, CPU_INT08U prio)
{
    CPU_SR_ALLOC();

    if (int_id < BSP_INT_SRC_NBR) {
        CPU_CRITICAL_ENTER();
        CPU_IntSrcPrioSet(int_id + 16u, prio);
        CPU_CRITICAL_EXIT();
    }
}


/**********************************************************************************************************
* Description : Initialize interrupts:
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : BSP_Init().
* Note(s)     : none.
**********************************************************************************************************/
void  bsp_int_init(void)
{
    CPU_DATA  int_id;


    for (int_id = 0u; int_id < BSP_INT_SRC_NBR; int_id++) {
        bsp_int_vect_set(int_id, BSP_IntHandlerDummy);
    }
}


/*
*********************************************************************************************************
*                                        BSP_IntHandler####()
*
* Description : Handle an interrupt.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This is an ISR.
*
* Note(s)     : none.
*********************************************************************************************************
*/
void  WWDG_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_WWDG);                }
void  PVD_IRQHandler                (void)  { BSP_IntHandler(BSP_INT_ID_PVD);                 }
void  TAMP_STAMP_IRQHandler         (void)  { BSP_IntHandler(BSP_INT_ID_TAMP_STAMP);          }
void  RTC_WKUP_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_RTC_WKUP);            }
void  FLASH_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_FLASH);               }
void  RCC_IRQHandler                (void)  { BSP_IntHandler(BSP_INT_ID_RCC);                 }
void  EXTI0_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_EXTI0);               }
void  EXTI1_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_EXTI1);               }
void  EXTI2_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_EXTI2);               }
void  EXTI3_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_EXTI3);               }
void  EXTI4_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_EXTI4);               }
void  DMA1_Stream0_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM0);        }
void  DMA1_Stream1_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM1);        }
void  DMA1_Stream2_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM2);        }
void  DMA1_Stream3_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM3);        }
void  DMA1_Stream4_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM4);        }
void  DMA1_Stream5_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM5);        }
void  DMA1_Stream6_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM6);        }
void  ADC_IRQHandler                (void)  { BSP_IntHandler(BSP_INT_ID_ADC);                 }
void  CAN1_TX_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_CAN1_TX);             }
void  CAN1_RX0_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN1_RX0);            }
void  CAN1_RX1_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN1_RX1);            }
void  CAN1_SCE_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN1_SCE);            }
void  EXTI9_5_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_EXTI9_5);             }
void  TIM1_BRK_TIM9_IRQHandler      (void)  { BSP_IntHandler(BSP_INT_ID_TIM1_BRK_TIM9);       }
void  TIM1_UP_TIM10_IRQHandler      (void)  { BSP_IntHandler(BSP_INT_ID_TIM1_UP_TIM10);       }
void  TIM1_TRG_COM_TIM11_IRQHandler (void)  { BSP_IntHandler(BSP_INT_ID_TIM1_TRG_COM_TIM11);  }
void  TIM1_CC_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_TIM1_CC);             }
void  TIM2_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_TIM2);                }
void  TIM3_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_TIM3);                }
void  TIM4_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_TIM4);                }
void  I2C1_EV_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C1_EV);             }
void  I2C1_ER_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C1_ER);             }
void  I2C2_EV_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C2_EV);             }
void  I2C2_ER_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C2_ER);             }
void  SPI1_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_SPI1);                }
void  SPI2_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_SPI2);                }
void  USART1_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_USART1);              }
void  USART2_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_USART2);              }
void  USART3_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_USART3);              }
void  EXTI15_10_IRQHandler          (void)  { BSP_IntHandler(BSP_INT_ID_EXTI15_10);           }
void  RTC_Alarm_IRQHandler          (void)  { BSP_IntHandler(BSP_INT_ID_RTC_ALARM);           }
void  OTG_FS_WKUP_IRQHandler        (void)  { BSP_IntHandler(BSP_INT_ID_OTG_FS_WKUP);         }
void  TIM8_BRK_TIM12_IRQHandler     (void)  { BSP_IntHandler(BSP_INT_ID_TIM8_BRK_TIM12);      }
void  TIM8_UP_TIM13_IRQHandler      (void)  { BSP_IntHandler(BSP_INT_ID_TIM8_UP_TIM13);       }
void  TIM8_TRG_COM_TIM14_IRQHandler (void)  { BSP_IntHandler(BSP_INT_ID_TIM8_TRG_COM_TIM14);  }
void  TIM8_CC_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_TIM8_CC);             }
void  DMA1_Stream7_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA1_STREAM7);        }
void  FSMC_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_FSMC);                }
void  SDIO_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_SDIO);                }
void  TIM5_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_TIM5);                }
void  SPI3_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_SPI3);                }
void  UART4_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_USART4);              }
void  UART5_IRQHandler              (void)  { BSP_IntHandler(BSP_INT_ID_USART5);              }
void  TIM6_DAC_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_TIM6_DAC);            }
void  TIM7_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_TIM7);                }
void  DMA2_Stream0_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream0);        }
void  DMA2_Stream1_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream1);        }
void  DMA2_Stream2_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream2);        }
void  DMA2_Stream3_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream3);        }
void  DMA2_Stream4_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream4);        }
void  ETH_IRQHandler                (void)  { BSP_IntHandler(BSP_INT_ID_ETH);                 }
void  ETH_WKUP_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_ETH_WKUP);            }
void  CAN2_TX_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_CAN2_TX);             }
void  CAN2_RX0_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN2_RX0);            }
void  CAN2_RX1_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN2_RX1);            }
void  CAN2_SCE_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_CAN2_SCE);            }
void  OTG_FS_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_OTG_FS);              }
void  DMA2_Stream5_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream5);        }
void  DMA2_Stream6_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream6);        }
void  DMA2_Stream7_IRQHandler       (void)  { BSP_IntHandler(BSP_INT_ID_DMA2_Stream7);        }
void  USART6_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_USART6);              }
void  I2C3_EV_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C3_EV);             }
void  I2C3_ER_IRQHandler            (void)  { BSP_IntHandler(BSP_INT_ID_I2C3_ER);             }
void  OTG_HS_EP1_OUT_IRQHandler     (void)  { BSP_IntHandler(BSP_INT_ID_OTG_HS_EP1_OUT);      }
void  OTG_HS_EP1_IN_IRQHandler      (void)  { BSP_IntHandler(BSP_INT_ID_OTG_HS_EP1_IN);       }
void  OTG_HS_WKUP_IRQHandler        (void)  { BSP_IntHandler(BSP_INT_ID_OTG_HS_WKUP);         }
void  OTG_HS_IRQHandler             (void)  { BSP_IntHandler(BSP_INT_ID_OTG_HS);              }
void  DCMI_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_DCMI);                }
void  CRYP_IRQHandler               (void)  { BSP_IntHandler(BSP_INT_ID_CRYP);                }
void  HASH_RNG_IRQHandler           (void)  { BSP_IntHandler(BSP_INT_ID_HASH_RNG);            }
void  FPU_IRQHandler                (void)  { BSP_IntHandler(BSP_INT_ID_FPU);                 }


/*
*********************************************************************************************************
*********************************************************************************************************
*                                           LOCAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          BSP_IntHandler()
*
* Description : Central interrupt handler.
*
* Argument(s) : int_id          Interrupt that will be handled.
*
* Return(s)   : none.
*
* Caller(s)   : ISR handlers.
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  BSP_IntHandler (CPU_DATA  int_id)
{
    CPU_FNCT_VOID  isr;
    CPU_SR_ALLOC();


    CPU_CRITICAL_ENTER();                                       /* Tell the OS that we are starting an ISR            */

    OSIntEnter();

    CPU_CRITICAL_EXIT();

    if (int_id < BSP_INT_SRC_NBR) {
        isr = BSP_IntVectTbl[int_id];
        if (isr != (CPU_FNCT_VOID)0u) {
            isr();
        }
    }

    OSIntExit();                                                /* Tell the OS that we are leaving the ISR            */
}


/*
*********************************************************************************************************
*                                        BSP_IntHandlerDummy()
*
* Description : Dummy interrupt handler.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : BSP_IntHandler().
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  BSP_IntHandlerDummy (void)
{
	while (DEF_TRUE) {
        ;
    }
}

/******************** end of file ********************/
