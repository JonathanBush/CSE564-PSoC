/*******************************************************************************
* File Name: LipRight.h  
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

#if !defined(CY_PINS_LipRight_H) /* Pins LipRight_H */
#define CY_PINS_LipRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LipRight_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LipRight__PORT == 15 && ((LipRight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LipRight_Write(uint8 value);
void    LipRight_SetDriveMode(uint8 mode);
uint8   LipRight_ReadDataReg(void);
uint8   LipRight_Read(void);
void    LipRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   LipRight_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LipRight_SetDriveMode() function.
     *  @{
     */
        #define LipRight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LipRight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LipRight_DM_RES_UP          PIN_DM_RES_UP
        #define LipRight_DM_RES_DWN         PIN_DM_RES_DWN
        #define LipRight_DM_OD_LO           PIN_DM_OD_LO
        #define LipRight_DM_OD_HI           PIN_DM_OD_HI
        #define LipRight_DM_STRONG          PIN_DM_STRONG
        #define LipRight_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LipRight_MASK               LipRight__MASK
#define LipRight_SHIFT              LipRight__SHIFT
#define LipRight_WIDTH              1u

/* Interrupt constants */
#if defined(LipRight__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LipRight_SetInterruptMode() function.
     *  @{
     */
        #define LipRight_INTR_NONE      (uint16)(0x0000u)
        #define LipRight_INTR_RISING    (uint16)(0x0001u)
        #define LipRight_INTR_FALLING   (uint16)(0x0002u)
        #define LipRight_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LipRight_INTR_MASK      (0x01u) 
#endif /* (LipRight__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LipRight_PS                     (* (reg8 *) LipRight__PS)
/* Data Register */
#define LipRight_DR                     (* (reg8 *) LipRight__DR)
/* Port Number */
#define LipRight_PRT_NUM                (* (reg8 *) LipRight__PRT) 
/* Connect to Analog Globals */                                                  
#define LipRight_AG                     (* (reg8 *) LipRight__AG)                       
/* Analog MUX bux enable */
#define LipRight_AMUX                   (* (reg8 *) LipRight__AMUX) 
/* Bidirectional Enable */                                                        
#define LipRight_BIE                    (* (reg8 *) LipRight__BIE)
/* Bit-mask for Aliased Register Access */
#define LipRight_BIT_MASK               (* (reg8 *) LipRight__BIT_MASK)
/* Bypass Enable */
#define LipRight_BYP                    (* (reg8 *) LipRight__BYP)
/* Port wide control signals */                                                   
#define LipRight_CTL                    (* (reg8 *) LipRight__CTL)
/* Drive Modes */
#define LipRight_DM0                    (* (reg8 *) LipRight__DM0) 
#define LipRight_DM1                    (* (reg8 *) LipRight__DM1)
#define LipRight_DM2                    (* (reg8 *) LipRight__DM2) 
/* Input Buffer Disable Override */
#define LipRight_INP_DIS                (* (reg8 *) LipRight__INP_DIS)
/* LCD Common or Segment Drive */
#define LipRight_LCD_COM_SEG            (* (reg8 *) LipRight__LCD_COM_SEG)
/* Enable Segment LCD */
#define LipRight_LCD_EN                 (* (reg8 *) LipRight__LCD_EN)
/* Slew Rate Control */
#define LipRight_SLW                    (* (reg8 *) LipRight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LipRight_PRTDSI__CAPS_SEL       (* (reg8 *) LipRight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LipRight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LipRight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LipRight_PRTDSI__OE_SEL0        (* (reg8 *) LipRight__PRTDSI__OE_SEL0) 
#define LipRight_PRTDSI__OE_SEL1        (* (reg8 *) LipRight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LipRight_PRTDSI__OUT_SEL0       (* (reg8 *) LipRight__PRTDSI__OUT_SEL0) 
#define LipRight_PRTDSI__OUT_SEL1       (* (reg8 *) LipRight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LipRight_PRTDSI__SYNC_OUT       (* (reg8 *) LipRight__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LipRight__SIO_CFG)
    #define LipRight_SIO_HYST_EN        (* (reg8 *) LipRight__SIO_HYST_EN)
    #define LipRight_SIO_REG_HIFREQ     (* (reg8 *) LipRight__SIO_REG_HIFREQ)
    #define LipRight_SIO_CFG            (* (reg8 *) LipRight__SIO_CFG)
    #define LipRight_SIO_DIFF           (* (reg8 *) LipRight__SIO_DIFF)
#endif /* (LipRight__SIO_CFG) */

/* Interrupt Registers */
#if defined(LipRight__INTSTAT)
    #define LipRight_INTSTAT            (* (reg8 *) LipRight__INTSTAT)
    #define LipRight_SNAP               (* (reg8 *) LipRight__SNAP)
    
	#define LipRight_0_INTTYPE_REG 		(* (reg8 *) LipRight__0__INTTYPE)
#endif /* (LipRight__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LipRight_H */


/* [] END OF FILE */
