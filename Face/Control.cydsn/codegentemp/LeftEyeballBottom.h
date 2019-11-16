/*******************************************************************************
* File Name: LeftEyeballBottom.h  
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

#if !defined(CY_PINS_LeftEyeballBottom_H) /* Pins LeftEyeballBottom_H */
#define CY_PINS_LeftEyeballBottom_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LeftEyeballBottom_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LeftEyeballBottom__PORT == 15 && ((LeftEyeballBottom__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LeftEyeballBottom_Write(uint8 value);
void    LeftEyeballBottom_SetDriveMode(uint8 mode);
uint8   LeftEyeballBottom_ReadDataReg(void);
uint8   LeftEyeballBottom_Read(void);
void    LeftEyeballBottom_SetInterruptMode(uint16 position, uint16 mode);
uint8   LeftEyeballBottom_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LeftEyeballBottom_SetDriveMode() function.
     *  @{
     */
        #define LeftEyeballBottom_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LeftEyeballBottom_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LeftEyeballBottom_DM_RES_UP          PIN_DM_RES_UP
        #define LeftEyeballBottom_DM_RES_DWN         PIN_DM_RES_DWN
        #define LeftEyeballBottom_DM_OD_LO           PIN_DM_OD_LO
        #define LeftEyeballBottom_DM_OD_HI           PIN_DM_OD_HI
        #define LeftEyeballBottom_DM_STRONG          PIN_DM_STRONG
        #define LeftEyeballBottom_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LeftEyeballBottom_MASK               LeftEyeballBottom__MASK
#define LeftEyeballBottom_SHIFT              LeftEyeballBottom__SHIFT
#define LeftEyeballBottom_WIDTH              1u

/* Interrupt constants */
#if defined(LeftEyeballBottom__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LeftEyeballBottom_SetInterruptMode() function.
     *  @{
     */
        #define LeftEyeballBottom_INTR_NONE      (uint16)(0x0000u)
        #define LeftEyeballBottom_INTR_RISING    (uint16)(0x0001u)
        #define LeftEyeballBottom_INTR_FALLING   (uint16)(0x0002u)
        #define LeftEyeballBottom_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LeftEyeballBottom_INTR_MASK      (0x01u) 
#endif /* (LeftEyeballBottom__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LeftEyeballBottom_PS                     (* (reg8 *) LeftEyeballBottom__PS)
/* Data Register */
#define LeftEyeballBottom_DR                     (* (reg8 *) LeftEyeballBottom__DR)
/* Port Number */
#define LeftEyeballBottom_PRT_NUM                (* (reg8 *) LeftEyeballBottom__PRT) 
/* Connect to Analog Globals */                                                  
#define LeftEyeballBottom_AG                     (* (reg8 *) LeftEyeballBottom__AG)                       
/* Analog MUX bux enable */
#define LeftEyeballBottom_AMUX                   (* (reg8 *) LeftEyeballBottom__AMUX) 
/* Bidirectional Enable */                                                        
#define LeftEyeballBottom_BIE                    (* (reg8 *) LeftEyeballBottom__BIE)
/* Bit-mask for Aliased Register Access */
#define LeftEyeballBottom_BIT_MASK               (* (reg8 *) LeftEyeballBottom__BIT_MASK)
/* Bypass Enable */
#define LeftEyeballBottom_BYP                    (* (reg8 *) LeftEyeballBottom__BYP)
/* Port wide control signals */                                                   
#define LeftEyeballBottom_CTL                    (* (reg8 *) LeftEyeballBottom__CTL)
/* Drive Modes */
#define LeftEyeballBottom_DM0                    (* (reg8 *) LeftEyeballBottom__DM0) 
#define LeftEyeballBottom_DM1                    (* (reg8 *) LeftEyeballBottom__DM1)
#define LeftEyeballBottom_DM2                    (* (reg8 *) LeftEyeballBottom__DM2) 
/* Input Buffer Disable Override */
#define LeftEyeballBottom_INP_DIS                (* (reg8 *) LeftEyeballBottom__INP_DIS)
/* LCD Common or Segment Drive */
#define LeftEyeballBottom_LCD_COM_SEG            (* (reg8 *) LeftEyeballBottom__LCD_COM_SEG)
/* Enable Segment LCD */
#define LeftEyeballBottom_LCD_EN                 (* (reg8 *) LeftEyeballBottom__LCD_EN)
/* Slew Rate Control */
#define LeftEyeballBottom_SLW                    (* (reg8 *) LeftEyeballBottom__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LeftEyeballBottom_PRTDSI__CAPS_SEL       (* (reg8 *) LeftEyeballBottom__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LeftEyeballBottom_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LeftEyeballBottom__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LeftEyeballBottom_PRTDSI__OE_SEL0        (* (reg8 *) LeftEyeballBottom__PRTDSI__OE_SEL0) 
#define LeftEyeballBottom_PRTDSI__OE_SEL1        (* (reg8 *) LeftEyeballBottom__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LeftEyeballBottom_PRTDSI__OUT_SEL0       (* (reg8 *) LeftEyeballBottom__PRTDSI__OUT_SEL0) 
#define LeftEyeballBottom_PRTDSI__OUT_SEL1       (* (reg8 *) LeftEyeballBottom__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LeftEyeballBottom_PRTDSI__SYNC_OUT       (* (reg8 *) LeftEyeballBottom__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LeftEyeballBottom__SIO_CFG)
    #define LeftEyeballBottom_SIO_HYST_EN        (* (reg8 *) LeftEyeballBottom__SIO_HYST_EN)
    #define LeftEyeballBottom_SIO_REG_HIFREQ     (* (reg8 *) LeftEyeballBottom__SIO_REG_HIFREQ)
    #define LeftEyeballBottom_SIO_CFG            (* (reg8 *) LeftEyeballBottom__SIO_CFG)
    #define LeftEyeballBottom_SIO_DIFF           (* (reg8 *) LeftEyeballBottom__SIO_DIFF)
#endif /* (LeftEyeballBottom__SIO_CFG) */

/* Interrupt Registers */
#if defined(LeftEyeballBottom__INTSTAT)
    #define LeftEyeballBottom_INTSTAT            (* (reg8 *) LeftEyeballBottom__INTSTAT)
    #define LeftEyeballBottom_SNAP               (* (reg8 *) LeftEyeballBottom__SNAP)
    
	#define LeftEyeballBottom_0_INTTYPE_REG 		(* (reg8 *) LeftEyeballBottom__0__INTTYPE)
#endif /* (LeftEyeballBottom__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LeftEyeballBottom_H */


/* [] END OF FILE */
