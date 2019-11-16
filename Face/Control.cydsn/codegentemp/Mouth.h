/*******************************************************************************
* File Name: Mouth.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_Mouth_H)
#define CY_PWM_Mouth_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Mouth_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Mouth_Resolution                     (16u)
#define Mouth_UsingFixedFunction             (0u)
#define Mouth_DeadBandMode                   (0u)
#define Mouth_KillModeMinTime                (0u)
#define Mouth_KillMode                       (0u)
#define Mouth_PWMMode                        (1u)
#define Mouth_PWMModeIsCenterAligned         (0u)
#define Mouth_DeadBandUsed                   (0u)
#define Mouth_DeadBand2_4                    (0u)

#if !defined(Mouth_PWMUDB_genblk8_stsreg__REMOVED)
    #define Mouth_UseStatus                  (1u)
#else
    #define Mouth_UseStatus                  (0u)
#endif /* !defined(Mouth_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Mouth_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Mouth_UseControl                 (1u)
#else
    #define Mouth_UseControl                 (0u)
#endif /* !defined(Mouth_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define Mouth_UseOneCompareMode              (0u)
#define Mouth_MinimumKillTime                (1u)
#define Mouth_EnableMode                     (0u)

#define Mouth_CompareMode1SW                 (0u)
#define Mouth_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Mouth__B_PWM__DISABLED 0
#define Mouth__B_PWM__ASYNCHRONOUS 1
#define Mouth__B_PWM__SINGLECYCLE 2
#define Mouth__B_PWM__LATCHED 3
#define Mouth__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Mouth__B_PWM__DBMDISABLED 0
#define Mouth__B_PWM__DBM_2_4_CLOCKS 1
#define Mouth__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Mouth__B_PWM__ONE_OUTPUT 0
#define Mouth__B_PWM__TWO_OUTPUTS 1
#define Mouth__B_PWM__DUAL_EDGE 2
#define Mouth__B_PWM__CENTER_ALIGN 3
#define Mouth__B_PWM__DITHER 5
#define Mouth__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Mouth__B_PWM__LESS_THAN 1
#define Mouth__B_PWM__LESS_THAN_OR_EQUAL 2
#define Mouth__B_PWM__GREATER_THAN 3
#define Mouth__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Mouth__B_PWM__EQUAL 0
#define Mouth__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!Mouth_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!Mouth_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!Mouth_PWMModeIsCenterAligned) */
        #if (Mouth_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Mouth_UseStatus) */

        /* Backup for Deadband parameters */
        #if(Mouth_DeadBandMode == Mouth__B_PWM__DBM_256_CLOCKS || \
            Mouth_DeadBandMode == Mouth__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(Mouth_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Mouth_KillModeMinTime) */

        /* Backup control register */
        #if(Mouth_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Mouth_UseControl) */

    #endif /* (!Mouth_UsingFixedFunction) */

}Mouth_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    Mouth_Start(void) ;
void    Mouth_Stop(void) ;

#if (Mouth_UseStatus || Mouth_UsingFixedFunction)
    void  Mouth_SetInterruptMode(uint8 interruptMode) ;
    uint8 Mouth_ReadStatusRegister(void) ;
#endif /* (Mouth_UseStatus || Mouth_UsingFixedFunction) */

#define Mouth_GetInterruptSource() Mouth_ReadStatusRegister()

#if (Mouth_UseControl)
    uint8 Mouth_ReadControlRegister(void) ;
    void  Mouth_WriteControlRegister(uint8 control)
          ;
#endif /* (Mouth_UseControl) */

#if (Mouth_UseOneCompareMode)
   #if (Mouth_CompareMode1SW)
       void    Mouth_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (Mouth_CompareMode1SW) */
#else
    #if (Mouth_CompareMode1SW)
        void    Mouth_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (Mouth_CompareMode1SW) */
    #if (Mouth_CompareMode2SW)
        void    Mouth_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (Mouth_CompareMode2SW) */
#endif /* (Mouth_UseOneCompareMode) */

#if (!Mouth_UsingFixedFunction)
    uint16   Mouth_ReadCounter(void) ;
    uint16 Mouth_ReadCapture(void) ;

    #if (Mouth_UseStatus)
            void Mouth_ClearFIFO(void) ;
    #endif /* (Mouth_UseStatus) */

    void    Mouth_WriteCounter(uint16 counter)
            ;
#endif /* (!Mouth_UsingFixedFunction) */

void    Mouth_WritePeriod(uint16 period)
        ;
uint16 Mouth_ReadPeriod(void) ;

#if (Mouth_UseOneCompareMode)
    void    Mouth_WriteCompare(uint16 compare)
            ;
    uint16 Mouth_ReadCompare(void) ;
#else
    void    Mouth_WriteCompare1(uint16 compare)
            ;
    uint16 Mouth_ReadCompare1(void) ;
    void    Mouth_WriteCompare2(uint16 compare)
            ;
    uint16 Mouth_ReadCompare2(void) ;
#endif /* (Mouth_UseOneCompareMode) */


#if (Mouth_DeadBandUsed)
    void    Mouth_WriteDeadTime(uint8 deadtime) ;
    uint8   Mouth_ReadDeadTime(void) ;
#endif /* (Mouth_DeadBandUsed) */

#if ( Mouth_KillModeMinTime)
    void Mouth_WriteKillTime(uint8 killtime) ;
    uint8 Mouth_ReadKillTime(void) ;
#endif /* ( Mouth_KillModeMinTime) */

void Mouth_Init(void) ;
void Mouth_Enable(void) ;
void Mouth_Sleep(void) ;
void Mouth_Wakeup(void) ;
void Mouth_SaveConfig(void) ;
void Mouth_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Mouth_INIT_PERIOD_VALUE          (20000u)
#define Mouth_INIT_COMPARE_VALUE1        (2000u)
#define Mouth_INIT_COMPARE_VALUE2        (2000u)
#define Mouth_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    Mouth_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Mouth_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Mouth_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Mouth_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Mouth_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  Mouth_CTRL_CMPMODE2_SHIFT)
#define Mouth_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  Mouth_CTRL_CMPMODE1_SHIFT)
#define Mouth_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (Mouth_UsingFixedFunction)
   #define Mouth_PERIOD_LSB              (*(reg16 *) Mouth_PWMHW__PER0)
   #define Mouth_PERIOD_LSB_PTR          ( (reg16 *) Mouth_PWMHW__PER0)
   #define Mouth_COMPARE1_LSB            (*(reg16 *) Mouth_PWMHW__CNT_CMP0)
   #define Mouth_COMPARE1_LSB_PTR        ( (reg16 *) Mouth_PWMHW__CNT_CMP0)
   #define Mouth_COMPARE2_LSB            (0x00u)
   #define Mouth_COMPARE2_LSB_PTR        (0x00u)
   #define Mouth_COUNTER_LSB             (*(reg16 *) Mouth_PWMHW__CNT_CMP0)
   #define Mouth_COUNTER_LSB_PTR         ( (reg16 *) Mouth_PWMHW__CNT_CMP0)
   #define Mouth_CAPTURE_LSB             (*(reg16 *) Mouth_PWMHW__CAP0)
   #define Mouth_CAPTURE_LSB_PTR         ( (reg16 *) Mouth_PWMHW__CAP0)
   #define Mouth_RT1                     (*(reg8 *)  Mouth_PWMHW__RT1)
   #define Mouth_RT1_PTR                 ( (reg8 *)  Mouth_PWMHW__RT1)

#else
   #if (Mouth_Resolution == 8u) /* 8bit - PWM */

       #if(Mouth_PWMModeIsCenterAligned)
           #define Mouth_PERIOD_LSB      (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define Mouth_PERIOD_LSB_PTR  ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define Mouth_PERIOD_LSB      (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define Mouth_PERIOD_LSB_PTR  ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (Mouth_PWMModeIsCenterAligned) */

       #define Mouth_COMPARE1_LSB        (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Mouth_COMPARE1_LSB_PTR    ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Mouth_COMPARE2_LSB        (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Mouth_COMPARE2_LSB_PTR    ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Mouth_COUNTERCAP_LSB      (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Mouth_COUNTERCAP_LSB_PTR  ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Mouth_COUNTER_LSB         (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Mouth_COUNTER_LSB_PTR     ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Mouth_CAPTURE_LSB         (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define Mouth_CAPTURE_LSB_PTR     ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(Mouth_PWMModeIsCenterAligned)
               #define Mouth_PERIOD_LSB      (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define Mouth_PERIOD_LSB_PTR  ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define Mouth_PERIOD_LSB      (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define Mouth_PERIOD_LSB_PTR  ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (Mouth_PWMModeIsCenterAligned) */

            #define Mouth_COMPARE1_LSB       (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Mouth_COMPARE1_LSB_PTR   ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Mouth_COMPARE2_LSB       (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Mouth_COMPARE2_LSB_PTR   ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Mouth_COUNTERCAP_LSB     (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Mouth_COUNTERCAP_LSB_PTR ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Mouth_COUNTER_LSB        (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Mouth_COUNTER_LSB_PTR    ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Mouth_CAPTURE_LSB        (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define Mouth_CAPTURE_LSB_PTR    ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(Mouth_PWMModeIsCenterAligned)
               #define Mouth_PERIOD_LSB      (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define Mouth_PERIOD_LSB_PTR  ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define Mouth_PERIOD_LSB      (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define Mouth_PERIOD_LSB_PTR  ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (Mouth_PWMModeIsCenterAligned) */

            #define Mouth_COMPARE1_LSB       (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Mouth_COMPARE1_LSB_PTR   ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Mouth_COMPARE2_LSB       (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Mouth_COMPARE2_LSB_PTR   ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Mouth_COUNTERCAP_LSB     (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Mouth_COUNTERCAP_LSB_PTR ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Mouth_COUNTER_LSB        (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Mouth_COUNTER_LSB_PTR    ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Mouth_CAPTURE_LSB        (*(reg16 *) Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define Mouth_CAPTURE_LSB_PTR    ((reg16 *)  Mouth_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define Mouth_AUX_CONTROLDP1          (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define Mouth_AUX_CONTROLDP1_PTR      ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Mouth_Resolution == 8) */

   #define Mouth_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define Mouth_AUX_CONTROLDP0          (*(reg8 *)  Mouth_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define Mouth_AUX_CONTROLDP0_PTR      ((reg8 *)   Mouth_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Mouth_UsingFixedFunction) */

#if(Mouth_KillModeMinTime )
    #define Mouth_KILLMODEMINTIME        (*(reg8 *)  Mouth_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Mouth_KILLMODEMINTIME_PTR    ((reg8 *)   Mouth_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Mouth_KillModeMinTime ) */

#if(Mouth_DeadBandMode == Mouth__B_PWM__DBM_256_CLOCKS)
    #define Mouth_DEADBAND_COUNT         (*(reg8 *)  Mouth_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Mouth_DEADBAND_COUNT_PTR     ((reg8 *)   Mouth_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Mouth_DEADBAND_LSB_PTR       ((reg8 *)   Mouth_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Mouth_DEADBAND_LSB           (*(reg8 *)  Mouth_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Mouth_DeadBandMode == Mouth__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Mouth_UsingFixedFunction)
        #define Mouth_DEADBAND_COUNT         (*(reg8 *)  Mouth_PWMHW__CFG0)
        #define Mouth_DEADBAND_COUNT_PTR     ((reg8 *)   Mouth_PWMHW__CFG0)
        #define Mouth_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Mouth_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Mouth_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Mouth_DEADBAND_COUNT         (*(reg8 *)  Mouth_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Mouth_DEADBAND_COUNT_PTR     ((reg8 *)   Mouth_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Mouth_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Mouth_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define Mouth_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (Mouth_UsingFixedFunction) */
#endif /* (Mouth_DeadBandMode == Mouth__B_PWM__DBM_256_CLOCKS) */



#if (Mouth_UsingFixedFunction)
    #define Mouth_STATUS                 (*(reg8 *) Mouth_PWMHW__SR0)
    #define Mouth_STATUS_PTR             ((reg8 *) Mouth_PWMHW__SR0)
    #define Mouth_STATUS_MASK            (*(reg8 *) Mouth_PWMHW__SR0)
    #define Mouth_STATUS_MASK_PTR        ((reg8 *) Mouth_PWMHW__SR0)
    #define Mouth_CONTROL                (*(reg8 *) Mouth_PWMHW__CFG0)
    #define Mouth_CONTROL_PTR            ((reg8 *) Mouth_PWMHW__CFG0)
    #define Mouth_CONTROL2               (*(reg8 *) Mouth_PWMHW__CFG1)
    #define Mouth_CONTROL3               (*(reg8 *) Mouth_PWMHW__CFG2)
    #define Mouth_GLOBAL_ENABLE          (*(reg8 *) Mouth_PWMHW__PM_ACT_CFG)
    #define Mouth_GLOBAL_ENABLE_PTR      ( (reg8 *) Mouth_PWMHW__PM_ACT_CFG)
    #define Mouth_GLOBAL_STBY_ENABLE     (*(reg8 *) Mouth_PWMHW__PM_STBY_CFG)
    #define Mouth_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) Mouth_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Mouth_BLOCK_EN_MASK          (Mouth_PWMHW__PM_ACT_MSK)
    #define Mouth_BLOCK_STBY_EN_MASK     (Mouth_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define Mouth_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define Mouth_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define Mouth_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define Mouth_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define Mouth_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define Mouth_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define Mouth_CTRL_ENABLE            (uint8)((uint8)0x01u << Mouth_CTRL_ENABLE_SHIFT)
    #define Mouth_CTRL_RESET             (uint8)((uint8)0x01u << Mouth_CTRL_RESET_SHIFT)
    #define Mouth_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Mouth_CTRL_CMPMODE2_SHIFT)
    #define Mouth_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Mouth_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Mouth_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define Mouth_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Mouth_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define Mouth_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define Mouth_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define Mouth_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define Mouth_STATUS_TC_INT_EN_MASK_SHIFT            (Mouth_STATUS_TC_SHIFT - 4u)
    #define Mouth_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define Mouth_STATUS_CMP1_INT_EN_MASK_SHIFT          (Mouth_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define Mouth_STATUS_TC              (uint8)((uint8)0x01u << Mouth_STATUS_TC_SHIFT)
    #define Mouth_STATUS_CMP1            (uint8)((uint8)0x01u << Mouth_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define Mouth_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Mouth_STATUS_TC >> 4u)
    #define Mouth_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Mouth_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define Mouth_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define Mouth_RT1_MASK              (uint8)((uint8)0x03u << Mouth_RT1_SHIFT)
    #define Mouth_SYNC                  (uint8)((uint8)0x03u << Mouth_RT1_SHIFT)
    #define Mouth_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define Mouth_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Mouth_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define Mouth_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Mouth_SYNCDSI_SHIFT)


#else
    #define Mouth_STATUS                (*(reg8 *)   Mouth_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Mouth_STATUS_PTR            ((reg8 *)    Mouth_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Mouth_STATUS_MASK           (*(reg8 *)   Mouth_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Mouth_STATUS_MASK_PTR       ((reg8 *)    Mouth_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Mouth_STATUS_AUX_CTRL       (*(reg8 *)   Mouth_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Mouth_CONTROL               (*(reg8 *)   Mouth_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Mouth_CONTROL_PTR           ((reg8 *)    Mouth_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define Mouth_CTRL_ENABLE_SHIFT      (0x07u)
    #define Mouth_CTRL_RESET_SHIFT       (0x06u)
    #define Mouth_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define Mouth_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define Mouth_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define Mouth_CTRL_ENABLE            (uint8)((uint8)0x01u << Mouth_CTRL_ENABLE_SHIFT)
    #define Mouth_CTRL_RESET             (uint8)((uint8)0x01u << Mouth_CTRL_RESET_SHIFT)
    #define Mouth_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Mouth_CTRL_CMPMODE2_SHIFT)
    #define Mouth_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Mouth_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define Mouth_STATUS_KILL_SHIFT          (0x05u)
    #define Mouth_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define Mouth_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define Mouth_STATUS_TC_SHIFT            (0x02u)
    #define Mouth_STATUS_CMP2_SHIFT          (0x01u)
    #define Mouth_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Mouth_STATUS_KILL_INT_EN_MASK_SHIFT          (Mouth_STATUS_KILL_SHIFT)
    #define Mouth_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (Mouth_STATUS_FIFONEMPTY_SHIFT)
    #define Mouth_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (Mouth_STATUS_FIFOFULL_SHIFT)
    #define Mouth_STATUS_TC_INT_EN_MASK_SHIFT            (Mouth_STATUS_TC_SHIFT)
    #define Mouth_STATUS_CMP2_INT_EN_MASK_SHIFT          (Mouth_STATUS_CMP2_SHIFT)
    #define Mouth_STATUS_CMP1_INT_EN_MASK_SHIFT          (Mouth_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define Mouth_STATUS_KILL            (uint8)((uint8)0x00u << Mouth_STATUS_KILL_SHIFT )
    #define Mouth_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Mouth_STATUS_FIFOFULL_SHIFT)
    #define Mouth_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Mouth_STATUS_FIFONEMPTY_SHIFT)
    #define Mouth_STATUS_TC              (uint8)((uint8)0x01u << Mouth_STATUS_TC_SHIFT)
    #define Mouth_STATUS_CMP2            (uint8)((uint8)0x01u << Mouth_STATUS_CMP2_SHIFT)
    #define Mouth_STATUS_CMP1            (uint8)((uint8)0x01u << Mouth_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Mouth_STATUS_KILL_INT_EN_MASK            (Mouth_STATUS_KILL)
    #define Mouth_STATUS_FIFOFULL_INT_EN_MASK        (Mouth_STATUS_FIFOFULL)
    #define Mouth_STATUS_FIFONEMPTY_INT_EN_MASK      (Mouth_STATUS_FIFONEMPTY)
    #define Mouth_STATUS_TC_INT_EN_MASK              (Mouth_STATUS_TC)
    #define Mouth_STATUS_CMP2_INT_EN_MASK            (Mouth_STATUS_CMP2)
    #define Mouth_STATUS_CMP1_INT_EN_MASK            (Mouth_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define Mouth_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define Mouth_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define Mouth_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define Mouth_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define Mouth_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* Mouth_UsingFixedFunction */

#endif  /* CY_PWM_Mouth_H */


/* [] END OF FILE */
