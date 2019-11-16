/*******************************************************************************
* File Name: LeftEyebrow2.h  
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

#if !defined(CY_PINS_LeftEyebrow2_H) /* Pins LeftEyebrow2_H */
#define CY_PINS_LeftEyebrow2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LeftEyebrow2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LeftEyebrow2__PORT == 15 && ((LeftEyebrow2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LeftEyebrow2_Write(uint8 value);
void    LeftEyebrow2_SetDriveMode(uint8 mode);
uint8   LeftEyebrow2_ReadDataReg(void);
uint8   LeftEyebrow2_Read(void);
void    LeftEyebrow2_SetInterruptMode(uint16 position, uint16 mode);
uint8   LeftEyebrow2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LeftEyebrow2_SetDriveMode() function.
     *  @{
     */
        #define LeftEyebrow2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LeftEyebrow2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LeftEyebrow2_DM_RES_UP          PIN_DM_RES_UP
        #define LeftEyebrow2_DM_RES_DWN         PIN_DM_RES_DWN
        #define LeftEyebrow2_DM_OD_LO           PIN_DM_OD_LO
        #define LeftEyebrow2_DM_OD_HI           PIN_DM_OD_HI
        #define LeftEyebrow2_DM_STRONG          PIN_DM_STRONG
        #define LeftEyebrow2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LeftEyebrow2_MASK               LeftEyebrow2__MASK
#define LeftEyebrow2_SHIFT              LeftEyebrow2__SHIFT
#define LeftEyebrow2_WIDTH              1u

/* Interrupt constants */
#if defined(LeftEyebrow2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LeftEyebrow2_SetInterruptMode() function.
     *  @{
     */
        #define LeftEyebrow2_INTR_NONE      (uint16)(0x0000u)
        #define LeftEyebrow2_INTR_RISING    (uint16)(0x0001u)
        #define LeftEyebrow2_INTR_FALLING   (uint16)(0x0002u)
        #define LeftEyebrow2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LeftEyebrow2_INTR_MASK      (0x01u) 
#endif /* (LeftEyebrow2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LeftEyebrow2_PS                     (* (reg8 *) LeftEyebrow2__PS)
/* Data Register */
#define LeftEyebrow2_DR                     (* (reg8 *) LeftEyebrow2__DR)
/* Port Number */
#define LeftEyebrow2_PRT_NUM                (* (reg8 *) LeftEyebrow2__PRT) 
/* Connect to Analog Globals */                                                  
#define LeftEyebrow2_AG                     (* (reg8 *) LeftEyebrow2__AG)                       
/* Analog MUX bux enable */
#define LeftEyebrow2_AMUX                   (* (reg8 *) LeftEyebrow2__AMUX) 
/* Bidirectional Enable */                                                        
#define LeftEyebrow2_BIE                    (* (reg8 *) LeftEyebrow2__BIE)
/* Bit-mask for Aliased Register Access */
#define LeftEyebrow2_BIT_MASK               (* (reg8 *) LeftEyebrow2__BIT_MASK)
/* Bypass Enable */
#define LeftEyebrow2_BYP                    (* (reg8 *) LeftEyebrow2__BYP)
/* Port wide control signals */                                                   
#define LeftEyebrow2_CTL                    (* (reg8 *) LeftEyebrow2__CTL)
/* Drive Modes */
#define LeftEyebrow2_DM0                    (* (reg8 *) LeftEyebrow2__DM0) 
#define LeftEyebrow2_DM1                    (* (reg8 *) LeftEyebrow2__DM1)
#define LeftEyebrow2_DM2                    (* (reg8 *) LeftEyebrow2__DM2) 
/* Input Buffer Disable Override */
#define LeftEyebrow2_INP_DIS                (* (reg8 *) LeftEyebrow2__INP_DIS)
/* LCD Common or Segment Drive */
#define LeftEyebrow2_LCD_COM_SEG            (* (reg8 *) LeftEyebrow2__LCD_COM_SEG)
/* Enable Segment LCD */
#define LeftEyebrow2_LCD_EN                 (* (reg8 *) LeftEyebrow2__LCD_EN)
/* Slew Rate Control */
#define LeftEyebrow2_SLW                    (* (reg8 *) LeftEyebrow2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LeftEyebrow2_PRTDSI__CAPS_SEL       (* (reg8 *) LeftEyebrow2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LeftEyebrow2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LeftEyebrow2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LeftEyebrow2_PRTDSI__OE_SEL0        (* (reg8 *) LeftEyebrow2__PRTDSI__OE_SEL0) 
#define LeftEyebrow2_PRTDSI__OE_SEL1        (* (reg8 *) LeftEyebrow2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LeftEyebrow2_PRTDSI__OUT_SEL0       (* (reg8 *) LeftEyebrow2__PRTDSI__OUT_SEL0) 
#define LeftEyebrow2_PRTDSI__OUT_SEL1       (* (reg8 *) LeftEyebrow2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LeftEyebrow2_PRTDSI__SYNC_OUT       (* (reg8 *) LeftEyebrow2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LeftEyebrow2__SIO_CFG)
    #define LeftEyebrow2_SIO_HYST_EN        (* (reg8 *) LeftEyebrow2__SIO_HYST_EN)
    #define LeftEyebrow2_SIO_REG_HIFREQ     (* (reg8 *) LeftEyebrow2__SIO_REG_HIFREQ)
    #define LeftEyebrow2_SIO_CFG            (* (reg8 *) LeftEyebrow2__SIO_CFG)
    #define LeftEyebrow2_SIO_DIFF           (* (reg8 *) LeftEyebrow2__SIO_DIFF)
#endif /* (LeftEyebrow2__SIO_CFG) */

/* Interrupt Registers */
#if defined(LeftEyebrow2__INTSTAT)
    #define LeftEyebrow2_INTSTAT            (* (reg8 *) LeftEyebrow2__INTSTAT)
    #define LeftEyebrow2_SNAP               (* (reg8 *) LeftEyebrow2__SNAP)
    
	#define LeftEyebrow2_0_INTTYPE_REG 		(* (reg8 *) LeftEyebrow2__0__INTTYPE)
#endif /* (LeftEyebrow2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LeftEyebrow2_H */


/* [] END OF FILE */
