/*******************************************************************************
* File Name: Rotation.h  
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

#if !defined(CY_PINS_Rotation_H) /* Pins Rotation_H */
#define CY_PINS_Rotation_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rotation_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rotation__PORT == 15 && ((Rotation__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rotation_Write(uint8 value);
void    Rotation_SetDriveMode(uint8 mode);
uint8   Rotation_ReadDataReg(void);
uint8   Rotation_Read(void);
void    Rotation_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rotation_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rotation_SetDriveMode() function.
     *  @{
     */
        #define Rotation_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rotation_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rotation_DM_RES_UP          PIN_DM_RES_UP
        #define Rotation_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rotation_DM_OD_LO           PIN_DM_OD_LO
        #define Rotation_DM_OD_HI           PIN_DM_OD_HI
        #define Rotation_DM_STRONG          PIN_DM_STRONG
        #define Rotation_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rotation_MASK               Rotation__MASK
#define Rotation_SHIFT              Rotation__SHIFT
#define Rotation_WIDTH              1u

/* Interrupt constants */
#if defined(Rotation__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rotation_SetInterruptMode() function.
     *  @{
     */
        #define Rotation_INTR_NONE      (uint16)(0x0000u)
        #define Rotation_INTR_RISING    (uint16)(0x0001u)
        #define Rotation_INTR_FALLING   (uint16)(0x0002u)
        #define Rotation_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rotation_INTR_MASK      (0x01u) 
#endif /* (Rotation__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rotation_PS                     (* (reg8 *) Rotation__PS)
/* Data Register */
#define Rotation_DR                     (* (reg8 *) Rotation__DR)
/* Port Number */
#define Rotation_PRT_NUM                (* (reg8 *) Rotation__PRT) 
/* Connect to Analog Globals */                                                  
#define Rotation_AG                     (* (reg8 *) Rotation__AG)                       
/* Analog MUX bux enable */
#define Rotation_AMUX                   (* (reg8 *) Rotation__AMUX) 
/* Bidirectional Enable */                                                        
#define Rotation_BIE                    (* (reg8 *) Rotation__BIE)
/* Bit-mask for Aliased Register Access */
#define Rotation_BIT_MASK               (* (reg8 *) Rotation__BIT_MASK)
/* Bypass Enable */
#define Rotation_BYP                    (* (reg8 *) Rotation__BYP)
/* Port wide control signals */                                                   
#define Rotation_CTL                    (* (reg8 *) Rotation__CTL)
/* Drive Modes */
#define Rotation_DM0                    (* (reg8 *) Rotation__DM0) 
#define Rotation_DM1                    (* (reg8 *) Rotation__DM1)
#define Rotation_DM2                    (* (reg8 *) Rotation__DM2) 
/* Input Buffer Disable Override */
#define Rotation_INP_DIS                (* (reg8 *) Rotation__INP_DIS)
/* LCD Common or Segment Drive */
#define Rotation_LCD_COM_SEG            (* (reg8 *) Rotation__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rotation_LCD_EN                 (* (reg8 *) Rotation__LCD_EN)
/* Slew Rate Control */
#define Rotation_SLW                    (* (reg8 *) Rotation__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rotation_PRTDSI__CAPS_SEL       (* (reg8 *) Rotation__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rotation_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rotation__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rotation_PRTDSI__OE_SEL0        (* (reg8 *) Rotation__PRTDSI__OE_SEL0) 
#define Rotation_PRTDSI__OE_SEL1        (* (reg8 *) Rotation__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rotation_PRTDSI__OUT_SEL0       (* (reg8 *) Rotation__PRTDSI__OUT_SEL0) 
#define Rotation_PRTDSI__OUT_SEL1       (* (reg8 *) Rotation__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rotation_PRTDSI__SYNC_OUT       (* (reg8 *) Rotation__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rotation__SIO_CFG)
    #define Rotation_SIO_HYST_EN        (* (reg8 *) Rotation__SIO_HYST_EN)
    #define Rotation_SIO_REG_HIFREQ     (* (reg8 *) Rotation__SIO_REG_HIFREQ)
    #define Rotation_SIO_CFG            (* (reg8 *) Rotation__SIO_CFG)
    #define Rotation_SIO_DIFF           (* (reg8 *) Rotation__SIO_DIFF)
#endif /* (Rotation__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rotation__INTSTAT)
    #define Rotation_INTSTAT            (* (reg8 *) Rotation__INTSTAT)
    #define Rotation_SNAP               (* (reg8 *) Rotation__SNAP)
    
	#define Rotation_0_INTTYPE_REG 		(* (reg8 *) Rotation__0__INTTYPE)
#endif /* (Rotation__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rotation_H */


/* [] END OF FILE */
