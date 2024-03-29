/*******************************************************************************
* File Name: Eyelids.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Eyelids.h"

/* Error message for removed <resource> through optimization */
#ifdef Eyelids_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* Eyelids_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 Eyelids_initVar = 0u;


/*******************************************************************************
* Function Name: Eyelids_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Eyelids_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Eyelids_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(Eyelids_initVar == 0u)
    {
        Eyelids_Init();
        Eyelids_initVar = 1u;
    }
    Eyelids_Enable();

}


/*******************************************************************************
* Function Name: Eyelids_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  Eyelids_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Eyelids_Init(void) 
{
    #if (Eyelids_UsingFixedFunction || Eyelids_UseControl)
        uint8 ctrl;
    #endif /* (Eyelids_UsingFixedFunction || Eyelids_UseControl) */

    #if(!Eyelids_UsingFixedFunction)
        #if(Eyelids_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 Eyelids_interruptState;
        #endif /* (Eyelids_UseStatus) */
    #endif /* (!Eyelids_UsingFixedFunction) */

    #if (Eyelids_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        Eyelids_CONTROL |= Eyelids_CFG0_MODE;
        #if (Eyelids_DeadBand2_4)
            Eyelids_CONTROL |= Eyelids_CFG0_DB;
        #endif /* (Eyelids_DeadBand2_4) */

        ctrl = Eyelids_CONTROL3 & ((uint8 )(~Eyelids_CTRL_CMPMODE1_MASK));
        Eyelids_CONTROL3 = ctrl | Eyelids_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        Eyelids_RT1 &= ((uint8)(~Eyelids_RT1_MASK));
        Eyelids_RT1 |= Eyelids_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        Eyelids_RT1 &= ((uint8)(~Eyelids_SYNCDSI_MASK));
        Eyelids_RT1 |= Eyelids_SYNCDSI_EN;

    #elif (Eyelids_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = Eyelids_CONTROL & ((uint8)(~Eyelids_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~Eyelids_CTRL_CMPMODE1_MASK));
        Eyelids_CONTROL = ctrl | Eyelids_DEFAULT_COMPARE2_MODE |
                                   Eyelids_DEFAULT_COMPARE1_MODE;
    #endif /* (Eyelids_UsingFixedFunction) */

    #if (!Eyelids_UsingFixedFunction)
        #if (Eyelids_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            Eyelids_AUX_CONTROLDP0 |= (Eyelids_AUX_CTRL_FIFO0_CLR);
        #else /* (Eyelids_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            Eyelids_AUX_CONTROLDP0 |= (Eyelids_AUX_CTRL_FIFO0_CLR);
            Eyelids_AUX_CONTROLDP1 |= (Eyelids_AUX_CTRL_FIFO0_CLR);
        #endif /* (Eyelids_Resolution == 8) */

        Eyelids_WriteCounter(Eyelids_INIT_PERIOD_VALUE);
    #endif /* (!Eyelids_UsingFixedFunction) */

    Eyelids_WritePeriod(Eyelids_INIT_PERIOD_VALUE);

        #if (Eyelids_UseOneCompareMode)
            Eyelids_WriteCompare(Eyelids_INIT_COMPARE_VALUE1);
        #else
            Eyelids_WriteCompare1(Eyelids_INIT_COMPARE_VALUE1);
            Eyelids_WriteCompare2(Eyelids_INIT_COMPARE_VALUE2);
        #endif /* (Eyelids_UseOneCompareMode) */

        #if (Eyelids_KillModeMinTime)
            Eyelids_WriteKillTime(Eyelids_MinimumKillTime);
        #endif /* (Eyelids_KillModeMinTime) */

        #if (Eyelids_DeadBandUsed)
            Eyelids_WriteDeadTime(Eyelids_INIT_DEAD_TIME);
        #endif /* (Eyelids_DeadBandUsed) */

    #if (Eyelids_UseStatus || Eyelids_UsingFixedFunction)
        Eyelids_SetInterruptMode(Eyelids_INIT_INTERRUPTS_MODE);
    #endif /* (Eyelids_UseStatus || Eyelids_UsingFixedFunction) */

    #if (Eyelids_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        Eyelids_GLOBAL_ENABLE |= Eyelids_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        Eyelids_CONTROL2 |= Eyelids_CTRL2_IRQ_SEL;
    #else
        #if(Eyelids_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Eyelids_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            Eyelids_STATUS_AUX_CTRL |= Eyelids_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(Eyelids_interruptState);

            /* Clear the FIFO to enable the Eyelids_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            Eyelids_ClearFIFO();
        #endif /* (Eyelids_UseStatus) */
    #endif /* (Eyelids_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Eyelids_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void Eyelids_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Eyelids_UsingFixedFunction)
        Eyelids_GLOBAL_ENABLE |= Eyelids_BLOCK_EN_MASK;
        Eyelids_GLOBAL_STBY_ENABLE |= Eyelids_BLOCK_STBY_EN_MASK;
    #endif /* (Eyelids_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (Eyelids_UseControl || Eyelids_UsingFixedFunction)
        Eyelids_CONTROL |= Eyelids_CTRL_ENABLE;
    #endif /* (Eyelids_UseControl || Eyelids_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Eyelids_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void Eyelids_Stop(void) 
{
    #if (Eyelids_UseControl || Eyelids_UsingFixedFunction)
        Eyelids_CONTROL &= ((uint8)(~Eyelids_CTRL_ENABLE));
    #endif /* (Eyelids_UseControl || Eyelids_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (Eyelids_UsingFixedFunction)
        Eyelids_GLOBAL_ENABLE &= ((uint8)(~Eyelids_BLOCK_EN_MASK));
        Eyelids_GLOBAL_STBY_ENABLE &= ((uint8)(~Eyelids_BLOCK_STBY_EN_MASK));
    #endif /* (Eyelids_UsingFixedFunction) */
}

#if (Eyelids_UseOneCompareMode)
    #if (Eyelids_CompareMode1SW)


        /*******************************************************************************
        * Function Name: Eyelids_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void Eyelids_SetCompareMode(uint8 comparemode) 
        {
            #if(Eyelids_UsingFixedFunction)

                #if(0 != Eyelids_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << Eyelids_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != Eyelids_CTRL_CMPMODE1_SHIFT) */

                Eyelids_CONTROL3 &= ((uint8)(~Eyelids_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                Eyelids_CONTROL3 |= comparemodemasked;

            #elif (Eyelids_UseControl)

                #if(0 != Eyelids_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << Eyelids_CTRL_CMPMODE1_SHIFT)) &
                                                Eyelids_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & Eyelids_CTRL_CMPMODE1_MASK;
                #endif /* (0 != Eyelids_CTRL_CMPMODE1_SHIFT) */

                #if(0 != Eyelids_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << Eyelids_CTRL_CMPMODE2_SHIFT)) &
                                               Eyelids_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & Eyelids_CTRL_CMPMODE2_MASK;
                #endif /* (0 != Eyelids_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                Eyelids_CONTROL &= ((uint8)(~(Eyelids_CTRL_CMPMODE1_MASK |
                                            Eyelids_CTRL_CMPMODE2_MASK)));
                Eyelids_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (Eyelids_UsingFixedFunction) */
        }
    #endif /* Eyelids_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (Eyelids_CompareMode1SW)


        /*******************************************************************************
        * Function Name: Eyelids_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void Eyelids_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != Eyelids_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << Eyelids_CTRL_CMPMODE1_SHIFT)) &
                                           Eyelids_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & Eyelids_CTRL_CMPMODE1_MASK;
            #endif /* (0 != Eyelids_CTRL_CMPMODE1_SHIFT) */

            #if (Eyelids_UseControl)
                Eyelids_CONTROL &= ((uint8)(~Eyelids_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                Eyelids_CONTROL |= comparemodemasked;
            #endif /* (Eyelids_UseControl) */
        }
    #endif /* Eyelids_CompareMode1SW */

#if (Eyelids_CompareMode2SW)


    /*******************************************************************************
    * Function Name: Eyelids_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != Eyelids_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << Eyelids_CTRL_CMPMODE2_SHIFT)) &
                                                 Eyelids_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & Eyelids_CTRL_CMPMODE2_MASK;
        #endif /* (0 != Eyelids_CTRL_CMPMODE2_SHIFT) */

        #if (Eyelids_UseControl)
            Eyelids_CONTROL &= ((uint8)(~Eyelids_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            Eyelids_CONTROL |= comparemodemasked;
        #endif /* (Eyelids_UseControl) */
    }
    #endif /*Eyelids_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!Eyelids_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Eyelids_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void Eyelids_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(Eyelids_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: Eyelids_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 Eyelids_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(Eyelids_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(Eyelids_CAPTURE_LSB_PTR));
    }

    #if (Eyelids_UseStatus)


        /*******************************************************************************
        * Function Name: Eyelids_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void Eyelids_ClearFIFO(void) 
        {
            while(0u != (Eyelids_ReadStatusRegister() & Eyelids_STATUS_FIFONEMPTY))
            {
                (void)Eyelids_ReadCapture();
            }
        }

    #endif /* Eyelids_UseStatus */

#endif /* !Eyelids_UsingFixedFunction */


/*******************************************************************************
* Function Name: Eyelids_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void Eyelids_WritePeriod(uint16 period) 
{
    #if(Eyelids_UsingFixedFunction)
        CY_SET_REG16(Eyelids_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(Eyelids_PERIOD_LSB_PTR, period);
    #endif /* (Eyelids_UsingFixedFunction) */
}

#if (Eyelids_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Eyelids_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void Eyelids_WriteCompare(uint16 compare) \
                                       
    {
        #if(Eyelids_UsingFixedFunction)
            CY_SET_REG16(Eyelids_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(Eyelids_COMPARE1_LSB_PTR, compare);
        #endif /* (Eyelids_UsingFixedFunction) */

        #if (Eyelids_PWMMode == Eyelids__B_PWM__DITHER)
            #if(Eyelids_UsingFixedFunction)
                CY_SET_REG16(Eyelids_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(Eyelids_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (Eyelids_UsingFixedFunction) */
        #endif /* (Eyelids_PWMMode == Eyelids__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: Eyelids_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_WriteCompare1(uint16 compare) \
                                        
    {
        #if(Eyelids_UsingFixedFunction)
            CY_SET_REG16(Eyelids_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(Eyelids_COMPARE1_LSB_PTR, compare);
        #endif /* (Eyelids_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: Eyelids_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_WriteCompare2(uint16 compare) \
                                        
    {
        #if(Eyelids_UsingFixedFunction)
            CY_SET_REG16(Eyelids_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(Eyelids_COMPARE2_LSB_PTR, compare);
        #endif /* (Eyelids_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (Eyelids_DeadBandUsed)


    /*******************************************************************************
    * Function Name: Eyelids_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!Eyelids_DeadBand2_4)
            CY_SET_REG8(Eyelids_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            Eyelids_DEADBAND_COUNT &= ((uint8)(~Eyelids_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(Eyelids_DEADBAND_COUNT_SHIFT)
                Eyelids_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << Eyelids_DEADBAND_COUNT_SHIFT)) &
                                                    Eyelids_DEADBAND_COUNT_MASK;
            #else
                Eyelids_DEADBAND_COUNT |= deadtime & Eyelids_DEADBAND_COUNT_MASK;
            #endif /* (Eyelids_DEADBAND_COUNT_SHIFT) */

        #endif /* (!Eyelids_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: Eyelids_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 Eyelids_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!Eyelids_DeadBand2_4)
            return (CY_GET_REG8(Eyelids_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(Eyelids_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(Eyelids_DEADBAND_COUNT & Eyelids_DEADBAND_COUNT_MASK)) >>
                                                                           Eyelids_DEADBAND_COUNT_SHIFT));
            #else
                return (Eyelids_DEADBAND_COUNT & Eyelids_DEADBAND_COUNT_MASK);
            #endif /* (Eyelids_DEADBAND_COUNT_SHIFT) */
        #endif /* (!Eyelids_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (Eyelids_UseStatus || Eyelids_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Eyelids_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(Eyelids_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: Eyelids_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 Eyelids_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(Eyelids_STATUS_PTR));
    }

#endif /* (Eyelids_UseStatus || Eyelids_UsingFixedFunction) */


#if (Eyelids_UseControl)


    /*******************************************************************************
    * Function Name: Eyelids_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 Eyelids_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(Eyelids_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: Eyelids_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(Eyelids_CONTROL_PTR, control);
    }

#endif /* (Eyelids_UseControl) */


#if (!Eyelids_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: Eyelids_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 Eyelids_ReadCapture(void) 
    {
        return (CY_GET_REG16(Eyelids_CAPTURE_LSB_PTR));
    }

#endif /* (!Eyelids_UsingFixedFunction) */


#if (Eyelids_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: Eyelids_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 Eyelids_ReadCompare(void) 
    {
        #if(Eyelids_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(Eyelids_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(Eyelids_COMPARE1_LSB_PTR));
        #endif /* (Eyelids_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: Eyelids_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 Eyelids_ReadCompare1(void) 
    {
        return (CY_GET_REG16(Eyelids_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: Eyelids_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 Eyelids_ReadCompare2(void) 
    {
        return (CY_GET_REG16(Eyelids_COMPARE2_LSB_PTR));
    }

#endif /* (Eyelids_UseOneCompareMode) */


/*******************************************************************************
* Function Name: Eyelids_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 Eyelids_ReadPeriod(void) 
{
    #if(Eyelids_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(Eyelids_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(Eyelids_PERIOD_LSB_PTR));
    #endif /* (Eyelids_UsingFixedFunction) */
}

#if ( Eyelids_KillModeMinTime)


    /*******************************************************************************
    * Function Name: Eyelids_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void Eyelids_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(Eyelids_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: Eyelids_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 Eyelids_ReadKillTime(void) 
    {
        return (CY_GET_REG8(Eyelids_KILLMODEMINTIME_PTR));
    }

#endif /* ( Eyelids_KillModeMinTime) */

/* [] END OF FILE */
