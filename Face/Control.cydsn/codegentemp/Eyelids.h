/*******************************************************************************
* File Name: Eyelids.h
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

#if !defined(CY_PWM_Eyelids_H)
#define CY_PWM_Eyelids_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Eyelids_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Eyelids_Resolution                     (16u)
#define Eyelids_UsingFixedFunction             (0u)
#define Eyelids_DeadBandMode                   (0u)
#define Eyelids_KillModeMinTime                (0u)
#define Eyelids_KillMode                       (0u)
#define Eyelids_PWMMode                        (1u)
#define Eyelids_PWMModeIsCenterAligned         (0u)
#define Eyelids_DeadBandUsed                   (0u)
#define Eyelids_DeadBand2_4                    (0u)

#if !defined(Eyelids_PWMUDB_genblk8_stsreg__REMOVED)
    #define Eyelids_UseStatus                  (1u)
#else
    #define Eyelids_UseStatus                  (0u)
#endif /* !defined(Eyelids_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Eyelids_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Eyelids_UseControl                 (1u)
#else
    #define Eyelids_UseControl                 (0u)
#endif /* !defined(Eyelids_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define Eyelids_UseOneCompareMode              (0u)
#define Eyelids_MinimumKillTime                (1u)
#define Eyelids_EnableMode                     (0u)

#define Eyelids_CompareMode1SW                 (0u)
#define Eyelids_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Eyelids__B_PWM__DISABLED 0
#define Eyelids__B_PWM__ASYNCHRONOUS 1
#define Eyelids__B_PWM__SINGLECYCLE 2
#define Eyelids__B_PWM__LATCHED 3
#define Eyelids__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Eyelids__B_PWM__DBMDISABLED 0
#define Eyelids__B_PWM__DBM_2_4_CLOCKS 1
#define Eyelids__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Eyelids__B_PWM__ONE_OUTPUT 0
#define Eyelids__B_PWM__TWO_OUTPUTS 1
#define Eyelids__B_PWM__DUAL_EDGE 2
#define Eyelids__B_PWM__CENTER_ALIGN 3
#define Eyelids__B_PWM__DITHER 5
#define Eyelids__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Eyelids__B_PWM__LESS_THAN 1
#define Eyelids__B_PWM__LESS_THAN_OR_EQUAL 2
#define Eyelids__B_PWM__GREATER_THAN 3
#define Eyelids__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Eyelids__B_PWM__EQUAL 0
#define Eyelids__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!Eyelids_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!Eyelids_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!Eyelids_PWMModeIsCenterAligned) */
        #if (Eyelids_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Eyelids_UseStatus) */

        /* Backup for Deadband parameters */
        #if(Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_256_CLOCKS || \
            Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(Eyelids_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Eyelids_KillModeMinTime) */

        /* Backup control register */
        #if(Eyelids_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Eyelids_UseControl) */

    #endif /* (!Eyelids_UsingFixedFunction) */

}Eyelids_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    Eyelids_Start(void) ;
void    Eyelids_Stop(void) ;

#if (Eyelids_UseStatus || Eyelids_UsingFixedFunction)
    void  Eyelids_SetInterruptMode(uint8 interruptMode) ;
    uint8 Eyelids_ReadStatusRegister(void) ;
#endif /* (Eyelids_UseStatus || Eyelids_UsingFixedFunction) */

#define Eyelids_GetInterruptSource() Eyelids_ReadStatusRegister()

#if (Eyelids_UseControl)
    uint8 Eyelids_ReadControlRegister(void) ;
    void  Eyelids_WriteControlRegister(uint8 control)
          ;
#endif /* (Eyelids_UseControl) */

#if (Eyelids_UseOneCompareMode)
   #if (Eyelids_CompareMode1SW)
       void    Eyelids_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (Eyelids_CompareMode1SW) */
#else
    #if (Eyelids_CompareMode1SW)
        void    Eyelids_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (Eyelids_CompareMode1SW) */
    #if (Eyelids_CompareMode2SW)
        void    Eyelids_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (Eyelids_CompareMode2SW) */
#endif /* (Eyelids_UseOneCompareMode) */

#if (!Eyelids_UsingFixedFunction)
    uint16   Eyelids_ReadCounter(void) ;
    uint16 Eyelids_ReadCapture(void) ;

    #if (Eyelids_UseStatus)
            void Eyelids_ClearFIFO(void) ;
    #endif /* (Eyelids_UseStatus) */

    void    Eyelids_WriteCounter(uint16 counter)
            ;
#endif /* (!Eyelids_UsingFixedFunction) */

void    Eyelids_WritePeriod(uint16 period)
        ;
uint16 Eyelids_ReadPeriod(void) ;

#if (Eyelids_UseOneCompareMode)
    void    Eyelids_WriteCompare(uint16 compare)
            ;
    uint16 Eyelids_ReadCompare(void) ;
#else
    void    Eyelids_WriteCompare1(uint16 compare)
            ;
    uint16 Eyelids_ReadCompare1(void) ;
    void    Eyelids_WriteCompare2(uint16 compare)
            ;
    uint16 Eyelids_ReadCompare2(void) ;
#endif /* (Eyelids_UseOneCompareMode) */


#if (Eyelids_DeadBandUsed)
    void    Eyelids_WriteDeadTime(uint8 deadtime) ;
    uint8   Eyelids_ReadDeadTime(void) ;
#endif /* (Eyelids_DeadBandUsed) */

#if ( Eyelids_KillModeMinTime)
    void Eyelids_WriteKillTime(uint8 killtime) ;
    uint8 Eyelids_ReadKillTime(void) ;
#endif /* ( Eyelids_KillModeMinTime) */

void Eyelids_Init(void) ;
void Eyelids_Enable(void) ;
void Eyelids_Sleep(void) ;
void Eyelids_Wakeup(void) ;
void Eyelids_SaveConfig(void) ;
void Eyelids_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Eyelids_INIT_PERIOD_VALUE          (20000u)
#define Eyelids_INIT_COMPARE_VALUE1        (2000u)
#define Eyelids_INIT_COMPARE_VALUE2        (2000u)
#define Eyelids_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    Eyelids_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Eyelids_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Eyelids_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Eyelids_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Eyelids_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  Eyelids_CTRL_CMPMODE2_SHIFT)
#define Eyelids_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  Eyelids_CTRL_CMPMODE1_SHIFT)
#define Eyelids_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (Eyelids_UsingFixedFunction)
   #define Eyelids_PERIOD_LSB              (*(reg16 *) Eyelids_PWMHW__PER0)
   #define Eyelids_PERIOD_LSB_PTR          ( (reg16 *) Eyelids_PWMHW__PER0)
   #define Eyelids_COMPARE1_LSB            (*(reg16 *) Eyelids_PWMHW__CNT_CMP0)
   #define Eyelids_COMPARE1_LSB_PTR        ( (reg16 *) Eyelids_PWMHW__CNT_CMP0)
   #define Eyelids_COMPARE2_LSB            (0x00u)
   #define Eyelids_COMPARE2_LSB_PTR        (0x00u)
   #define Eyelids_COUNTER_LSB             (*(reg16 *) Eyelids_PWMHW__CNT_CMP0)
   #define Eyelids_COUNTER_LSB_PTR         ( (reg16 *) Eyelids_PWMHW__CNT_CMP0)
   #define Eyelids_CAPTURE_LSB             (*(reg16 *) Eyelids_PWMHW__CAP0)
   #define Eyelids_CAPTURE_LSB_PTR         ( (reg16 *) Eyelids_PWMHW__CAP0)
   #define Eyelids_RT1                     (*(reg8 *)  Eyelids_PWMHW__RT1)
   #define Eyelids_RT1_PTR                 ( (reg8 *)  Eyelids_PWMHW__RT1)

#else
   #if (Eyelids_Resolution == 8u) /* 8bit - PWM */

       #if(Eyelids_PWMModeIsCenterAligned)
           #define Eyelids_PERIOD_LSB      (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define Eyelids_PERIOD_LSB_PTR  ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define Eyelids_PERIOD_LSB      (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define Eyelids_PERIOD_LSB_PTR  ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (Eyelids_PWMModeIsCenterAligned) */

       #define Eyelids_COMPARE1_LSB        (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Eyelids_COMPARE1_LSB_PTR    ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define Eyelids_COMPARE2_LSB        (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Eyelids_COMPARE2_LSB_PTR    ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define Eyelids_COUNTERCAP_LSB      (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Eyelids_COUNTERCAP_LSB_PTR  ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define Eyelids_COUNTER_LSB         (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Eyelids_COUNTER_LSB_PTR     ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define Eyelids_CAPTURE_LSB         (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define Eyelids_CAPTURE_LSB_PTR     ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(Eyelids_PWMModeIsCenterAligned)
               #define Eyelids_PERIOD_LSB      (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define Eyelids_PERIOD_LSB_PTR  ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define Eyelids_PERIOD_LSB      (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define Eyelids_PERIOD_LSB_PTR  ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (Eyelids_PWMModeIsCenterAligned) */

            #define Eyelids_COMPARE1_LSB       (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Eyelids_COMPARE1_LSB_PTR   ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define Eyelids_COMPARE2_LSB       (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Eyelids_COMPARE2_LSB_PTR   ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define Eyelids_COUNTERCAP_LSB     (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Eyelids_COUNTERCAP_LSB_PTR ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define Eyelids_COUNTER_LSB        (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Eyelids_COUNTER_LSB_PTR    ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define Eyelids_CAPTURE_LSB        (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define Eyelids_CAPTURE_LSB_PTR    ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(Eyelids_PWMModeIsCenterAligned)
               #define Eyelids_PERIOD_LSB      (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define Eyelids_PERIOD_LSB_PTR  ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define Eyelids_PERIOD_LSB      (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define Eyelids_PERIOD_LSB_PTR  ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (Eyelids_PWMModeIsCenterAligned) */

            #define Eyelids_COMPARE1_LSB       (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Eyelids_COMPARE1_LSB_PTR   ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define Eyelids_COMPARE2_LSB       (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Eyelids_COMPARE2_LSB_PTR   ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define Eyelids_COUNTERCAP_LSB     (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Eyelids_COUNTERCAP_LSB_PTR ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define Eyelids_COUNTER_LSB        (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Eyelids_COUNTER_LSB_PTR    ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define Eyelids_CAPTURE_LSB        (*(reg16 *) Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define Eyelids_CAPTURE_LSB_PTR    ((reg16 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define Eyelids_AUX_CONTROLDP1          (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define Eyelids_AUX_CONTROLDP1_PTR      ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Eyelids_Resolution == 8) */

   #define Eyelids_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define Eyelids_AUX_CONTROLDP0          (*(reg8 *)  Eyelids_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define Eyelids_AUX_CONTROLDP0_PTR      ((reg8 *)   Eyelids_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Eyelids_UsingFixedFunction) */

#if(Eyelids_KillModeMinTime )
    #define Eyelids_KILLMODEMINTIME        (*(reg8 *)  Eyelids_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Eyelids_KILLMODEMINTIME_PTR    ((reg8 *)   Eyelids_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Eyelids_KillModeMinTime ) */

#if(Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_256_CLOCKS)
    #define Eyelids_DEADBAND_COUNT         (*(reg8 *)  Eyelids_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Eyelids_DEADBAND_COUNT_PTR     ((reg8 *)   Eyelids_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Eyelids_DEADBAND_LSB_PTR       ((reg8 *)   Eyelids_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Eyelids_DEADBAND_LSB           (*(reg8 *)  Eyelids_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Eyelids_UsingFixedFunction)
        #define Eyelids_DEADBAND_COUNT         (*(reg8 *)  Eyelids_PWMHW__CFG0)
        #define Eyelids_DEADBAND_COUNT_PTR     ((reg8 *)   Eyelids_PWMHW__CFG0)
        #define Eyelids_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Eyelids_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Eyelids_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Eyelids_DEADBAND_COUNT         (*(reg8 *)  Eyelids_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Eyelids_DEADBAND_COUNT_PTR     ((reg8 *)   Eyelids_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Eyelids_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Eyelids_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define Eyelids_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (Eyelids_UsingFixedFunction) */
#endif /* (Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_256_CLOCKS) */



#if (Eyelids_UsingFixedFunction)
    #define Eyelids_STATUS                 (*(reg8 *) Eyelids_PWMHW__SR0)
    #define Eyelids_STATUS_PTR             ((reg8 *) Eyelids_PWMHW__SR0)
    #define Eyelids_STATUS_MASK            (*(reg8 *) Eyelids_PWMHW__SR0)
    #define Eyelids_STATUS_MASK_PTR        ((reg8 *) Eyelids_PWMHW__SR0)
    #define Eyelids_CONTROL                (*(reg8 *) Eyelids_PWMHW__CFG0)
    #define Eyelids_CONTROL_PTR            ((reg8 *) Eyelids_PWMHW__CFG0)
    #define Eyelids_CONTROL2               (*(reg8 *) Eyelids_PWMHW__CFG1)
    #define Eyelids_CONTROL3               (*(reg8 *) Eyelids_PWMHW__CFG2)
    #define Eyelids_GLOBAL_ENABLE          (*(reg8 *) Eyelids_PWMHW__PM_ACT_CFG)
    #define Eyelids_GLOBAL_ENABLE_PTR      ( (reg8 *) Eyelids_PWMHW__PM_ACT_CFG)
    #define Eyelids_GLOBAL_STBY_ENABLE     (*(reg8 *) Eyelids_PWMHW__PM_STBY_CFG)
    #define Eyelids_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) Eyelids_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Eyelids_BLOCK_EN_MASK          (Eyelids_PWMHW__PM_ACT_MSK)
    #define Eyelids_BLOCK_STBY_EN_MASK     (Eyelids_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define Eyelids_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define Eyelids_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define Eyelids_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define Eyelids_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define Eyelids_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define Eyelids_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define Eyelids_CTRL_ENABLE            (uint8)((uint8)0x01u << Eyelids_CTRL_ENABLE_SHIFT)
    #define Eyelids_CTRL_RESET             (uint8)((uint8)0x01u << Eyelids_CTRL_RESET_SHIFT)
    #define Eyelids_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Eyelids_CTRL_CMPMODE2_SHIFT)
    #define Eyelids_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Eyelids_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Eyelids_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define Eyelids_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Eyelids_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define Eyelids_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define Eyelids_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define Eyelids_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define Eyelids_STATUS_TC_INT_EN_MASK_SHIFT            (Eyelids_STATUS_TC_SHIFT - 4u)
    #define Eyelids_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define Eyelids_STATUS_CMP1_INT_EN_MASK_SHIFT          (Eyelids_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define Eyelids_STATUS_TC              (uint8)((uint8)0x01u << Eyelids_STATUS_TC_SHIFT)
    #define Eyelids_STATUS_CMP1            (uint8)((uint8)0x01u << Eyelids_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define Eyelids_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Eyelids_STATUS_TC >> 4u)
    #define Eyelids_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Eyelids_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define Eyelids_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define Eyelids_RT1_MASK              (uint8)((uint8)0x03u << Eyelids_RT1_SHIFT)
    #define Eyelids_SYNC                  (uint8)((uint8)0x03u << Eyelids_RT1_SHIFT)
    #define Eyelids_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define Eyelids_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Eyelids_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define Eyelids_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Eyelids_SYNCDSI_SHIFT)


#else
    #define Eyelids_STATUS                (*(reg8 *)   Eyelids_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Eyelids_STATUS_PTR            ((reg8 *)    Eyelids_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Eyelids_STATUS_MASK           (*(reg8 *)   Eyelids_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Eyelids_STATUS_MASK_PTR       ((reg8 *)    Eyelids_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Eyelids_STATUS_AUX_CTRL       (*(reg8 *)   Eyelids_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Eyelids_CONTROL               (*(reg8 *)   Eyelids_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Eyelids_CONTROL_PTR           ((reg8 *)    Eyelids_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define Eyelids_CTRL_ENABLE_SHIFT      (0x07u)
    #define Eyelids_CTRL_RESET_SHIFT       (0x06u)
    #define Eyelids_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define Eyelids_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define Eyelids_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define Eyelids_CTRL_ENABLE            (uint8)((uint8)0x01u << Eyelids_CTRL_ENABLE_SHIFT)
    #define Eyelids_CTRL_RESET             (uint8)((uint8)0x01u << Eyelids_CTRL_RESET_SHIFT)
    #define Eyelids_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Eyelids_CTRL_CMPMODE2_SHIFT)
    #define Eyelids_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Eyelids_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define Eyelids_STATUS_KILL_SHIFT          (0x05u)
    #define Eyelids_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define Eyelids_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define Eyelids_STATUS_TC_SHIFT            (0x02u)
    #define Eyelids_STATUS_CMP2_SHIFT          (0x01u)
    #define Eyelids_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Eyelids_STATUS_KILL_INT_EN_MASK_SHIFT          (Eyelids_STATUS_KILL_SHIFT)
    #define Eyelids_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (Eyelids_STATUS_FIFONEMPTY_SHIFT)
    #define Eyelids_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (Eyelids_STATUS_FIFOFULL_SHIFT)
    #define Eyelids_STATUS_TC_INT_EN_MASK_SHIFT            (Eyelids_STATUS_TC_SHIFT)
    #define Eyelids_STATUS_CMP2_INT_EN_MASK_SHIFT          (Eyelids_STATUS_CMP2_SHIFT)
    #define Eyelids_STATUS_CMP1_INT_EN_MASK_SHIFT          (Eyelids_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define Eyelids_STATUS_KILL            (uint8)((uint8)0x00u << Eyelids_STATUS_KILL_SHIFT )
    #define Eyelids_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Eyelids_STATUS_FIFOFULL_SHIFT)
    #define Eyelids_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Eyelids_STATUS_FIFONEMPTY_SHIFT)
    #define Eyelids_STATUS_TC              (uint8)((uint8)0x01u << Eyelids_STATUS_TC_SHIFT)
    #define Eyelids_STATUS_CMP2            (uint8)((uint8)0x01u << Eyelids_STATUS_CMP2_SHIFT)
    #define Eyelids_STATUS_CMP1            (uint8)((uint8)0x01u << Eyelids_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Eyelids_STATUS_KILL_INT_EN_MASK            (Eyelids_STATUS_KILL)
    #define Eyelids_STATUS_FIFOFULL_INT_EN_MASK        (Eyelids_STATUS_FIFOFULL)
    #define Eyelids_STATUS_FIFONEMPTY_INT_EN_MASK      (Eyelids_STATUS_FIFONEMPTY)
    #define Eyelids_STATUS_TC_INT_EN_MASK              (Eyelids_STATUS_TC)
    #define Eyelids_STATUS_CMP2_INT_EN_MASK            (Eyelids_STATUS_CMP2)
    #define Eyelids_STATUS_CMP1_INT_EN_MASK            (Eyelids_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define Eyelids_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define Eyelids_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define Eyelids_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define Eyelids_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define Eyelids_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* Eyelids_UsingFixedFunction */

#endif  /* CY_PWM_Eyelids_H */


/* [] END OF FILE */
