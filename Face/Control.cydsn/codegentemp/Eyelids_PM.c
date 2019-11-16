/*******************************************************************************
* File Name: Eyelids_PM.c
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

#include "Eyelids.h"

static Eyelids_backupStruct Eyelids_backup;


/*******************************************************************************
* Function Name: Eyelids_SaveConfig
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
*  Eyelids_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Eyelids_SaveConfig(void) 
{

    #if(!Eyelids_UsingFixedFunction)
        #if(!Eyelids_PWMModeIsCenterAligned)
            Eyelids_backup.PWMPeriod = Eyelids_ReadPeriod();
        #endif /* (!Eyelids_PWMModeIsCenterAligned) */
        Eyelids_backup.PWMUdb = Eyelids_ReadCounter();
        #if (Eyelids_UseStatus)
            Eyelids_backup.InterruptMaskValue = Eyelids_STATUS_MASK;
        #endif /* (Eyelids_UseStatus) */

        #if(Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_256_CLOCKS || \
            Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_2_4_CLOCKS)
            Eyelids_backup.PWMdeadBandValue = Eyelids_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Eyelids_KillModeMinTime)
             Eyelids_backup.PWMKillCounterPeriod = Eyelids_ReadKillTime();
        #endif /* (Eyelids_KillModeMinTime) */

        #if(Eyelids_UseControl)
            Eyelids_backup.PWMControlRegister = Eyelids_ReadControlRegister();
        #endif /* (Eyelids_UseControl) */
    #endif  /* (!Eyelids_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Eyelids_RestoreConfig
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
*  Eyelids_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Eyelids_RestoreConfig(void) 
{
        #if(!Eyelids_UsingFixedFunction)
            #if(!Eyelids_PWMModeIsCenterAligned)
                Eyelids_WritePeriod(Eyelids_backup.PWMPeriod);
            #endif /* (!Eyelids_PWMModeIsCenterAligned) */

            Eyelids_WriteCounter(Eyelids_backup.PWMUdb);

            #if (Eyelids_UseStatus)
                Eyelids_STATUS_MASK = Eyelids_backup.InterruptMaskValue;
            #endif /* (Eyelids_UseStatus) */

            #if(Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_256_CLOCKS || \
                Eyelids_DeadBandMode == Eyelids__B_PWM__DBM_2_4_CLOCKS)
                Eyelids_WriteDeadTime(Eyelids_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Eyelids_KillModeMinTime)
                Eyelids_WriteKillTime(Eyelids_backup.PWMKillCounterPeriod);
            #endif /* (Eyelids_KillModeMinTime) */

            #if(Eyelids_UseControl)
                Eyelids_WriteControlRegister(Eyelids_backup.PWMControlRegister);
            #endif /* (Eyelids_UseControl) */
        #endif  /* (!Eyelids_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Eyelids_Sleep
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
*  Eyelids_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Eyelids_Sleep(void) 
{
    #if(Eyelids_UseControl)
        if(Eyelids_CTRL_ENABLE == (Eyelids_CONTROL & Eyelids_CTRL_ENABLE))
        {
            /*Component is enabled */
            Eyelids_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Eyelids_backup.PWMEnableState = 0u;
        }
    #endif /* (Eyelids_UseControl) */

    /* Stop component */
    Eyelids_Stop();

    /* Save registers configuration */
    Eyelids_SaveConfig();
}


/*******************************************************************************
* Function Name: Eyelids_Wakeup
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
*  Eyelids_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Eyelids_Wakeup(void) 
{
     /* Restore registers values */
    Eyelids_RestoreConfig();

    if(Eyelids_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Eyelids_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
