/*******************************************************************************
* File Name: LeftEyeballTop.h  
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

#if !defined(CY_PINS_LeftEyeballTop_H) /* Pins LeftEyeballTop_H */
#define CY_PINS_LeftEyeballTop_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LeftEyeballTop_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LeftEyeballTop__PORT == 15 && ((LeftEyeballTop__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LeftEyeballTop_Write(uint8 value);
void    LeftEyeballTop_SetDriveMode(uint8 mode);
uint8   LeftEyeballTop_ReadDataReg(void);
uint8   LeftEyeballTop_Read(void);
void    LeftEyeballTop_SetInterruptMode(uint16 position, uint16 mode);
uint8   LeftEyeballTop_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LeftEyeballTop_SetDriveMode() function.
     *  @{
     */
        #define LeftEyeballTop_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LeftEyeballTop_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LeftEyeballTop_DM_RES_UP          PIN_DM_RES_UP
        #define LeftEyeballTop_DM_RES_DWN         PIN_DM_RES_DWN
        #define LeftEyeballTop_DM_OD_LO           PIN_DM_OD_LO
        #define LeftEyeballTop_DM_OD_HI           PIN_DM_OD_HI
        #define LeftEyeballTop_DM_STRONG          PIN_DM_STRONG
        #define LeftEyeballTop_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LeftEyeballTop_MASK               LeftEyeballTop__MASK
#define LeftEyeballTop_SHIFT              LeftEyeballTop__SHIFT
#define LeftEyeballTop_WIDTH              1u

/* Interrupt constants */
#if defined(LeftEyeballTop__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LeftEyeballTop_SetInterruptMode() function.
     *  @{
     */
        #define LeftEyeballTop_INTR_NONE      (uint16)(0x0000u)
        #define LeftEyeballTop_INTR_RISING    (uint16)(0x0001u)
        #define LeftEyeballTop_INTR_FALLING   (uint16)(0x0002u)
        #define LeftEyeballTop_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LeftEyeballTop_INTR_MASK      (0x01u) 
#endif /* (LeftEyeballTop__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LeftEyeballTop_PS                     (* (reg8 *) LeftEyeballTop__PS)
/* Data Register */
#define LeftEyeballTop_DR                     (* (reg8 *) LeftEyeballTop__DR)
/* Port Number */
#define LeftEyeballTop_PRT_NUM                (* (reg8 *) LeftEyeballTop__PRT) 
/* Connect to Analog Globals */                                                  
#define LeftEyeballTop_AG                     (* (reg8 *) LeftEyeballTop__AG)                       
/* Analog MUX bux enable */
#define LeftEyeballTop_AMUX                   (* (reg8 *) LeftEyeballTop__AMUX) 
/* Bidirectional Enable */                                                        
#define LeftEyeballTop_BIE                    (* (reg8 *) LeftEyeballTop__BIE)
/* Bit-mask for Aliased Register Access */
#define LeftEyeballTop_BIT_MASK               (* (reg8 *) LeftEyeballTop__BIT_MASK)
/* Bypass Enable */
#define LeftEyeballTop_BYP                    (* (reg8 *) LeftEyeballTop__BYP)
/* Port wide control signals */                                                   
#define LeftEyeballTop_CTL                    (* (reg8 *) LeftEyeballTop__CTL)
/* Drive Modes */
#define LeftEyeballTop_DM0                    (* (reg8 *) LeftEyeballTop__DM0) 
#define LeftEyeballTop_DM1                    (* (reg8 *) LeftEyeballTop__DM1)
#define LeftEyeballTop_DM2                    (* (reg8 *) LeftEyeballTop__DM2) 
/* Input Buffer Disable Override */
#define LeftEyeballTop_INP_DIS                (* (reg8 *) LeftEyeballTop__INP_DIS)
/* LCD Common or Segment Drive */
#define LeftEyeballTop_LCD_COM_SEG            (* (reg8 *) LeftEyeballTop__LCD_COM_SEG)
/* Enable Segment LCD */
#define LeftEyeballTop_LCD_EN                 (* (reg8 *) LeftEyeballTop__LCD_EN)
/* Slew Rate Control */
#define LeftEyeballTop_SLW                    (* (reg8 *) LeftEyeballTop__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LeftEyeballTop_PRTDSI__CAPS_SEL       (* (reg8 *) LeftEyeballTop__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LeftEyeballTop_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LeftEyeballTop__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LeftEyeballTop_PRTDSI__OE_SEL0        (* (reg8 *) LeftEyeballTop__PRTDSI__OE_SEL0) 
#define LeftEyeballTop_PRTDSI__OE_SEL1        (* (reg8 *) LeftEyeballTop__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LeftEyeballTop_PRTDSI__OUT_SEL0       (* (reg8 *) LeftEyeballTop__PRTDSI__OUT_SEL0) 
#define LeftEyeballTop_PRTDSI__OUT_SEL1       (* (reg8 *) LeftEyeballTop__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LeftEyeballTop_PRTDSI__SYNC_OUT       (* (reg8 *) LeftEyeballTop__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LeftEyeballTop__SIO_CFG)
    #define LeftEyeballTop_SIO_HYST_EN        (* (reg8 *) LeftEyeballTop__SIO_HYST_EN)
    #define LeftEyeballTop_SIO_REG_HIFREQ     (* (reg8 *) LeftEyeballTop__SIO_REG_HIFREQ)
    #define LeftEyeballTop_SIO_CFG            (* (reg8 *) LeftEyeballTop__SIO_CFG)
    #define LeftEyeballTop_SIO_DIFF           (* (reg8 *) LeftEyeballTop__SIO_DIFF)
#endif /* (LeftEyeballTop__SIO_CFG) */

/* Interrupt Registers */
#if defined(LeftEyeballTop__INTSTAT)
    #define LeftEyeballTop_INTSTAT            (* (reg8 *) LeftEyeballTop__INTSTAT)
    #define LeftEyeballTop_SNAP               (* (reg8 *) LeftEyeballTop__SNAP)
    
	#define LeftEyeballTop_0_INTTYPE_REG 		(* (reg8 *) LeftEyeballTop__0__INTTYPE)
#endif /* (LeftEyeballTop__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LeftEyeballTop_H */


/* [] END OF FILE */
