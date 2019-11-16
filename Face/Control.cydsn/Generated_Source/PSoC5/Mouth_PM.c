/*******************************************************************************
* File Name: Mouth_PM.c
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

#include "Mouth.h"

static Mouth_backupStruct Mouth_backup;


/*******************************************************************************
* Function Name: Mouth_SaveConfig
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
*  Mouth_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Mouth_SaveConfig(void) 
{

    #if(!Mouth_UsingFixedFunction)
        #if(!Mouth_PWMModeIsCenterAligned)
            Mouth_backup.PWMPeriod = Mouth_ReadPeriod();
        #endif /* (!Mouth_PWMModeIsCenterAligned) */
        Mouth_backup.PWMUdb = Mouth_ReadCounter();
        #if (Mouth_UseStatus)
            Mouth_backup.InterruptMaskValue = Mouth_STATUS_MASK;
        #endif /* (Mouth_UseStatus) */

        #if(Mouth_DeadBandMode == Mouth__B_PWM__DBM_256_CLOCKS || \
            Mouth_DeadBandMode == Mouth__B_PWM__DBM_2_4_CLOCKS)
            Mouth_backup.PWMdeadBandValue = Mouth_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Mouth_KillModeMinTime)
             Mouth_backup.PWMKillCounterPeriod = Mouth_ReadKillTime();
        #endif /* (Mouth_KillModeMinTime) */

        #if(Mouth_UseControl)
            Mouth_backup.PWMControlRegister = Mouth_ReadControlRegister();
        #endif /* (Mouth_UseControl) */
    #endif  /* (!Mouth_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Mouth_RestoreConfig
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
*  Mouth_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Mouth_RestoreConfig(void) 
{
        #if(!Mouth_UsingFixedFunction)
            #if(!Mouth_PWMModeIsCenterAligned)
                Mouth_WritePeriod(Mouth_backup.PWMPeriod);
            #endif /* (!Mouth_PWMModeIsCenterAligned) */

            Mouth_WriteCounter(Mouth_backup.PWMUdb);

            #if (Mouth_UseStatus)
                Mouth_STATUS_MASK = Mouth_backup.InterruptMaskValue;
            #endif /* (Mouth_UseStatus) */

            #if(Mouth_DeadBandMode == Mouth__B_PWM__DBM_256_CLOCKS || \
                Mouth_DeadBandMode == Mouth__B_PWM__DBM_2_4_CLOCKS)
                Mouth_WriteDeadTime(Mouth_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Mouth_KillModeMinTime)
                Mouth_WriteKillTime(Mouth_backup.PWMKillCounterPeriod);
            #endif /* (Mouth_KillModeMinTime) */

            #if(Mouth_UseControl)
                Mouth_WriteControlRegister(Mouth_backup.PWMControlRegister);
            #endif /* (Mouth_UseControl) */
        #endif  /* (!Mouth_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Mouth_Sleep
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
*  Mouth_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Mouth_Sleep(void) 
{
    #if(Mouth_UseControl)
        if(Mouth_CTRL_ENABLE == (Mouth_CONTROL & Mouth_CTRL_ENABLE))
        {
            /*Component is enabled */
            Mouth_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Mouth_backup.PWMEnableState = 0u;
        }
    #endif /* (Mouth_UseControl) */

    /* Stop component */
    Mouth_Stop();

    /* Save registers configuration */
    Mouth_SaveConfig();
}


/*******************************************************************************
* Function Name: Mouth_Wakeup
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
*  Mouth_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Mouth_Wakeup(void) 
{
     /* Restore registers values */
    Mouth_RestoreConfig();

    if(Mouth_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Mouth_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
