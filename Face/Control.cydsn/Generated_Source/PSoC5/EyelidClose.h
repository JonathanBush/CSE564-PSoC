/*******************************************************************************
* File Name: EyelidClose.h  
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

#if !defined(CY_PINS_EyelidClose_H) /* Pins EyelidClose_H */
#define CY_PINS_EyelidClose_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EyelidClose_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EyelidClose__PORT == 15 && ((EyelidClose__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    EyelidClose_Write(uint8 value);
void    EyelidClose_SetDriveMode(uint8 mode);
uint8   EyelidClose_ReadDataReg(void);
uint8   EyelidClose_Read(void);
void    EyelidClose_SetInterruptMode(uint16 position, uint16 mode);
uint8   EyelidClose_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the EyelidClose_SetDriveMode() function.
     *  @{
     */
        #define EyelidClose_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define EyelidClose_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define EyelidClose_DM_RES_UP          PIN_DM_RES_UP
        #define EyelidClose_DM_RES_DWN         PIN_DM_RES_DWN
        #define EyelidClose_DM_OD_LO           PIN_DM_OD_LO
        #define EyelidClose_DM_OD_HI           PIN_DM_OD_HI
        #define EyelidClose_DM_STRONG          PIN_DM_STRONG
        #define EyelidClose_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define EyelidClose_MASK               EyelidClose__MASK
#define EyelidClose_SHIFT              EyelidClose__SHIFT
#define EyelidClose_WIDTH              1u

/* Interrupt constants */
#if defined(EyelidClose__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EyelidClose_SetInterruptMode() function.
     *  @{
     */
        #define EyelidClose_INTR_NONE      (uint16)(0x0000u)
        #define EyelidClose_INTR_RISING    (uint16)(0x0001u)
        #define EyelidClose_INTR_FALLING   (uint16)(0x0002u)
        #define EyelidClose_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define EyelidClose_INTR_MASK      (0x01u) 
#endif /* (EyelidClose__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EyelidClose_PS                     (* (reg8 *) EyelidClose__PS)
/* Data Register */
#define EyelidClose_DR                     (* (reg8 *) EyelidClose__DR)
/* Port Number */
#define EyelidClose_PRT_NUM                (* (reg8 *) EyelidClose__PRT) 
/* Connect to Analog Globals */                                                  
#define EyelidClose_AG                     (* (reg8 *) EyelidClose__AG)                       
/* Analog MUX bux enable */
#define EyelidClose_AMUX                   (* (reg8 *) EyelidClose__AMUX) 
/* Bidirectional Enable */                                                        
#define EyelidClose_BIE                    (* (reg8 *) EyelidClose__BIE)
/* Bit-mask for Aliased Register Access */
#define EyelidClose_BIT_MASK               (* (reg8 *) EyelidClose__BIT_MASK)
/* Bypass Enable */
#define EyelidClose_BYP                    (* (reg8 *) EyelidClose__BYP)
/* Port wide control signals */                                                   
#define EyelidClose_CTL                    (* (reg8 *) EyelidClose__CTL)
/* Drive Modes */
#define EyelidClose_DM0                    (* (reg8 *) EyelidClose__DM0) 
#define EyelidClose_DM1                    (* (reg8 *) EyelidClose__DM1)
#define EyelidClose_DM2                    (* (reg8 *) EyelidClose__DM2) 
/* Input Buffer Disable Override */
#define EyelidClose_INP_DIS                (* (reg8 *) EyelidClose__INP_DIS)
/* LCD Common or Segment Drive */
#define EyelidClose_LCD_COM_SEG            (* (reg8 *) EyelidClose__LCD_COM_SEG)
/* Enable Segment LCD */
#define EyelidClose_LCD_EN                 (* (reg8 *) EyelidClose__LCD_EN)
/* Slew Rate Control */
#define EyelidClose_SLW                    (* (reg8 *) EyelidClose__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EyelidClose_PRTDSI__CAPS_SEL       (* (reg8 *) EyelidClose__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EyelidClose_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EyelidClose__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EyelidClose_PRTDSI__OE_SEL0        (* (reg8 *) EyelidClose__PRTDSI__OE_SEL0) 
#define EyelidClose_PRTDSI__OE_SEL1        (* (reg8 *) EyelidClose__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EyelidClose_PRTDSI__OUT_SEL0       (* (reg8 *) EyelidClose__PRTDSI__OUT_SEL0) 
#define EyelidClose_PRTDSI__OUT_SEL1       (* (reg8 *) EyelidClose__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EyelidClose_PRTDSI__SYNC_OUT       (* (reg8 *) EyelidClose__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(EyelidClose__SIO_CFG)
    #define EyelidClose_SIO_HYST_EN        (* (reg8 *) EyelidClose__SIO_HYST_EN)
    #define EyelidClose_SIO_REG_HIFREQ     (* (reg8 *) EyelidClose__SIO_REG_HIFREQ)
    #define EyelidClose_SIO_CFG            (* (reg8 *) EyelidClose__SIO_CFG)
    #define EyelidClose_SIO_DIFF           (* (reg8 *) EyelidClose__SIO_DIFF)
#endif /* (EyelidClose__SIO_CFG) */

/* Interrupt Registers */
#if defined(EyelidClose__INTSTAT)
    #define EyelidClose_INTSTAT            (* (reg8 *) EyelidClose__INTSTAT)
    #define EyelidClose_SNAP               (* (reg8 *) EyelidClose__SNAP)
    
	#define EyelidClose_0_INTTYPE_REG 		(* (reg8 *) EyelidClose__0__INTTYPE)
#endif /* (EyelidClose__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EyelidClose_H */


/* [] END OF FILE */
