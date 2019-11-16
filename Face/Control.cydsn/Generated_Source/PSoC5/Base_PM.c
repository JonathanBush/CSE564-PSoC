/*******************************************************************************
* File Name: Base_PM.c
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

#include "Base.h"

static Base_backupStruct Base_backup;


/*******************************************************************************
* Function Name: Base_SaveConfig
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
*  Base_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Base_SaveConfig(void) 
{

    #if(!Base_UsingFixedFunction)
        #if(!Base_PWMModeIsCenterAligned)
            Base_backup.PWMPeriod = Base_ReadPeriod();
        #endif /* (!Base_PWMModeIsCenterAligned) */
        Base_backup.PWMUdb = Base_ReadCounter();
        #if (Base_UseStatus)
            Base_backup.InterruptMaskValue = Base_STATUS_MASK;
        #endif /* (Base_UseStatus) */

        #if(Base_DeadBandMode == Base__B_PWM__DBM_256_CLOCKS || \
            Base_DeadBandMode == Base__B_PWM__DBM_2_4_CLOCKS)
            Base_backup.PWMdeadBandValue = Base_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Base_KillModeMinTime)
             Base_backup.PWMKillCounterPeriod = Base_ReadKillTime();
        #endif /* (Base_KillModeMinTime) */

        #if(Base_UseControl)
            Base_backup.PWMControlRegister = Base_ReadControlRegister();
        #endif /* (Base_UseControl) */
    #endif  /* (!Base_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Base_RestoreConfig
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
*  Base_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Base_RestoreConfig(void) 
{
        #if(!Base_UsingFixedFunction)
            #if(!Base_PWMModeIsCenterAligned)
                Base_WritePeriod(Base_backup.PWMPeriod);
            #endif /* (!Base_PWMModeIsCenterAligned) */

            Base_WriteCounter(Base_backup.PWMUdb);

            #if (Base_UseStatus)
                Base_STATUS_MASK = Base_backup.InterruptMaskValue;
            #endif /* (Base_UseStatus) */

            #if(Base_DeadBandMode == Base__B_PWM__DBM_256_CLOCKS || \
                Base_DeadBandMode == Base__B_PWM__DBM_2_4_CLOCKS)
                Base_WriteDeadTime(Base_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Base_KillModeMinTime)
                Base_WriteKillTime(Base_backup.PWMKillCounterPeriod);
            #endif /* (Base_KillModeMinTime) */

            #if(Base_UseControl)
                Base_WriteControlRegister(Base_backup.PWMControlRegister);
            #endif /* (Base_UseControl) */
        #endif  /* (!Base_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Base_Sleep
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
*  Base_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Base_Sleep(void) 
{
    #if(Base_UseControl)
        if(Base_CTRL_ENABLE == (Base_CONTROL & Base_CTRL_ENABLE))
        {
            /*Component is enabled */
            Base_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Base_backup.PWMEnableState = 0u;
        }
    #endif /* (Base_UseControl) */

    /* Stop component */
    Base_Stop();

    /* Save registers configuration */
    Base_SaveConfig();
}


/*******************************************************************************
* Function Name: Base_Wakeup
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
*  Base_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Base_Wakeup(void) 
{
     /* Restore registers values */
    Base_RestoreConfig();

    if(Base_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Base_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
