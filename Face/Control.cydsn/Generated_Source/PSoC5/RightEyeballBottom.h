/*******************************************************************************
* File Name: RightEyeballBottom.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RightEyeballBottom_H) /* Pins RightEyeballBottom_H */
#define CY_PINS_RightEyeballBottom_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RightEyeballBottom_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RightEyeballBottom__PORT == 15 && ((RightEyeballBottom__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RightEyeballBottom_Write(uint8 value);
void    RightEyeballBottom_SetDriveMode(uint8 mode);
uint8   RightEyeballBottom_ReadDataReg(void);
uint8   RightEyeballBottom_Read(void);
void    RightEyeballBottom_SetInterruptMode(uint16 position, uint16 mode);
uint8   RightEyeballBottom_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RightEyeballBottom_SetDriveMode() function.
     *  @{
     */
        #define RightEyeballBottom_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RightEyeballBottom_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RightEyeballBottom_DM_RES_UP          PIN_DM_RES_UP
        #define RightEyeballBottom_DM_RES_DWN         PIN_DM_RES_DWN
        #define RightEyeballBottom_DM_OD_LO           PIN_DM_OD_LO
        #define RightEyeballBottom_DM_OD_HI           PIN_DM_OD_HI
        #define RightEyeballBottom_DM_STRONG          PIN_DM_STRONG
        #define RightEyeballBottom_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RightEyeballBottom_MASK               RightEyeballBottom__MASK
#define RightEyeballBottom_SHIFT              RightEyeballBottom__SHIFT
#define RightEyeballBottom_WIDTH              1u

/* Interrupt constants */
#if defined(RightEyeballBottom__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RightEyeballBottom_SetInterruptMode() function.
     *  @{
     */
        #define RightEyeballBottom_INTR_NONE      (uint16)(0x0000u)
        #define RightEyeballBottom_INTR_RISING    (uint16)(0x0001u)
        #define RightEyeballBottom_INTR_FALLING   (uint16)(0x0002u)
        #define RightEyeballBottom_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RightEyeballBottom_INTR_MASK      (0x01u) 
#endif /* (RightEyeballBottom__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RightEyeballBottom_PS                     (* (reg8 *) RightEyeballBottom__PS)
/* Data Register */
#define RightEyeballBottom_DR                     (* (reg8 *) RightEyeballBottom__DR)
/* Port Number */
#define RightEyeballBottom_PRT_NUM                (* (reg8 *) RightEyeballBottom__PRT) 
/* Connect to Analog Globals */                                                  
#define RightEyeballBottom_AG                     (* (reg8 *) RightEyeballBottom__AG)                       
/* Analog MUX bux enable */
#define RightEyeballBottom_AMUX                   (* (reg8 *) RightEyeballBottom__AMUX) 
/* Bidirectional Enable */                                                        
#define RightEyeballBottom_BIE                    (* (reg8 *) RightEyeballBottom__BIE)
/* Bit-mask for Aliased Register Access */
#define RightEyeballBottom_BIT_MASK               (* (reg8 *) RightEyeballBottom__BIT_MASK)
/* Bypass Enable */
#define RightEyeballBottom_BYP                    (* (reg8 *) RightEyeballBottom__BYP)
/* Port wide control signals */                                                   
#define RightEyeballBottom_CTL                    (* (reg8 *) RightEyeballBottom__CTL)
/* Drive Modes */
#define RightEyeballBottom_DM0                    (* (reg8 *) RightEyeballBottom__DM0) 
#define RightEyeballBottom_DM1                    (* (reg8 *) RightEyeballBottom__DM1)
#define RightEyeballBottom_DM2                    (* (reg8 *) RightEyeballBottom__DM2) 
/* Input Buffer Disable Override */
#define RightEyeballBottom_INP_DIS                (* (reg8 *) RightEyeballBottom__INP_DIS)
/* LCD Common or Segment Drive */
#define RightEyeballBottom_LCD_COM_SEG            (* (reg8 *) RightEyeballBottom__LCD_COM_SEG)
/* Enable Segment LCD */
#define RightEyeballBottom_LCD_EN                 (* (reg8 *) RightEyeballBottom__LCD_EN)
/* Slew Rate Control */
#define RightEyeballBottom_SLW                    (* (reg8 *) RightEyeballBottom__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RightEyeballBottom_PRTDSI__CAPS_SEL       (* (reg8 *) RightEyeballBottom__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RightEyeballBottom_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RightEyeballBottom__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RightEyeballBottom_PRTDSI__OE_SEL0        (* (reg8 *) RightEyeballBottom__PRTDSI__OE_SEL0) 
#define RightEyeballBottom_PRTDSI__OE_SEL1        (* (reg8 *) RightEyeballBottom__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RightEyeballBottom_PRTDSI__OUT_SEL0       (* (reg8 *) RightEyeballBottom__PRTDSI__OUT_SEL0) 
#define RightEyeballBottom_PRTDSI__OUT_SEL1       (* (reg8 *) RightEyeballBottom__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RightEyeballBottom_PRTDSI__SYNC_OUT       (* (reg8 *) RightEyeballBottom__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RightEyeballBottom__SIO_CFG)
    #define RightEyeballBottom_SIO_HYST_EN        (* (reg8 *) RightEyeballBottom__SIO_HYST_EN)
    #define RightEyeballBottom_SIO_REG_HIFREQ     (* (reg8 *) RightEyeballBottom__SIO_REG_HIFREQ)
    #define RightEyeballBottom_SIO_CFG            (* (reg8 *) RightEyeballBottom__SIO_CFG)
    #define RightEyeballBottom_SIO_DIFF           (* (reg8 *) RightEyeballBottom__SIO_DIFF)
#endif /* (RightEyeballBottom__SIO_CFG) */

/* Interrupt Registers */
#if defined(RightEyeballBottom__INTSTAT)
    #define RightEyeballBottom_INTSTAT            (* (reg8 *) RightEyeballBottom__INTSTAT)
    #define RightEyeballBottom_SNAP               (* (reg8 *) RightEyeballBottom__SNAP)
    
	#define RightEyeballBottom_0_INTTYPE_REG 		(* (reg8 *) RightEyeballBottom__0__INTTYPE)
#endif /* (RightEyeballBottom__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RightEyeballBottom_H */


/* [] END OF FILE */
