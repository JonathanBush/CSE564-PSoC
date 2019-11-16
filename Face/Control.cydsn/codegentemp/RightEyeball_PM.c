/*******************************************************************************
* File Name: RightEyeball_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RightEyeball.h"

static RightEyeball_backupStruct RightEyeball_backup;


/*******************************************************************************
* Function Name: RightEyeball_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RightEyeball_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void RightEyeball_SaveConfig(void) 
{

    #if(!RightEyeball_UsingFixedFunction)
        #if(!RightEyeball_PWMModeIsCenterAligned)
            RightEyeball_backup.PWMPeriod = RightEyeball_ReadPeriod();
        #endif /* (!RightEyeball_PWMModeIsCenterAligned) */
        RightEyeball_backup.PWMUdb = RightEyeball_ReadCounter();
        #if (RightEyeball_UseStatus)
            RightEyeball_backup.InterruptMaskValue = RightEyeball_STATUS_MASK;
        #endif /* (RightEyeball_UseStatus) */

        #if(RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_256_CLOCKS || \
            RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_2_4_CLOCKS)
            RightEyeball_backup.PWMdeadBandValue = RightEyeball_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(RightEyeball_KillModeMinTime)
             RightEyeball_backup.PWMKillCounterPeriod = RightEyeball_ReadKillTime();
        #endif /* (RightEyeball_KillModeMinTime) */

        #if(RightEyeball_UseControl)
            RightEyeball_backup.PWMControlRegister = RightEyeball_ReadControlRegister();
        #endif /* (RightEyeball_UseControl) */
    #endif  /* (!RightEyeball_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: RightEyeball_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RightEyeball_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void RightEyeball_RestoreConfig(void) 
{
        #if(!RightEyeball_UsingFixedFunction)
            #if(!RightEyeball_PWMModeIsCenterAligned)
                RightEyeball_WritePeriod(RightEyeball_backup.PWMPeriod);
            #endif /* (!RightEyeball_PWMModeIsCenterAligned) */

            RightEyeball_WriteCounter(RightEyeball_backup.PWMUdb);

            #if (RightEyeball_UseStatus)
                RightEyeball_STATUS_MASK = RightEyeball_backup.InterruptMaskValue;
            #endif /* (RightEyeball_UseStatus) */

            #if(RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_256_CLOCKS || \
                RightEyeball_DeadBandMode == RightEyeball__B_PWM__DBM_2_4_CLOCKS)
                RightEyeball_WriteDeadTime(RightEyeball_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(RightEyeball_KillModeMinTime)
                RightEyeball_WriteKillTime(RightEyeball_backup.PWMKillCounterPeriod);
            #endif /* (RightEyeball_KillModeMinTime) */

            #if(RightEyeball_UseControl)
                RightEyeball_WriteControlRegister(RightEyeball_backup.PWMControlRegister);
            #endif /* (RightEyeball_UseControl) */
        #endif  /* (!RightEyeball_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: RightEyeball_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RightEyeball_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void RightEyeball_Sleep(void) 
{
    #if(RightEyeball_UseControl)
        if(RightEyeball_CTRL_ENABLE == (RightEyeball_CONTROL & RightEyeball_CTRL_ENABLE))
        {
            /*Component is enabled */
            RightEyeball_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            RightEyeball_backup.PWMEnableState = 0u;
        }
    #endif /* (RightEyeball_UseControl) */

    /* Stop component */
    RightEyeball_Stop();

    /* Save registers configuration */
    RightEyeball_SaveConfig();
}


/*******************************************************************************
* Function Name: RightEyeball_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RightEyeball_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void RightEyeball_Wakeup(void) 
{
     /* Restore registers values */
    RightEyeball_RestoreConfig();

    if(RightEyeball_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        RightEyeball_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
