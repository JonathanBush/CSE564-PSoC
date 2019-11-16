/*******************************************************************************
* File Name: LipLeft.h  
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

#if !defined(CY_PINS_LipLeft_H) /* Pins LipLeft_H */
#define CY_PINS_LipLeft_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LipLeft_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LipLeft__PORT == 15 && ((LipLeft__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LipLeft_Write(uint8 value);
void    LipLeft_SetDriveMode(uint8 mode);
uint8   LipLeft_ReadDataReg(void);
uint8   LipLeft_Read(void);
void    LipLeft_SetInterruptMode(uint16 position, uint16 mode);
uint8   LipLeft_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LipLeft_SetDriveMode() function.
     *  @{
     */
        #define LipLeft_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LipLeft_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LipLeft_DM_RES_UP          PIN_DM_RES_UP
        #define LipLeft_DM_RES_DWN         PIN_DM_RES_DWN
        #define LipLeft_DM_OD_LO           PIN_DM_OD_LO
        #define LipLeft_DM_OD_HI           PIN_DM_OD_HI
        #define LipLeft_DM_STRONG          PIN_DM_STRONG
        #define LipLeft_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LipLeft_MASK               LipLeft__MASK
#define LipLeft_SHIFT              LipLeft__SHIFT
#define LipLeft_WIDTH              1u

/* Interrupt constants */
#if defined(LipLeft__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LipLeft_SetInterruptMode() function.
     *  @{
     */
        #define LipLeft_INTR_NONE      (uint16)(0x0000u)
        #define LipLeft_INTR_RISING    (uint16)(0x0001u)
        #define LipLeft_INTR_FALLING   (uint16)(0x0002u)
        #define LipLeft_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LipLeft_INTR_MASK      (0x01u) 
#endif /* (LipLeft__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LipLeft_PS                     (* (reg8 *) LipLeft__PS)
/* Data Register */
#define LipLeft_DR                     (* (reg8 *) LipLeft__DR)
/* Port Number */
#define LipLeft_PRT_NUM                (* (reg8 *) LipLeft__PRT) 
/* Connect to Analog Globals */                                                  
#define LipLeft_AG                     (* (reg8 *) LipLeft__AG)                       
/* Analog MUX bux enable */
#define LipLeft_AMUX                   (* (reg8 *) LipLeft__AMUX) 
/* Bidirectional Enable */                                                        
#define LipLeft_BIE                    (* (reg8 *) LipLeft__BIE)
/* Bit-mask for Aliased Register Access */
#define LipLeft_BIT_MASK               (* (reg8 *) LipLeft__BIT_MASK)
/* Bypass Enable */
#define LipLeft_BYP                    (* (reg8 *) LipLeft__BYP)
/* Port wide control signals */                                                   
#define LipLeft_CTL                    (* (reg8 *) LipLeft__CTL)
/* Drive Modes */
#define LipLeft_DM0                    (* (reg8 *) LipLeft__DM0) 
#define LipLeft_DM1                    (* (reg8 *) LipLeft__DM1)
#define LipLeft_DM2                    (* (reg8 *) LipLeft__DM2) 
/* Input Buffer Disable Override */
#define LipLeft_INP_DIS                (* (reg8 *) LipLeft__INP_DIS)
/* LCD Common or Segment Drive */
#define LipLeft_LCD_COM_SEG            (* (reg8 *) LipLeft__LCD_COM_SEG)
/* Enable Segment LCD */
#define LipLeft_LCD_EN                 (* (reg8 *) LipLeft__LCD_EN)
/* Slew Rate Control */
#define LipLeft_SLW                    (* (reg8 *) LipLeft__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LipLeft_PRTDSI__CAPS_SEL       (* (reg8 *) LipLeft__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LipLeft_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LipLeft__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LipLeft_PRTDSI__OE_SEL0        (* (reg8 *) LipLeft__PRTDSI__OE_SEL0) 
#define LipLeft_PRTDSI__OE_SEL1        (* (reg8 *) LipLeft__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LipLeft_PRTDSI__OUT_SEL0       (* (reg8 *) LipLeft__PRTDSI__OUT_SEL0) 
#define LipLeft_PRTDSI__OUT_SEL1       (* (reg8 *) LipLeft__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LipLeft_PRTDSI__SYNC_OUT       (* (reg8 *) LipLeft__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LipLeft__SIO_CFG)
    #define LipLeft_SIO_HYST_EN        (* (reg8 *) LipLeft__SIO_HYST_EN)
    #define LipLeft_SIO_REG_HIFREQ     (* (reg8 *) LipLeft__SIO_REG_HIFREQ)
    #define LipLeft_SIO_CFG            (* (reg8 *) LipLeft__SIO_CFG)
    #define LipLeft_SIO_DIFF           (* (reg8 *) LipLeft__SIO_DIFF)
#endif /* (LipLeft__SIO_CFG) */

/* Interrupt Registers */
#if defined(LipLeft__INTSTAT)
    #define LipLeft_INTSTAT            (* (reg8 *) LipLeft__INTSTAT)
    #define LipLeft_SNAP               (* (reg8 *) LipLeft__SNAP)
    
	#define LipLeft_0_INTTYPE_REG 		(* (reg8 *) LipLeft__0__INTTYPE)
#endif /* (LipLeft__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LipLeft_H */


/* [] END OF FILE */
