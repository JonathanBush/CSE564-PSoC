/*******************************************************************************
* File Name: LeftEyeball.h
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

#if !defined(CY_PWM_LeftEyeball_H)
#define CY_PWM_LeftEyeball_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 LeftEyeball_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define LeftEyeball_Resolution                     (16u)
#define LeftEyeball_UsingFixedFunction             (0u)
#define LeftEyeball_DeadBandMode                   (0u)
#define LeftEyeball_KillModeMinTime                (0u)
#define LeftEyeball_KillMode                       (0u)
#define LeftEyeball_PWMMode                        (1u)
#define LeftEyeball_PWMModeIsCenterAligned         (0u)
#define LeftEyeball_DeadBandUsed                   (0u)
#define LeftEyeball_DeadBand2_4                    (0u)

#if !defined(LeftEyeball_PWMUDB_genblk8_stsreg__REMOVED)
    #define LeftEyeball_UseStatus                  (1u)
#else
    #define LeftEyeball_UseStatus                  (0u)
#endif /* !defined(LeftEyeball_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(LeftEyeball_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define LeftEyeball_UseControl                 (1u)
#else
    #define LeftEyeball_UseControl                 (0u)
#endif /* !defined(LeftEyeball_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define LeftEyeball_UseOneCompareMode              (0u)
#define LeftEyeball_MinimumKillTime                (1u)
#define LeftEyeball_EnableMode                     (0u)

#define LeftEyeball_CompareMode1SW                 (0u)
#define LeftEyeball_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define LeftEyeball__B_PWM__DISABLED 0
#define LeftEyeball__B_PWM__ASYNCHRONOUS 1
#define LeftEyeball__B_PWM__SINGLECYCLE 2
#define LeftEyeball__B_PWM__LATCHED 3
#define LeftEyeball__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define LeftEyeball__B_PWM__DBMDISABLED 0
#define LeftEyeball__B_PWM__DBM_2_4_CLOCKS 1
#define LeftEyeball__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define LeftEyeball__B_PWM__ONE_OUTPUT 0
#define LeftEyeball__B_PWM__TWO_OUTPUTS 1
#define LeftEyeball__B_PWM__DUAL_EDGE 2
#define LeftEyeball__B_PWM__CENTER_ALIGN 3
#define LeftEyeball__B_PWM__DITHER 5
#define LeftEyeball__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define LeftEyeball__B_PWM__LESS_THAN 1
#define LeftEyeball__B_PWM__LESS_THAN_OR_EQUAL 2
#define LeftEyeball__B_PWM__GREATER_THAN 3
#define LeftEyeball__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define LeftEyeball__B_PWM__EQUAL 0
#define LeftEyeball__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!LeftEyeball_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!LeftEyeball_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!LeftEyeball_PWMModeIsCenterAligned) */
        #if (LeftEyeball_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (LeftEyeball_UseStatus) */

        /* Backup for Deadband parameters */
        #if(LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_256_CLOCKS || \
            LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(LeftEyeball_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (LeftEyeball_KillModeMinTime) */

        /* Backup control register */
        #if(LeftEyeball_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (LeftEyeball_UseControl) */

    #endif /* (!LeftEyeball_UsingFixedFunction) */

}LeftEyeball_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    LeftEyeball_Start(void) ;
void    LeftEyeball_Stop(void) ;

#if (LeftEyeball_UseStatus || LeftEyeball_UsingFixedFunction)
    void  LeftEyeball_SetInterruptMode(uint8 interruptMode) ;
    uint8 LeftEyeball_ReadStatusRegister(void) ;
#endif /* (LeftEyeball_UseStatus || LeftEyeball_UsingFixedFunction) */

#define LeftEyeball_GetInterruptSource() LeftEyeball_ReadStatusRegister()

#if (LeftEyeball_UseControl)
    uint8 LeftEyeball_ReadControlRegister(void) ;
    void  LeftEyeball_WriteControlRegister(uint8 control)
          ;
#endif /* (LeftEyeball_UseControl) */

#if (LeftEyeball_UseOneCompareMode)
   #if (LeftEyeball_CompareMode1SW)
       void    LeftEyeball_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (LeftEyeball_CompareMode1SW) */
#else
    #if (LeftEyeball_CompareMode1SW)
        void    LeftEyeball_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (LeftEyeball_CompareMode1SW) */
    #if (LeftEyeball_CompareMode2SW)
        void    LeftEyeball_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (LeftEyeball_CompareMode2SW) */
#endif /* (LeftEyeball_UseOneCompareMode) */

#if (!LeftEyeball_UsingFixedFunction)
    uint16   LeftEyeball_ReadCounter(void) ;
    uint16 LeftEyeball_ReadCapture(void) ;

    #if (LeftEyeball_UseStatus)
            void LeftEyeball_ClearFIFO(void) ;
    #endif /* (LeftEyeball_UseStatus) */

    void    LeftEyeball_WriteCounter(uint16 counter)
            ;
#endif /* (!LeftEyeball_UsingFixedFunction) */

void    LeftEyeball_WritePeriod(uint16 period)
        ;
uint16 LeftEyeball_ReadPeriod(void) ;

#if (LeftEyeball_UseOneCompareMode)
    void    LeftEyeball_WriteCompare(uint16 compare)
            ;
    uint16 LeftEyeball_ReadCompare(void) ;
#else
    void    LeftEyeball_WriteCompare1(uint16 compare)
            ;
    uint16 LeftEyeball_ReadCompare1(void) ;
    void    LeftEyeball_WriteCompare2(uint16 compare)
            ;
    uint16 LeftEyeball_ReadCompare2(void) ;
#endif /* (LeftEyeball_UseOneCompareMode) */


#if (LeftEyeball_DeadBandUsed)
    void    LeftEyeball_WriteDeadTime(uint8 deadtime) ;
    uint8   LeftEyeball_ReadDeadTime(void) ;
#endif /* (LeftEyeball_DeadBandUsed) */

#if ( LeftEyeball_KillModeMinTime)
    void LeftEyeball_WriteKillTime(uint8 killtime) ;
    uint8 LeftEyeball_ReadKillTime(void) ;
#endif /* ( LeftEyeball_KillModeMinTime) */

void LeftEyeball_Init(void) ;
void LeftEyeball_Enable(void) ;
void LeftEyeball_Sleep(void) ;
void LeftEyeball_Wakeup(void) ;
void LeftEyeball_SaveConfig(void) ;
void LeftEyeball_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define LeftEyeball_INIT_PERIOD_VALUE          (20000u)
#define LeftEyeball_INIT_COMPARE_VALUE1        (2000u)
#define LeftEyeball_INIT_COMPARE_VALUE2        (2000u)
#define LeftEyeball_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    LeftEyeball_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LeftEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LeftEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LeftEyeball_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define LeftEyeball_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  LeftEyeball_CTRL_CMPMODE2_SHIFT)
#define LeftEyeball_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  LeftEyeball_CTRL_CMPMODE1_SHIFT)
#define LeftEyeball_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (LeftEyeball_UsingFixedFunction)
   #define LeftEyeball_PERIOD_LSB              (*(reg16 *) LeftEyeball_PWMHW__PER0)
   #define LeftEyeball_PERIOD_LSB_PTR          ( (reg16 *) LeftEyeball_PWMHW__PER0)
   #define LeftEyeball_COMPARE1_LSB            (*(reg16 *) LeftEyeball_PWMHW__CNT_CMP0)
   #define LeftEyeball_COMPARE1_LSB_PTR        ( (reg16 *) LeftEyeball_PWMHW__CNT_CMP0)
   #define LeftEyeball_COMPARE2_LSB            (0x00u)
   #define LeftEyeball_COMPARE2_LSB_PTR        (0x00u)
   #define LeftEyeball_COUNTER_LSB             (*(reg16 *) LeftEyeball_PWMHW__CNT_CMP0)
   #define LeftEyeball_COUNTER_LSB_PTR         ( (reg16 *) LeftEyeball_PWMHW__CNT_CMP0)
   #define LeftEyeball_CAPTURE_LSB             (*(reg16 *) LeftEyeball_PWMHW__CAP0)
   #define LeftEyeball_CAPTURE_LSB_PTR         ( (reg16 *) LeftEyeball_PWMHW__CAP0)
   #define LeftEyeball_RT1                     (*(reg8 *)  LeftEyeball_PWMHW__RT1)
   #define LeftEyeball_RT1_PTR                 ( (reg8 *)  LeftEyeball_PWMHW__RT1)

#else
   #if (LeftEyeball_Resolution == 8u) /* 8bit - PWM */

       #if(LeftEyeball_PWMModeIsCenterAligned)
           #define LeftEyeball_PERIOD_LSB      (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define LeftEyeball_PERIOD_LSB_PTR  ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define LeftEyeball_PERIOD_LSB      (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define LeftEyeball_PERIOD_LSB_PTR  ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (LeftEyeball_PWMModeIsCenterAligned) */

       #define LeftEyeball_COMPARE1_LSB        (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define LeftEyeball_COMPARE1_LSB_PTR    ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define LeftEyeball_COMPARE2_LSB        (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define LeftEyeball_COMPARE2_LSB_PTR    ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define LeftEyeball_COUNTERCAP_LSB      (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define LeftEyeball_COUNTERCAP_LSB_PTR  ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define LeftEyeball_COUNTER_LSB         (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define LeftEyeball_COUNTER_LSB_PTR     ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define LeftEyeball_CAPTURE_LSB         (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define LeftEyeball_CAPTURE_LSB_PTR     ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(LeftEyeball_PWMModeIsCenterAligned)
               #define LeftEyeball_PERIOD_LSB      (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define LeftEyeball_PERIOD_LSB_PTR  ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define LeftEyeball_PERIOD_LSB      (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define LeftEyeball_PERIOD_LSB_PTR  ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (LeftEyeball_PWMModeIsCenterAligned) */

            #define LeftEyeball_COMPARE1_LSB       (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define LeftEyeball_COMPARE1_LSB_PTR   ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define LeftEyeball_COMPARE2_LSB       (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define LeftEyeball_COMPARE2_LSB_PTR   ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define LeftEyeball_COUNTERCAP_LSB     (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define LeftEyeball_COUNTERCAP_LSB_PTR ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define LeftEyeball_COUNTER_LSB        (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define LeftEyeball_COUNTER_LSB_PTR    ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define LeftEyeball_CAPTURE_LSB        (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define LeftEyeball_CAPTURE_LSB_PTR    ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(LeftEyeball_PWMModeIsCenterAligned)
               #define LeftEyeball_PERIOD_LSB      (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define LeftEyeball_PERIOD_LSB_PTR  ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define LeftEyeball_PERIOD_LSB      (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define LeftEyeball_PERIOD_LSB_PTR  ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (LeftEyeball_PWMModeIsCenterAligned) */

            #define LeftEyeball_COMPARE1_LSB       (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define LeftEyeball_COMPARE1_LSB_PTR   ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define LeftEyeball_COMPARE2_LSB       (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define LeftEyeball_COMPARE2_LSB_PTR   ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define LeftEyeball_COUNTERCAP_LSB     (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define LeftEyeball_COUNTERCAP_LSB_PTR ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define LeftEyeball_COUNTER_LSB        (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define LeftEyeball_COUNTER_LSB_PTR    ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define LeftEyeball_CAPTURE_LSB        (*(reg16 *) LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define LeftEyeball_CAPTURE_LSB_PTR    ((reg16 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define LeftEyeball_AUX_CONTROLDP1          (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define LeftEyeball_AUX_CONTROLDP1_PTR      ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (LeftEyeball_Resolution == 8) */

   #define LeftEyeball_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define LeftEyeball_AUX_CONTROLDP0          (*(reg8 *)  LeftEyeball_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define LeftEyeball_AUX_CONTROLDP0_PTR      ((reg8 *)   LeftEyeball_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (LeftEyeball_UsingFixedFunction) */

#if(LeftEyeball_KillModeMinTime )
    #define LeftEyeball_KILLMODEMINTIME        (*(reg8 *)  LeftEyeball_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define LeftEyeball_KILLMODEMINTIME_PTR    ((reg8 *)   LeftEyeball_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (LeftEyeball_KillModeMinTime ) */

#if(LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_256_CLOCKS)
    #define LeftEyeball_DEADBAND_COUNT         (*(reg8 *)  LeftEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LeftEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   LeftEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LeftEyeball_DEADBAND_LSB_PTR       ((reg8 *)   LeftEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define LeftEyeball_DEADBAND_LSB           (*(reg8 *)  LeftEyeball_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (LeftEyeball_UsingFixedFunction)
        #define LeftEyeball_DEADBAND_COUNT         (*(reg8 *)  LeftEyeball_PWMHW__CFG0)
        #define LeftEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   LeftEyeball_PWMHW__CFG0)
        #define LeftEyeball_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LeftEyeball_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define LeftEyeball_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define LeftEyeball_DEADBAND_COUNT         (*(reg8 *)  LeftEyeball_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LeftEyeball_DEADBAND_COUNT_PTR     ((reg8 *)   LeftEyeball_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LeftEyeball_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LeftEyeball_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define LeftEyeball_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (LeftEyeball_UsingFixedFunction) */
#endif /* (LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_256_CLOCKS) */



#if (LeftEyeball_UsingFixedFunction)
    #define LeftEyeball_STATUS                 (*(reg8 *) LeftEyeball_PWMHW__SR0)
    #define LeftEyeball_STATUS_PTR             ((reg8 *) LeftEyeball_PWMHW__SR0)
    #define LeftEyeball_STATUS_MASK            (*(reg8 *) LeftEyeball_PWMHW__SR0)
    #define LeftEyeball_STATUS_MASK_PTR        ((reg8 *) LeftEyeball_PWMHW__SR0)
    #define LeftEyeball_CONTROL                (*(reg8 *) LeftEyeball_PWMHW__CFG0)
    #define LeftEyeball_CONTROL_PTR            ((reg8 *) LeftEyeball_PWMHW__CFG0)
    #define LeftEyeball_CONTROL2               (*(reg8 *) LeftEyeball_PWMHW__CFG1)
    #define LeftEyeball_CONTROL3               (*(reg8 *) LeftEyeball_PWMHW__CFG2)
    #define LeftEyeball_GLOBAL_ENABLE          (*(reg8 *) LeftEyeball_PWMHW__PM_ACT_CFG)
    #define LeftEyeball_GLOBAL_ENABLE_PTR      ( (reg8 *) LeftEyeball_PWMHW__PM_ACT_CFG)
    #define LeftEyeball_GLOBAL_STBY_ENABLE     (*(reg8 *) LeftEyeball_PWMHW__PM_STBY_CFG)
    #define LeftEyeball_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) LeftEyeball_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define LeftEyeball_BLOCK_EN_MASK          (LeftEyeball_PWMHW__PM_ACT_MSK)
    #define LeftEyeball_BLOCK_STBY_EN_MASK     (LeftEyeball_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define LeftEyeball_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define LeftEyeball_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define LeftEyeball_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define LeftEyeball_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define LeftEyeball_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define LeftEyeball_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define LeftEyeball_CTRL_ENABLE            (uint8)((uint8)0x01u << LeftEyeball_CTRL_ENABLE_SHIFT)
    #define LeftEyeball_CTRL_RESET             (uint8)((uint8)0x01u << LeftEyeball_CTRL_RESET_SHIFT)
    #define LeftEyeball_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LeftEyeball_CTRL_CMPMODE2_SHIFT)
    #define LeftEyeball_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LeftEyeball_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define LeftEyeball_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define LeftEyeball_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << LeftEyeball_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define LeftEyeball_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define LeftEyeball_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define LeftEyeball_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define LeftEyeball_STATUS_TC_INT_EN_MASK_SHIFT            (LeftEyeball_STATUS_TC_SHIFT - 4u)
    #define LeftEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define LeftEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT          (LeftEyeball_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define LeftEyeball_STATUS_TC              (uint8)((uint8)0x01u << LeftEyeball_STATUS_TC_SHIFT)
    #define LeftEyeball_STATUS_CMP1            (uint8)((uint8)0x01u << LeftEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define LeftEyeball_STATUS_TC_INT_EN_MASK              (uint8)((uint8)LeftEyeball_STATUS_TC >> 4u)
    #define LeftEyeball_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)LeftEyeball_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define LeftEyeball_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define LeftEyeball_RT1_MASK              (uint8)((uint8)0x03u << LeftEyeball_RT1_SHIFT)
    #define LeftEyeball_SYNC                  (uint8)((uint8)0x03u << LeftEyeball_RT1_SHIFT)
    #define LeftEyeball_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define LeftEyeball_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << LeftEyeball_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define LeftEyeball_SYNCDSI_EN            (uint8)((uint8)0x0Fu << LeftEyeball_SYNCDSI_SHIFT)


#else
    #define LeftEyeball_STATUS                (*(reg8 *)   LeftEyeball_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LeftEyeball_STATUS_PTR            ((reg8 *)    LeftEyeball_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LeftEyeball_STATUS_MASK           (*(reg8 *)   LeftEyeball_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LeftEyeball_STATUS_MASK_PTR       ((reg8 *)    LeftEyeball_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LeftEyeball_STATUS_AUX_CTRL       (*(reg8 *)   LeftEyeball_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define LeftEyeball_CONTROL               (*(reg8 *)   LeftEyeball_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define LeftEyeball_CONTROL_PTR           ((reg8 *)    LeftEyeball_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define LeftEyeball_CTRL_ENABLE_SHIFT      (0x07u)
    #define LeftEyeball_CTRL_RESET_SHIFT       (0x06u)
    #define LeftEyeball_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define LeftEyeball_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define LeftEyeball_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define LeftEyeball_CTRL_ENABLE            (uint8)((uint8)0x01u << LeftEyeball_CTRL_ENABLE_SHIFT)
    #define LeftEyeball_CTRL_RESET             (uint8)((uint8)0x01u << LeftEyeball_CTRL_RESET_SHIFT)
    #define LeftEyeball_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LeftEyeball_CTRL_CMPMODE2_SHIFT)
    #define LeftEyeball_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LeftEyeball_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define LeftEyeball_STATUS_KILL_SHIFT          (0x05u)
    #define LeftEyeball_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define LeftEyeball_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define LeftEyeball_STATUS_TC_SHIFT            (0x02u)
    #define LeftEyeball_STATUS_CMP2_SHIFT          (0x01u)
    #define LeftEyeball_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define LeftEyeball_STATUS_KILL_INT_EN_MASK_SHIFT          (LeftEyeball_STATUS_KILL_SHIFT)
    #define LeftEyeball_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (LeftEyeball_STATUS_FIFONEMPTY_SHIFT)
    #define LeftEyeball_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (LeftEyeball_STATUS_FIFOFULL_SHIFT)
    #define LeftEyeball_STATUS_TC_INT_EN_MASK_SHIFT            (LeftEyeball_STATUS_TC_SHIFT)
    #define LeftEyeball_STATUS_CMP2_INT_EN_MASK_SHIFT          (LeftEyeball_STATUS_CMP2_SHIFT)
    #define LeftEyeball_STATUS_CMP1_INT_EN_MASK_SHIFT          (LeftEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define LeftEyeball_STATUS_KILL            (uint8)((uint8)0x00u << LeftEyeball_STATUS_KILL_SHIFT )
    #define LeftEyeball_STATUS_FIFOFULL        (uint8)((uint8)0x01u << LeftEyeball_STATUS_FIFOFULL_SHIFT)
    #define LeftEyeball_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << LeftEyeball_STATUS_FIFONEMPTY_SHIFT)
    #define LeftEyeball_STATUS_TC              (uint8)((uint8)0x01u << LeftEyeball_STATUS_TC_SHIFT)
    #define LeftEyeball_STATUS_CMP2            (uint8)((uint8)0x01u << LeftEyeball_STATUS_CMP2_SHIFT)
    #define LeftEyeball_STATUS_CMP1            (uint8)((uint8)0x01u << LeftEyeball_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define LeftEyeball_STATUS_KILL_INT_EN_MASK            (LeftEyeball_STATUS_KILL)
    #define LeftEyeball_STATUS_FIFOFULL_INT_EN_MASK        (LeftEyeball_STATUS_FIFOFULL)
    #define LeftEyeball_STATUS_FIFONEMPTY_INT_EN_MASK      (LeftEyeball_STATUS_FIFONEMPTY)
    #define LeftEyeball_STATUS_TC_INT_EN_MASK              (LeftEyeball_STATUS_TC)
    #define LeftEyeball_STATUS_CMP2_INT_EN_MASK            (LeftEyeball_STATUS_CMP2)
    #define LeftEyeball_STATUS_CMP1_INT_EN_MASK            (LeftEyeball_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define LeftEyeball_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define LeftEyeball_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define LeftEyeball_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define LeftEyeball_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define LeftEyeball_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* LeftEyeball_UsingFixedFunction */

#endif  /* CY_PWM_LeftEyeball_H */


/* [] END OF FILE */
