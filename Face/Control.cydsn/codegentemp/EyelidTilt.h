/*******************************************************************************
* File Name: EyelidTilt.h  
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

#if !defined(CY_PINS_EyelidTilt_H) /* Pins EyelidTilt_H */
#define CY_PINS_EyelidTilt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EyelidTilt_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EyelidTilt__PORT == 15 && ((EyelidTilt__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    EyelidTilt_Write(uint8 value);
void    EyelidTilt_SetDriveMode(uint8 mode);
uint8   EyelidTilt_ReadDataReg(void);
uint8   EyelidTilt_Read(void);
void    EyelidTilt_SetInterruptMode(uint16 position, uint16 mode);
uint8   EyelidTilt_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the EyelidTilt_SetDriveMode() function.
     *  @{
     */
        #define EyelidTilt_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define EyelidTilt_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define EyelidTilt_DM_RES_UP          PIN_DM_RES_UP
        #define EyelidTilt_DM_RES_DWN         PIN_DM_RES_DWN
        #define EyelidTilt_DM_OD_LO           PIN_DM_OD_LO
        #define EyelidTilt_DM_OD_HI           PIN_DM_OD_HI
        #define EyelidTilt_DM_STRONG          PIN_DM_STRONG
        #define EyelidTilt_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define EyelidTilt_MASK               EyelidTilt__MASK
#define EyelidTilt_SHIFT              EyelidTilt__SHIFT
#define EyelidTilt_WIDTH              1u

/* Interrupt constants */
#if defined(EyelidTilt__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EyelidTilt_SetInterruptMode() function.
     *  @{
     */
        #define EyelidTilt_INTR_NONE      (uint16)(0x0000u)
        #define EyelidTilt_INTR_RISING    (uint16)(0x0001u)
        #define EyelidTilt_INTR_FALLING   (uint16)(0x0002u)
        #define EyelidTilt_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define EyelidTilt_INTR_MASK      (0x01u) 
#endif /* (EyelidTilt__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EyelidTilt_PS                     (* (reg8 *) EyelidTilt__PS)
/* Data Register */
#define EyelidTilt_DR                     (* (reg8 *) EyelidTilt__DR)
/* Port Number */
#define EyelidTilt_PRT_NUM                (* (reg8 *) EyelidTilt__PRT) 
/* Connect to Analog Globals */                                                  
#define EyelidTilt_AG                     (* (reg8 *) EyelidTilt__AG)                       
/* Analog MUX bux enable */
#define EyelidTilt_AMUX                   (* (reg8 *) EyelidTilt__AMUX) 
/* Bidirectional Enable */                                                        
#define EyelidTilt_BIE                    (* (reg8 *) EyelidTilt__BIE)
/* Bit-mask for Aliased Register Access */
#define EyelidTilt_BIT_MASK               (* (reg8 *) EyelidTilt__BIT_MASK)
/* Bypass Enable */
#define EyelidTilt_BYP                    (* (reg8 *) EyelidTilt__BYP)
/* Port wide control signals */                                                   
#define EyelidTilt_CTL                    (* (reg8 *) EyelidTilt__CTL)
/* Drive Modes */
#define EyelidTilt_DM0                    (* (reg8 *) EyelidTilt__DM0) 
#define EyelidTilt_DM1                    (* (reg8 *) EyelidTilt__DM1)
#define EyelidTilt_DM2                    (* (reg8 *) EyelidTilt__DM2) 
/* Input Buffer Disable Override */
#define EyelidTilt_INP_DIS                (* (reg8 *) EyelidTilt__INP_DIS)
/* LCD Common or Segment Drive */
#define EyelidTilt_LCD_COM_SEG            (* (reg8 *) EyelidTilt__LCD_COM_SEG)
/* Enable Segment LCD */
#define EyelidTilt_LCD_EN                 (* (reg8 *) EyelidTilt__LCD_EN)
/* Slew Rate Control */
#define EyelidTilt_SLW                    (* (reg8 *) EyelidTilt__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EyelidTilt_PRTDSI__CAPS_SEL       (* (reg8 *) EyelidTilt__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EyelidTilt_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EyelidTilt__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EyelidTilt_PRTDSI__OE_SEL0        (* (reg8 *) EyelidTilt__PRTDSI__OE_SEL0) 
#define EyelidTilt_PRTDSI__OE_SEL1        (* (reg8 *) EyelidTilt__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EyelidTilt_PRTDSI__OUT_SEL0       (* (reg8 *) EyelidTilt__PRTDSI__OUT_SEL0) 
#define EyelidTilt_PRTDSI__OUT_SEL1       (* (reg8 *) EyelidTilt__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EyelidTilt_PRTDSI__SYNC_OUT       (* (reg8 *) EyelidTilt__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(EyelidTilt__SIO_CFG)
    #define EyelidTilt_SIO_HYST_EN        (* (reg8 *) EyelidTilt__SIO_HYST_EN)
    #define EyelidTilt_SIO_REG_HIFREQ     (* (reg8 *) EyelidTilt__SIO_REG_HIFREQ)
    #define EyelidTilt_SIO_CFG            (* (reg8 *) EyelidTilt__SIO_CFG)
    #define EyelidTilt_SIO_DIFF           (* (reg8 *) EyelidTilt__SIO_DIFF)
#endif /* (EyelidTilt__SIO_CFG) */

/* Interrupt Registers */
#if defined(EyelidTilt__INTSTAT)
    #define EyelidTilt_INTSTAT            (* (reg8 *) EyelidTilt__INTSTAT)
    #define EyelidTilt_SNAP               (* (reg8 *) EyelidTilt__SNAP)
    
	#define EyelidTilt_0_INTTYPE_REG 		(* (reg8 *) EyelidTilt__0__INTTYPE)
#endif /* (EyelidTilt__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EyelidTilt_H */


/* [] END OF FILE */
