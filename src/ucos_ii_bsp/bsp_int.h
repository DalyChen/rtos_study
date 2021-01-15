/**********************************************************************
 * FilePath: bsp_int.h
 * Author: zhwchen
 * Date: 2021-01-10 14:10
 * Version: V1
 * Brief: 
 * Note: 
 * Remarks: 
 **********************************************************************/
#ifndef _BSP_INT_H_
#define _BSP_INT_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include  <cpu.h>
#include  <cpu_core.h>

#include  <lib_def.h>


#define  BSP_INT_ID_WWDG                                   0u   /* Window WatchDog Interrupt                            */
#define  BSP_INT_ID_PVD                                    1u   /* PVD through EXTI Line detection Interrupt            */
#define  BSP_INT_ID_TAMP_STAMP                             2u   /* Tamper and TimeStamp Interrupt                       */
#define  BSP_INT_ID_RTC_WKUP                               3u   /* RTC wakeup Interrupt through the EXTI line           */
#define  BSP_INT_ID_FLASH                                  4u   /* FLASH global Interrupt                               */
#define  BSP_INT_ID_RCC                                    5u   /* RCC global Interrupt                                 */
#define  BSP_INT_ID_EXTI0                                  6u   /* EXTI Line0 Interrupt                                 */
#define  BSP_INT_ID_EXTI1                                  7u   /* EXTI Line1 Interrupt                                 */
#define  BSP_INT_ID_EXTI2                                  8u   /* EXTI Line2 Interrupt                                 */
#define  BSP_INT_ID_EXTI3                                  9u   /* EXTI Line3 Interrupt                                 */
#define  BSP_INT_ID_EXTI4                                 10u   /* EXTI Line4 Interrupt                                 */
#define  BSP_INT_ID_DMA1_STREAM0                          11u   /* DMA1 Stream 0 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM1                          12u   /* DMA1 Stream 1 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM2                          13u   /* DMA1 Stream 2 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM3                          14u   /* DMA1 Stream 3 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM4                          15u   /* DMA1 Stream 4 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM5                          16u   /* DMA1 Stream 5 global Interrupt                      */
#define  BSP_INT_ID_DMA1_STREAM6                          17u   /* DMA1 Stream 6 global Interrupt                      */
#define  BSP_INT_ID_ADC                                   18u   /* ADC1, ADC2 and ADC3 global Interrupt                 */
#define  BSP_INT_ID_CAN1_TX                               19u   /* CAN1 TX Interrupts                                   */
#define  BSP_INT_ID_CAN1_RX0                              20u   /* CAN1 RX0 Interrupts                                  */
#define  BSP_INT_ID_CAN1_RX1                              21u   /* CAN1 RX1 Interrupt                                   */
#define  BSP_INT_ID_CAN1_SCE                              22u   /* CAN1 SCE Interrupt                                   */
#define  BSP_INT_ID_EXTI9_5                               23u   /* External Line[9:5] Interrupts                        */
#define  BSP_INT_ID_TIM1_BRK_TIM9                         24u   /* TIM1 Break Interrupt and TIM9 global interrupt       */
#define  BSP_INT_ID_TIM1_UP_TIM10                         25u   /* TIM1 Update Interrupt and TIM10 global interrupt     */
#define  BSP_INT_ID_TIM1_TRG_COM_TIM11                    26u   /* TIM1 Trigger & Commutation Int. & TIM11 global Int.  */
#define  BSP_INT_ID_TIM1_CC                               27u   /* TIM1 Capture Compare Interrupt                       */
#define  BSP_INT_ID_TIM2                                  28u   /* TIM2 global Interrupt                                */
#define  BSP_INT_ID_TIM3                                  29u   /* TIM3 global Interrupt                                */
#define  BSP_INT_ID_TIM4                                  30u   /* TIM4 global Interrupt                                */
#define  BSP_INT_ID_I2C1_EV                               31u   /* I2C1 Event Interrupt                                 */
#define  BSP_INT_ID_I2C1_ER                               32u   /* I2C1 Error Interrupt                                 */
#define  BSP_INT_ID_I2C2_EV                               33u   /* I2C2 Event Interrupt                                 */
#define  BSP_INT_ID_I2C2_ER                               34u   /* I2C2 Error Interrupt                                 */
#define  BSP_INT_ID_SPI1                                  35u   /* SPI1 global Interrupt                                */
#define  BSP_INT_ID_SPI2                                  36u   /* SPI2 global Interrupt                                */
#define  BSP_INT_ID_USART1                                37u   /* USART1 global Interrupt                              */
#define  BSP_INT_ID_USART2                                38u   /* USART2 global Interrupt                              */
#define  BSP_INT_ID_USART3                                39u   /* USART3 global Interrupt                              */
#define  BSP_INT_ID_EXTI15_10                             40u   /* External Line[15:10] Interrupts                      */
#define  BSP_INT_ID_RTC_ALARM                             41u   /* RTC Alarms (A and B) through EXTI Line Interrupt     */
#define  BSP_INT_ID_OTG_FS_WKUP                           42u   /* USB WakeUp from suspend through EXTI Line Interrupt  */

#define  BSP_INT_ID_TIM8_BRK_TIM12                        43u   /* TIM8 Break Interrupt and TIM12 global Interrupt      */
#define  BSP_INT_ID_TIM8_UP_TIM13                         44u   /* TIM8 Update Interrupt and TIM13 global Interrupt     */
#define  BSP_INT_ID_TIM8_TRG_COM_TIM14                    45u   /* TIM8 Trigger/Commutation and TIM14 global Interrupt  */
#define  BSP_INT_ID_TIM8_CC                               46u   /* TIM8 Capture Compare Interrupt                       */
#define  BSP_INT_ID_DMA1_STREAM7                          47u   /* DMA1 Stream7 Interrupt                               */
#define  BSP_INT_ID_FSMC                                  48u   /* FSMC global Interrupt                                */
#define  BSP_INT_ID_SDIO                                  49u   /* SDIO global Interrupt                                */

#define  BSP_INT_ID_TIM5                                  50u   /* TIM5 global Interrupt                                */
#define  BSP_INT_ID_SPI3                                  51u   /* SPI3 global Interrupt                                */
#define  BSP_INT_ID_USART4                                52u   /* USART4 global Interrupt                              */
#define  BSP_INT_ID_USART5                                53u   /* USART5 global Interrupt                              */
#define  BSP_INT_ID_TIM6_DAC                              54u   /* TIM6 global Interrupt, DAC1 & DAC2 underrun err int. */
#define  BSP_INT_ID_TIM7                                  55u   /* TIM7 global Interrupt                                */
#define  BSP_INT_ID_DMA2_Stream0                          56u   /* DMA2 Stream 0 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream1                          57u   /* DMA2 Stream 1 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream2                          58u   /* DMA2 Stream 2 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream3                          59u   /* DMA2 Stream 3 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream4                          60u   /* DMA2 Stream 4 global Interrupt                      */

#define  BSP_INT_ID_ETH                                   61u   /* ETH  global Interrupt                                */
#define  BSP_INT_ID_ETH_WKUP                              62u   /* ETH  WakeUp from EXTI line interrupt                 */
#define  BSP_INT_ID_CAN2_TX                               63u   /* CAN2 TX Interrupts                                   */
#define  BSP_INT_ID_CAN2_RX0                              64u   /* CAN2 RX0 Interrupts                                  */
#define  BSP_INT_ID_CAN2_RX1                              65u   /* CAN2 RX1 Interrupt                                   */
#define  BSP_INT_ID_CAN2_SCE                              66u   /* CAN2 SCE Interrupt                                   */
#define  BSP_INT_ID_OTG_FS                                67u   /* OTG global Interrupt                                 */

#define  BSP_INT_ID_DMA2_Stream5                          68u   /* DMA2 Stream 5 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream6                          69u   /* DMA2 Stream 6 global Interrupt                      */
#define  BSP_INT_ID_DMA2_Stream7                          70u   /* DMA2 Stream 7 global Interrupt                      */
#define  BSP_INT_ID_USART6                                71u   /* USART5 global Interrupt                              */
#define  BSP_INT_ID_I2C3_EV                               72u   /* I2C3 Event  Interrupt                                */
#define  BSP_INT_ID_I2C3_ER                               73u   /* I2C3 Error  Interrupt                                */
#define  BSP_INT_ID_OTG_HS_EP1_OUT                        74u   /* OTG HS EP1 OUT global Interrupt                      */
#define  BSP_INT_ID_OTG_HS_EP1_IN                         75u   /* OTG HS EP1 IN global Interrupt                       */
#define  BSP_INT_ID_OTG_HS_WKUP                           76u   /* OTG HS Wakeup Interrupt                              */
#define  BSP_INT_ID_OTG_HS                                77u   /* OTG HS global Interrupt                              */
#define  BSP_INT_ID_DCMI                                  78u   /* DCMI global Interrupt                                */
#define  BSP_INT_ID_CRYP                                  79u   /* CRYPT crypto global Interrupt                        */
#define  BSP_INT_ID_HASH_RNG                              80u   /* HASH and RNG global Interrupt                        */
#define  BSP_INT_ID_FPU                                   81u   /* FPU global Interrupt                                 */

#define  BSP_INT_SRC_NBR                                  82u

/**********************************************************************************************************
* Description : Clear interrupt.
* Argument(s) : int_id      Interrupt to clear.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : (1) An interrupt does not need to be cleared within the interrupt controller.
**********************************************************************************************************/
void bsp_int_clr(CPU_DATA int_id);

/**********************************************************************************************************
* Description : Disable interrupt.
* Argument(s) : int_id      Interrupt to disable.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_dis(CPU_DATA int_id);

/**********************************************************************************************************
* Description : Disable ALL interrupts.
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_dis_all(void);

/**********************************************************************************************************
* Description : Enable interrupt.
* Argument(s) : int_id      Interrupt to enable.
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_en(CPU_DATA int_id);

/**********************************************************************************************************
* Description : Assign ISR handler.
* Argument(s) : int_id      Interrupt for which vector will be set.
*               isr         Handler to assign
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_vect_set(CPU_DATA int_id, CPU_FNCT_VOID isr);

/**********************************************************************************************************
* Description : Assign ISR priority.
* Argument(s) : int_id      Interrupt for which vector will be set.
*               prio        Priority to assign
* Return(s)   : none.
* Caller(s)   : Application.
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_prio_set(CPU_DATA int_id, CPU_INT08U prio);

/**********************************************************************************************************
* Description : Initialize interrupts:
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : BSP_Init().
* Note(s)     : none.
**********************************************************************************************************/
void bsp_int_init(void);

/**********************************************************************************************************
* Name        : BSP_IntHandler####()
* Description : Handle an interrupt.
* Argument(s) : none.
* Return(s)   : none.
* Caller(s)   : This is an ISR.
* Note(s)     : none.
**********************************************************************************************************/
void WWDG_IRQHandler                (void);
void PVD_IRQHandler                 (void);
void TAMP_STAMP_IRQHandler          (void);
void RTC_WKUP_IRQHandler            (void);
void FLASH_IRQHandler               (void);
void RCC_IRQHandler                 (void);
void EXTI0_IRQHandler               (void);
void EXTI1_IRQHandler               (void);
void EXTI2_IRQHandler               (void);
void EXTI3_IRQHandler               (void);
void EXTI4_IRQHandler               (void);
void DMA1_Stream0_IRQHandler        (void);
void DMA1_Stream1_IRQHandler        (void);
void DMA1_Stream2_IRQHandler        (void);
void DMA1_Stream3_IRQHandler        (void);
void DMA1_Stream4_IRQHandler        (void);
void DMA1_Stream5_IRQHandler        (void);
void DMA1_Stream6_IRQHandler        (void);
void ADC_IRQHandler                 (void);
void CAN1_TX_IRQHandler             (void);
void CAN1_RX0_IRQHandler            (void);
void CAN1_RX1_IRQHandler            (void);
void CAN1_SCE_IRQHandler            (void);
void EXTI9_5_IRQHandler             (void);
void TIM1_BRK_TIM9_IRQHandler       (void);
void TIM1_UP_TIM10_IRQHandler       (void);
void TIM1_TRG_COM_TIM11_IRQHandler  (void);
void TIM1_CC_IRQHandler             (void);
void TIM2_IRQHandler                (void);
void TIM3_IRQHandler                (void);
void TIM4_IRQHandler                (void);
void I2C1_EV_IRQHandler             (void);
void I2C1_ER_IRQHandler             (void);
void I2C2_EV_IRQHandler             (void);
void I2C2_ER_IRQHandler             (void);
void SPI1_IRQHandler                (void);
void SPI2_IRQHandler                (void);
void USART1_IRQHandler              (void);
void USART2_IRQHandler              (void);
void USART3_IRQHandler              (void);
void EXTI15_10_IRQHandler           (void);
void RTC_Alarm_IRQHandler           (void);
void OTG_FS_WKUP_IRQHandler         (void);
void TIM8_BRK_TIM12_IRQHandler      (void);
void TIM8_UP_TIM13_IRQHandler       (void);
void TIM8_TRG_COM_TIM14_IRQHandler  (void);
void TIM8_CC_IRQHandler             (void);
void DMA1_Stream7_IRQHandler        (void);
void FSMC_IRQHandler                (void);
void SDIO_IRQHandler                (void);
void TIM5_IRQHandler                (void);
void SPI3_IRQHandler                (void);
void UART4_IRQHandler               (void);
void UART5_IRQHandler               (void);
void TIM6_DAC_IRQHandler            (void);
void TIM7_IRQHandler                (void);
void DMA2_Stream0_IRQHandler        (void);
void DMA2_Stream1_IRQHandler        (void);
void DMA2_Stream2_IRQHandler        (void);
void DMA2_Stream3_IRQHandler        (void);
void DMA2_Stream4_IRQHandler        (void);
void ETH_IRQHandler                 (void);
void ETH_WKUP_IRQHandler            (void);
void CAN2_TX_IRQHandler             (void);
void CAN2_RX0_IRQHandler            (void);
void CAN2_RX1_IRQHandler            (void);
void CAN2_SCE_IRQHandler            (void);
void OTG_FS_IRQHandler              (void);
void DMA2_Stream5_IRQHandler        (void);
void DMA2_Stream6_IRQHandler        (void);
void DMA2_Stream7_IRQHandler        (void);
void USART6_IRQHandler              (void);
void I2C3_EV_IRQHandler             (void);
void I2C3_ER_IRQHandler             (void);
void OTG_HS_EP1_OUT_IRQHandler      (void);
void OTG_HS_EP1_IN_IRQHandler       (void);
void OTG_HS_WKUP_IRQHandler         (void);
void OTG_HS_IRQHandler              (void);
void DCMI_IRQHandler                (void);
void CRYP_IRQHandler                (void);
void HASH_RNG_IRQHandler            (void);
void FPU_IRQHandler                 (void);



#ifdef __cplusplus
}
#endif
#endif    /* _BSP_INT_H_ */

/******************** end of file ********************/
