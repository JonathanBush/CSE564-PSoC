/*******************************************************************************
* File Name: LeftEyebrow1.h  
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

#if !defined(CY_PINS_LeftEyebrow1_H) /* Pins LeftEyebrow1_H */
#define CY_PINS_LeftEyebrow1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LeftEyebrow1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LeftEyebrow1__PORT == 15 && ((LeftEyebrow1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LeftEyebrow1_Write(uint8 value);
void    LeftEyebrow1_SetDriveMode(uint8 mode);
uint8   LeftEyebrow1_ReadDataReg(void);
uint8   LeftEyebrow1_Read(void);
void    LeftEyebrow1_SetInterruptMode(uint16 position, uint16 mode);
uint8   LeftEyebrow1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LeftEyebrow1_SetDriveMode() function.
     *  @{
     */
        #define LeftEyebrow1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LeftEyebrow1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LeftEyebrow1_DM_RES_UP          PIN_DM_RES_UP
        #define LeftEyebrow1_DM_RES_DWN         PIN_DM_RES_DWN
        #define LeftEyebrow1_DM_OD_LO           PIN_DM_OD_LO
        #define LeftEyebrow1_DM_OD_HI           PIN_DM_OD_HI
        #define LeftEyebrow1_DM_STRONG          PIN_DM_STRONG
        #define LeftEyebrow1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LeftEyebrow1_MASK               LeftEyebrow1__MASK
#define LeftEyebrow1_SHIFT              LeftEyebrow1__SHIFT
#define LeftEyebrow1_WIDTH              1u

/* Interrupt constants */
#if defined(LeftEyebrow1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LeftEyebrow1_SetInterruptMode() function.
     *  @{
     */
        #define LeftEyebrow1_INTR_NONE      (uint16)(0x0000u)
        #define LeftEyebrow1_INTR_RISING    (uint16)(0x0001u)
        #define LeftEyebrow1_INTR_FALLING   (uint16)(0x0002u)
        #define LeftEyebrow1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LeftEyebrow1_INTR_MASK      (0x01u) 
#endif /* (LeftEyebrow1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LeftEyebrow1_PS                     (* (reg8 *) LeftEyebrow1__PS)
/* Data Register */
#define LeftEyebrow1_DR                     (* (reg8 *) LeftEyebrow1__DR)
/* Port Number */
#define LeftEyebrow1_PRT_NUM                (* (reg8 *) LeftEyebrow1__PRT) 
/* Connect to Analog Globals */                                                  
#define LeftEyebrow1_AG                     (* (reg8 *) LeftEyebrow1__AG)                       
/* Analog MUX bux enable */
#define LeftEyebrow1_AMUX                   (* (reg8 *) LeftEyebrow1__AMUX) 
/* Bidirectional Enable */                                                        
#define LeftEyebrow1_BIE                    (* (reg8 *) LeftEyebrow1__BIE)
/* Bit-mask for Aliased Register Access */
#define LeftEyebrow1_BIT_MASK               (* (reg8 *) LeftEyebrow1__BIT_MASK)
/* Bypass Enable */
#define LeftEyebrow1_BYP                    (* (reg8 *) LeftEyebrow1__BYP)
/* Port wide control signals */                                                   
#define LeftEyebrow1_CTL                    (* (reg8 *) LeftEyebrow1__CTL)
/* Drive Modes */
#define LeftEyebrow1_DM0                    (* (reg8 *) LeftEyebrow1__DM0) 
#define LeftEyebrow1_DM1                    (* (reg8 *) LeftEyebrow1__DM1)
#define LeftEyebrow1_DM2                    (* (reg8 *) LeftEyebrow1__DM2) 
/* Input Buffer Disable Override */
#define LeftEyebrow1_INP_DIS                (* (reg8 *) LeftEyebrow1__INP_DIS)
/* LCD Common or Segment Drive */
#define LeftEyebrow1_LCD_COM_SEG            (* (reg8 *) LeftEyebrow1__LCD_COM_SEG)
/* Enable Segment LCD */
#define LeftEyebrow1_LCD_EN                 (* (reg8 *) LeftEyebrow1__LCD_EN)
/* Slew Rate Control */
#define LeftEyebrow1_SLW                    (* (reg8 *) LeftEyebrow1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LeftEyebrow1_PRTDSI__CAPS_SEL       (* (reg8 *) LeftEyebrow1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LeftEyebrow1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LeftEyebrow1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LeftEyebrow1_PRTDSI__OE_SEL0        (* (reg8 *) LeftEyebrow1__PRTDSI__OE_SEL0) 
#define LeftEyebrow1_PRTDSI__OE_SEL1        (* (reg8 *) LeftEyebrow1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LeftEyebrow1_PRTDSI__OUT_SEL0       (* (reg8 *) LeftEyebrow1__PRTDSI__OUT_SEL0) 
#define LeftEyebrow1_PRTDSI__OUT_SEL1       (* (reg8 *) LeftEyebrow1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LeftEyebrow1_PRTDSI__SYNC_OUT       (* (reg8 *) LeftEyebrow1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LeftEyebrow1__SIO_CFG)
    #define LeftEyebrow1_SIO_HYST_EN        (* (reg8 *) LeftEyebrow1__SIO_HYST_EN)
    #define LeftEyebrow1_SIO_REG_HIFREQ     (* (reg8 *) LeftEyebrow1__SIO_REG_HIFREQ)
    #define LeftEyebrow1_SIO_CFG            (* (reg8 *) LeftEyebrow1__SIO_CFG)
    #define LeftEyebrow1_SIO_DIFF           (* (reg8 *) LeftEyebrow1__SIO_DIFF)
#endif /* (LeftEyebrow1__SIO_CFG) */

/* Interrupt Registers */
#if defined(LeftEyebrow1__INTSTAT)
    #define LeftEyebrow1_INTSTAT            (* (reg8 *) LeftEyebrow1__INTSTAT)
    #define LeftEyebrow1_SNAP               (* (reg8 *) LeftEyebrow1__SNAP)
    
	#define LeftEyebrow1_0_INTTYPE_REG 		(* (reg8 *) LeftEyebrow1__0__INTTYPE)
#endif /* (LeftEyebrow1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LeftEyebrow1_H */


/* [] END OF FILE */
