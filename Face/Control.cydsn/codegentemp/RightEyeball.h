/*******************************************************************************
* File Name: RightEyeball.h
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

#if !defined(CY_PWM_RightEyeball_H)
#define CY_PWM_RightEyeball_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 RightEyeball_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define RightEyeball_Resolution                     (16u)
#define RightEyeball_UsingFixedFunction             (0u)
#define RightEyeball_DeadBandMode                   (0u)
#define RightEyeball_KillModeMinTime                (0u)
#define RightEyeball_KillMode                       (0u)
#define RightEyeball_PWMMode                        (1u)
#define RightEyeball_PWMModeIsCenterAligned         (0u)
#define RightEyeball_DeadBandUsed                   (0u)
#define RightEyeball_DeadBand2_4                    (0u)

#if !defined(RightEyeball_PWMUDB_genblk8_stsreg__REMOVED)
    #define RightEyeball_UseStatus                  (1u)
#else
    #define RightEyeball_UseStatus                  (0u)
#endif /* !defined(RightEyeball_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(RightEyeball_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define RightEyeball_UseControl                 (1u)
#else
    #define RightEyeball_UseControl                 (0u)
#endif /* !defined(RightEyeball_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define RightEyeball_UseOneCompareMode              (0u)
#define RightEyeball_MinimumKillTime                (1u)
#define RightEyeball_EnableMode                     (0u)

#define RightEyeball_CompareMode1SW                 (0u)
#define RightEyeball_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define RightEyeball__B_PWM__DISABLED 0
#define RightEyeball__B_PWM__ASYNCHRONOUS 1
#define RightEyeball__B_PWM__SINGLECYCLE 2
#define RightEyeball__B_PWM__LATCHED 3
#define RightEyeball__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define RightEyeball__B_PWM__DBMDISABLED 0
#define RightEyeball__B_PWM__DBM_2_4_CLOCKS 1
#define RightEyeball__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define RightEyeball__B_PWM__ONE_OUTPUT 0
#define RightEyeball__B_PWM__TWO_OUTPUTS 1
#define RightEyeball__B_PWM__DUAL_EDGE 2
#define RightEyeball__B_PWM__CENTER_ALIGN 3
#define RightEyeball__B_PWM__DITHER 5
#define RightEyeball__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define RightEyeball__B_PWM__LESS_THAN 1
#define RightEyeball__B_PWM__LESS_THAN_OR_EQUAL 2
#define RightEyeball__B_PWM__GREATER_THAN 3
#define RightEyeball__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define RightEyeball__B_PWM__EQUAL 0
#define RightEyeball__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!RightEyeball_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!RightEyeball_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!RightEyeball_PWMModeIsCenterAligned) */
        #if (RightEyeball_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (RightEyeball_UseStatus) */

        /* Backup for Deadband parameters */
        #if(RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_256_CLOCKS || \
            RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(RightEyeball_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (RightEyeball_KillModeMinTime) */

        /* Backup control register */
        #if(RightEyeball_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (RightEyeball_UseControl) */

    #endif /* (!RightEyeball_UsingFixedFunction) */

}RightEyeball_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    RightEyeball_Start(void) ;
void    RightEyeball_Stop(void) ;

#if (RightEyeball_UseStatus || RightEyeball_UsingFixedFunction)
    void  RightEyeball_SetInterruptMode(uint8 interruptMode) ;
    uint8 RightEyeball_ReadStatusRegister(void) ;
#endif /* (RightEyeball_UseStatus || RightEyeball_UsingFixedFunction) */

#define RightEyeball_GetInterruptSource() RightEyeball_ReadStatusRegister()

#if (RightEyeball_UseControl)
    uint8 RightEyeball_ReadControlRegister(void) ;
    void  RightEyeball_WriteControlRegister(uint8 control)
          ;
#endif /* (RightEyeball_UseControl) */

#if (RightEyeball_UseOneCompareMode)
   #if (RightEyeball_CompareMode1SW)
       void    RightEyeball_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (RightEyeball_CompareMode1SW) */
#else
    #if (RightEyeball_CompareMode1SW)
        void    RightEyeball_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (RightEyeball_CompareMode1SW) */
    #if (RightEyeball_CompareMode2SW)
        void    RightEyeball_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (RightEyeball_CompareMode2SW) */
#endif /* (RightEyeball_UseOneCompareMode) */

#if (!RightEyeball_UsingFixedFunction)
    uint16   RightEyeball_ReadCounter(void) ;
    uint16 RightEyeball_ReadCapture(void) ;

    #if (RightEyeball_UseStatus)
            void RightEyeball_ClearFIFO(void) ;
    #endif /* (RightEyeball_UseStatus) */

    void    RightEyeball_WriteCounter(uint16 counter)
            ;
#endif /* (!RightEyeball_UsingFixedFunction) */

void    RightEyeball_WritePeriod(uint16 period)
        ;
uint16 RightEyeball_ReadPeriod(void) ;

#if (RightEyeball_UseOneCompareMode)
    void    RightEyeball_WriteCompare(uint16 compare)
            ;
    uint16 RightEyeball_ReadCompare(void) ;
#else
    void    RightEyeball_WriteCompare1(uint16 compare)
            ;
    uint16 RightEyeball_ReadCompare1(void) ;
    void    RightEyeball_WriteCompare2(uint16 compare)
            ;
    uint16 RightEyeball_ReadCompare2(void) ;
#endif /* (RightEyeball_UseOneCompareMode) */


#if (RightEyeball_DeadBandUsed)
    void    RightEyeball_WriteDeadTime(uint8 deadtime) ;
    uint8   RightEyeball_ReadDeadTime(void) ;
#endif /* (RightEyeball_DeadBandUsed) */

#if ( RightEyeball_KillModeMinTime)
    void RightEyeball_WriteKillTime(uint8 killtime) ;
    uint8 RightEyeball_ReadKillTime(void) ;
#endif /* ( RightEyeball_KillModeMinTime) */

void RightEyeball_Init(void) ;
void RightEyeball_Enable(void) ;
void RightEyeball_Sleep(void) ;
void RightEyeball_Wakeup(void) ;
void RightEyeball_SaveConfig(void) ;
void RightEyeball_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define RightEyeball_INIT_PERIOD_VALUE          (20000u)
#define RightEyeball_INIT_COMPARE_VALUE1        (2000u)
#define RightEyeball_INIT_COMPARE_VALUE2        (2000u)
#define RightEyeball_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    RightEyeball_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    RightEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    RightEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    RightEyeball_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define RightEyeball_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  RightEyeball_CTRL_CMPMODE2_SHIFT)
#define RightEyeball_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  RightEyeball_CTRL_CMPMODE1_SHIFT)
#define RightEyeball_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (RightEyeball_UsingFixedFunction)
   #define RightEyeball_PERIOD_LSB              (*(reg16 *) RightEyeball_PWMHW__PER0)
   #define RightEyeball_PERIOD_LSB_PTR          ( (reg16 *) RightEyeball_PWMHW__PER0)
   #define RightEyeball_COMPARE1_LSB            (*(reg16 *) RightEyeball_PWMHW__CNT_CMP0)
   #define RightEyeball_COMPARE1_LSB_PTR        ( (reg16 *) RightEyeball_PWMHW__CNT_CMP0)
   #define RightEyeball_COMPARE2_LSB            (0x00u)
   #define RightEyeball_COMPARE2_LSB_PTR        (0x00u)
   #define RightEyeball_COUNTER_LSB             (*(reg16 *) RightEyeball_PWMHW__CNT_CMP0)
   #define RightEyeball_COUNTER_LSB_PTR         ( (reg16 *) RightEyeball_PWMHW__CNT_CMP0)
   #define RightEyeball_CAPTURE_LSB             (*(reg16 *) RightEyeball_PWMHW__CAP0)
   #define RightEyeball_CAPTURE_LSB_PTR         ( (reg16 *) RightEyeball_PWMHW__CAP0)
   #define RightEyeball_RT1                     (*(reg8 *)  RightEyeball_PWMHW__RT1)
   #define RightEyeball_RT1_PTR                 ( (reg8 *)  RightEyeball_PWMHW__RT1)

#else
   #if (RightEyeball_Resolution == 8u) /* 8bit - PWM */

       #if(RightEyeball_PWMModeIsCenterAligned)
           #define RightEyeball_PERIOD_LSB      (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define RightEyeball_PERIOD_LSB_PTR  ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define RightEyeball_PERIOD_LSB      (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define RightEyeball_PERIOD_LSB_PTR  ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (RightEyeball_PWMModeIsCenterAligned) */

       #define RightEyeball_COMPARE1_LSB        (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define RightEyeball_COMPARE1_LSB_PTR    ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define RightEyeball_COMPARE2_LSB        (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define RightEyeball_COMPARE2_LSB_PTR    ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define RightEyeball_COUNTERCAP_LSB      (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define RightEyeball_COUNTERCAP_LSB_PTR  ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define RightEyeball_COUNTER_LSB         (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define RightEyeball_COUNTER_LSB_PTR     ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define RightEyeball_CAPTURE_LSB         (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define RightEyeball_CAPTURE_LSB_PTR     ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(RightEyeball_PWMModeIsCenterAligned)
               #define RightEyeball_PERIOD_LSB      (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define RightEyeball_PERIOD_LSB_PTR  ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define RightEyeball_PERIOD_LSB      (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define RightEyeball_PERIOD_LSB_PTR  ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (RightEyeball_PWMModeIsCenterAligned) */

            #define RightEyeball_COMPARE1_LSB       (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define RightEyeball_COMPARE1_LSB_PTR   ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define RightEyeball_COMPARE2_LSB       (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define RightEyeball_COMPARE2_LSB_PTR   ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define RightEyeball_COUNTERCAP_LSB     (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define RightEyeball_COUNTERCAP_LSB_PTR ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define RightEyeball_COUNTER_LSB        (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define RightEyeball_COUNTER_LSB_PTR    ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define RightEyeball_CAPTURE_LSB        (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define RightEyeball_CAPTURE_LSB_PTR    ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(RightEyeball_PWMModeIsCenterAligned)
               #define RightEyeball_PERIOD_LSB      (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define RightEyeball_PERIOD_LSB_PTR  ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define RightEyeball_PERIOD_LSB      (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define RightEyeball_PERIOD_LSB_PTR  ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (RightEyeball_PWMModeIsCenterAligned) */

            #define RightEyeball_COMPARE1_LSB       (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define RightEyeball_COMPARE1_LSB_PTR   ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define RightEyeball_COMPARE2_LSB       (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define RightEyeball_COMPARE2_LSB_PTR   ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define RightEyeball_COUNTERCAP_LSB     (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define RightEyeball_COUNTERCAP_LSB_PTR ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define RightEyeball_COUNTER_LSB        (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define RightEyeball_COUNTER_LSB_PTR    ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define RightEyeball_CAPTURE_LSB        (*(reg16 *) RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define RightEyeball_CAPTURE_LSB_PTR    ((reg16 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define RightEyeball_AUX_CONTROLDP1          (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define RightEyeball_AUX_CONTROLDP1_PTR      ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (RightEyeball_Resolution == 8) */

   #define RightEyeball_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define RightEyeball_AUX_CONTROLDP0          (*(reg8 *)  RightEyeball_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define RightEyeball_AUX_CONTROLDP0_PTR      ((reg8 *)   RightEyeball_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (RightEyeball_UsingFixedFunction) */

#if(RightEyeball_KillModeMinTime )
    #define RightEyeball_KILLMODEMINTIME        (*(reg8 *)  RightEyeball_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define RightEyeball_KILLMODEMINTIME_PTR    ((reg8 *)   RightEyeball_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (RightEyeball_KillModeMinTime ) */

#if(RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_256_CLOCKS)
    #define RightEyeball_DEADBAND_COUNT         (*(reg8 *)  RightEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define RightEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   RightEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define RightEyeball_DEADBAND_LSB_PTR       ((reg8 *)   RightEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define RightEyeball_DEADBAND_LSB           (*(reg8 *)  RightEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (RightEyeball_UsingFixedFunction)
        #define RightEyeball_DEADBAND_COUNT         (*(reg8 *)  RightEyeball_PWMHW__CFG0)
        #define RightEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   RightEyeball_PWMHW__CFG0)
        #define RightEyeball_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << RightEyeball_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define RightEyeball_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define RightEyeball_DEADBAND_COUNT         (*(reg8 *)  RightEyeball_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define RightEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   RightEyeball_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define RightEyeball_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << RightEyeball_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define RightEyeball_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (RightEyeball_UsingFixedFunction) */
#endif /* (RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_256_CLOCKS) */



#if (RightEyeball_UsingFixedFunction)
    #define RightEyeball_STATUS                 (*(reg8 *) RightEyeball_PWMHW__SR0)
    #define RightEyeball_STATUS_PTR             ((reg8 *) RightEyeball_PWMHW__SR0)
    #define RightEyeball_STATUS_MASK            (*(reg8 *) RightEyeball_PWMHW__SR0)
    #define RightEyeball_STATUS_MASK_PTR        ((reg8 *) RightEyeball_PWMHW__SR0)
    #define RightEyeball_CONTROL                (*(reg8 *) RightEyeball_PWMHW__CFG0)
    #define RightEyeball_CONTROL_PTR            ((reg8 *) RightEyeball_PWMHW__CFG0)
    #define RightEyeball_CONTROL2               (*(reg8 *) RightEyeball_PWMHW__CFG1)
    #define RightEyeball_CONTROL3               (*(reg8 *) RightEyeball_PWMHW__CFG2)
    #define RightEyeball_GLOBAL_ENABLE          (*(reg8 *) RightEyeball_PWMHW__PM_ACT_CFG)
    #define RightEyeball_GLOBAL_ENABLE_PTR      ( (reg8 *) RightEyeball_PWMHW__PM_ACT_CFG)
    #define RightEyeball_GLOBAL_STBY_ENABLE     (*(reg8 *) RightEyeball_PWMHW__PM_STBY_CFG)
    #define RightEyeball_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) RightEyeball_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define RightEyeball_BLOCK_EN_MASK          (RightEyeball_PWMHW__PM_ACT_MSK)
    #define RightEyeball_BLOCK_STBY_EN_MASK     (RightEyeball_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define RightEyeball_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define RightEyeball_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define RightEyeball_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define RightEyeball_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define RightEyeball_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define RightEyeball_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define RightEyeball_CTRL_ENABLE            (uint8)((uint8)0x01u << RightEyeball_CTRL_ENABLE_SHIFT)
    #define RightEyeball_CTRL_RESET             (uint8)((uint8)0x01u << RightEyeball_CTRL_RESET_SHIFT)
    #define RightEyeball_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << RightEyeball_CTRL_CMPMODE2_SHIFT)
    #define RightEyeball_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << RightEyeball_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define RightEyeball_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define RightEyeball_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << RightEyeball_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define RightEyeball_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define RightEyeball_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define RightEyeball_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define RightEyeball_STATUS_TC_INT_EN_MASK_SHIFT            (RightEyeball_STATUS_TC_SHIFT - 4u)
    #define RightEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define RightEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT          (RightEyeball_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define RightEyeball_STATUS_TC              (uint8)((uint8)0x01u << RightEyeball_STATUS_TC_SHIFT)
    #define RightEyeball_STATUS_CMP1            (uint8)((uint8)0x01u << RightEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define RightEyeball_STATUS_TC_INT_EN_MASK              (uint8)((uint8)RightEyeball_STATUS_TC >> 4u)
    #define RightEyeball_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)RightEyeball_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define RightEyeball_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define RightEyeball_RT1_MASK              (uint8)((uint8)0x03u << RightEyeball_RT1_SHIFT)
    #define RightEyeball_SYNC                  (uint8)((uint8)0x03u << RightEyeball_RT1_SHIFT)
    #define RightEyeball_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define RightEyeball_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << RightEyeball_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define RightEyeball_SYNCDSI_EN            (uint8)((uint8)0x0Fu << RightEyeball_SYNCDSI_SHIFT)


#else
    #define RightEyeball_STATUS                (*(reg8 *)   RightEyeball_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define RightEyeball_STATUS_PTR            ((reg8 *)    RightEyeball_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define RightEyeball_STATUS_MASK           (*(reg8 *)   RightEyeball_PWMUDB_genblk8_stsreg__MASK_REG)
    #define RightEyeball_STATUS_MASK_PTR       ((reg8 *)    RightEyeball_PWMUDB_genblk8_stsreg__MASK_REG)
    #define RightEyeball_STATUS_AUX_CTRL       (*(reg8 *)   RightEyeball_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define RightEyeball_CONTROL               (*(reg8 *)   RightEyeball_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define RightEyeball_CONTROL_PTR           ((reg8 *)    RightEyeball_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define RightEyeball_CTRL_ENABLE_SHIFT      (0x07u)
    #define RightEyeball_CTRL_RESET_SHIFT       (0x06u)
    #define RightEyeball_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define RightEyeball_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define RightEyeball_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define RightEyeball_CTRL_ENABLE            (uint8)((uint8)0x01u << RightEyeball_CTRL_ENABLE_SHIFT)
    #define RightEyeball_CTRL_RESET             (uint8)((uint8)0x01u << RightEyeball_CTRL_RESET_SHIFT)
    #define RightEyeball_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << RightEyeball_CTRL_CMPMODE2_SHIFT)
    #define RightEyeball_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << RightEyeball_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define RightEyeball_STATUS_KILL_SHIFT          (0x05u)
    #define RightEyeball_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define RightEyeball_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define RightEyeball_STATUS_TC_SHIFT            (0x02u)
    #define RightEyeball_STATUS_CMP2_SHIFT          (0x01u)
    #define RightEyeball_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define RightEyeball_STATUS_KILL_INT_EN_MASK_SHIFT          (RightEyeball_STATUS_KILL_SHIFT)
    #define RightEyeball_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (RightEyeball_STATUS_FIFONEMPTY_SHIFT)
    #define RightEyeball_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (RightEyeball_STATUS_FIFOFULL_SHIFT)
    #define RightEyeball_STATUS_TC_INT_EN_MASK_SHIFT            (RightEyeball_STATUS_TC_SHIFT)
    #define RightEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT          (RightEyeball_STATUS_CMP2_SHIFT)
    #define RightEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT          (RightEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define RightEyeball_STATUS_KILL            (uint8)((uint8)0x00u << RightEyeball_STATUS_KILL_SHIFT )
    #define RightEyeball_STATUS_FIFOFULL        (uint8)((uint8)0x01u << RightEyeball_STATUS_FIFOFULL_SHIFT)
    #define RightEyeball_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << RightEyeball_STATUS_FIFONEMPTY_SHIFT)
    #define RightEyeball_STATUS_TC              (uint8)((uint8)0x01u << RightEyeball_STATUS_TC_SHIFT)
    #define RightEyeball_STATUS_CMP2            (uint8)((uint8)0x01u << RightEyeball_STATUS_CMP2_SHIFT)
    #define RightEyeball_STATUS_CMP1            (uint8)((uint8)0x01u << RightEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define RightEyeball_STATUS_KILL_INT_EN_MASK            (RightEyeball_STATUS_KILL)
    #define RightEyeball_STATUS_FIFOFULL_INT_EN_MASK        (RightEyeball_STATUS_FIFOFULL)
    #define RightEyeball_STATUS_FIFONEMPTY_INT_EN_MASK      (RightEyeball_STATUS_FIFONEMPTY)
    #define RightEyeball_STATUS_TC_INT_EN_MASK              (RightEyeball_STATUS_TC)
    #define RightEyeball_STATUS_CMP2_INT_EN_MASK            (RightEyeball_STATUS_CMP2)
    #define RightEyeball_STATUS_CMP1_INT_EN_MASK            (RightEyeball_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define RightEyeball_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define RightEyeball_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define RightEyeball_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define RightEyeball_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define RightEyeball_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* RightEyeball_UsingFixedFunction */

#endif  /* CY_PWM_RightEyeball_H */


/* [] END OF FILE */
