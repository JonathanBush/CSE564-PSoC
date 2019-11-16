/*******************************************************************************
* File Name: LeftEyeball_PM.c
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

#include "LeftEyeball.h"

static LeftEyeball_backupStruct LeftEyeball_backup;


/*******************************************************************************
* Function Name: LeftEyeball_SaveConfig
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
*  LeftEyeball_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LeftEyeball_SaveConfig(void) 
{

    #if(!LeftEyeball_UsingFixedFunction)
        #if(!LeftEyeball_PWMModeIsCenterAligned)
            LeftEyeball_backup.PWMPeriod = LeftEyeball_ReadPeriod();
        #endif /* (!LeftEyeball_PWMModeIsCenterAligned) */
        LeftEyeball_backup.PWMUdb = LeftEyeball_ReadCounter();
        #if (LeftEyeball_UseStatus)
            LeftEyeball_backup.InterruptMaskValue = LeftEyeball_STATUS_MASK;
        #endif /* (LeftEyeball_UseStatus) */

        #if(LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_256_CLOCKS || \
            LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_2_4_CLOCKS)
            LeftEyeball_backup.PWMdeadBandValue = LeftEyeball_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(LeftEyeball_KillModeMinTime)
             LeftEyeball_backup.PWMKillCounterPeriod = LeftEyeball_ReadKillTime();
        #endif /* (LeftEyeball_KillModeMinTime) */

        #if(LeftEyeball_UseControl)
            LeftEyeball_backup.PWMControlRegister = LeftEyeball_ReadControlRegister();
        #endif /* (LeftEyeball_UseControl) */
    #endif  /* (!LeftEyeball_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LeftEyeball_RestoreConfig
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
*  LeftEyeball_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LeftEyeball_RestoreConfig(void) 
{
        #if(!LeftEyeball_UsingFixedFunction)
            #if(!LeftEyeball_PWMModeIsCenterAligned)
                LeftEyeball_WritePeriod(LeftEyeball_backup.PWMPeriod);
            #endif /* (!LeftEyeball_PWMModeIsCenterAligned) */

            LeftEyeball_WriteCounter(LeftEyeball_backup.PWMUdb);

            #if (LeftEyeball_UseStatus)
                LeftEyeball_STATUS_MASK = LeftEyeball_backup.InterruptMaskValue;
            #endif /* (LeftEyeball_UseStatus) */

            #if(LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_256_CLOCKS || \
                LeftEyeball_DeadBandMode == LeftEyeball__B_PWM__DBM_2_4_CLOCKS)
                LeftEyeball_WriteDeadTime(LeftEyeball_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(LeftEyeball_KillModeMinTime)
                LeftEyeball_WriteKillTime(LeftEyeball_backup.PWMKillCounterPeriod);
            #endif /* (LeftEyeball_KillModeMinTime) */

            #if(LeftEyeball_UseControl)
                LeftEyeball_WriteControlRegister(LeftEyeball_backup.PWMControlRegister);
            #endif /* (LeftEyeball_UseControl) */
        #endif  /* (!LeftEyeball_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: LeftEyeball_Sleep
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
*  LeftEyeball_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LeftEyeball_Sleep(void) 
{
    #if(LeftEyeball_UseControl)
        if(LeftEyeball_CTRL_ENABLE == (LeftEyeball_CONTROL & LeftEyeball_CTRL_ENABLE))
        {
            /*Component is enabled */
            LeftEyeball_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            LeftEyeball_backup.PWMEnableState = 0u;
        }
    #endif /* (LeftEyeball_UseControl) */

    /* Stop component */
    LeftEyeball_Stop();

    /* Save registers configuration */
    LeftEyeball_SaveConfig();
}


/*******************************************************************************
* Function Name: LeftEyeball_Wakeup
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
*  LeftEyeball_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LeftEyeball_Wakeup(void) 
{
     /* Restore registers values */
    LeftEyeball_RestoreConfig();

    if(LeftEyeball_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        LeftEyeball_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
