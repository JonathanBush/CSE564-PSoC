/*******************************************************************************
* File Name: NeckLeft.h  
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

#if !defined(CY_PINS_NeckLeft_H) /* Pins NeckLeft_H */
#define CY_PINS_NeckLeft_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NeckLeft_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NeckLeft__PORT == 15 && ((NeckLeft__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    NeckLeft_Write(uint8 value);
void    NeckLeft_SetDriveMode(uint8 mode);
uint8   NeckLeft_ReadDataReg(void);
uint8   NeckLeft_Read(void);
void    NeckLeft_SetInterruptMode(uint16 position, uint16 mode);
uint8   NeckLeft_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the NeckLeft_SetDriveMode() function.
     *  @{
     */
        #define NeckLeft_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define NeckLeft_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define NeckLeft_DM_RES_UP          PIN_DM_RES_UP
        #define NeckLeft_DM_RES_DWN         PIN_DM_RES_DWN
        #define NeckLeft_DM_OD_LO           PIN_DM_OD_LO
        #define NeckLeft_DM_OD_HI           PIN_DM_OD_HI
        #define NeckLeft_DM_STRONG          PIN_DM_STRONG
        #define NeckLeft_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define NeckLeft_MASK               NeckLeft__MASK
#define NeckLeft_SHIFT              NeckLeft__SHIFT
#define NeckLeft_WIDTH              1u

/* Interrupt constants */
#if defined(NeckLeft__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NeckLeft_SetInterruptMode() function.
     *  @{
     */
        #define NeckLeft_INTR_NONE      (uint16)(0x0000u)
        #define NeckLeft_INTR_RISING    (uint16)(0x0001u)
        #define NeckLeft_INTR_FALLING   (uint16)(0x0002u)
        #define NeckLeft_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define NeckLeft_INTR_MASK      (0x01u) 
#endif /* (NeckLeft__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NeckLeft_PS                     (* (reg8 *) NeckLeft__PS)
/* Data Register */
#define NeckLeft_DR                     (* (reg8 *) NeckLeft__DR)
/* Port Number */
#define NeckLeft_PRT_NUM                (* (reg8 *) NeckLeft__PRT) 
/* Connect to Analog Globals */                                                  
#define NeckLeft_AG                     (* (reg8 *) NeckLeft__AG)                       
/* Analog MUX bux enable */
#define NeckLeft_AMUX                   (* (reg8 *) NeckLeft__AMUX) 
/* Bidirectional Enable */                                                        
#define NeckLeft_BIE                    (* (reg8 *) NeckLeft__BIE)
/* Bit-mask for Aliased Register Access */
#define NeckLeft_BIT_MASK               (* (reg8 *) NeckLeft__BIT_MASK)
/* Bypass Enable */
#define NeckLeft_BYP                    (* (reg8 *) NeckLeft__BYP)
/* Port wide control signals */                                                   
#define NeckLeft_CTL                    (* (reg8 *) NeckLeft__CTL)
/* Drive Modes */
#define NeckLeft_DM0                    (* (reg8 *) NeckLeft__DM0) 
#define NeckLeft_DM1                    (* (reg8 *) NeckLeft__DM1)
#define NeckLeft_DM2                    (* (reg8 *) NeckLeft__DM2) 
/* Input Buffer Disable Override */
#define NeckLeft_INP_DIS                (* (reg8 *) NeckLeft__INP_DIS)
/* LCD Common or Segment Drive */
#define NeckLeft_LCD_COM_SEG            (* (reg8 *) NeckLeft__LCD_COM_SEG)
/* Enable Segment LCD */
#define NeckLeft_LCD_EN                 (* (reg8 *) NeckLeft__LCD_EN)
/* Slew Rate Control */
#define NeckLeft_SLW                    (* (reg8 *) NeckLeft__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NeckLeft_PRTDSI__CAPS_SEL       (* (reg8 *) NeckLeft__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NeckLeft_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NeckLeft__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NeckLeft_PRTDSI__OE_SEL0        (* (reg8 *) NeckLeft__PRTDSI__OE_SEL0) 
#define NeckLeft_PRTDSI__OE_SEL1        (* (reg8 *) NeckLeft__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NeckLeft_PRTDSI__OUT_SEL0       (* (reg8 *) NeckLeft__PRTDSI__OUT_SEL0) 
#define NeckLeft_PRTDSI__OUT_SEL1       (* (reg8 *) NeckLeft__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NeckLeft_PRTDSI__SYNC_OUT       (* (reg8 *) NeckLeft__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(NeckLeft__SIO_CFG)
    #define NeckLeft_SIO_HYST_EN        (* (reg8 *) NeckLeft__SIO_HYST_EN)
    #define NeckLeft_SIO_REG_HIFREQ     (* (reg8 *) NeckLeft__SIO_REG_HIFREQ)
    #define NeckLeft_SIO_CFG            (* (reg8 *) NeckLeft__SIO_CFG)
    #define NeckLeft_SIO_DIFF           (* (reg8 *) NeckLeft__SIO_DIFF)
#endif /* (NeckLeft__SIO_CFG) */

/* Interrupt Registers */
#if defined(NeckLeft__INTSTAT)
    #define NeckLeft_INTSTAT            (* (reg8 *) NeckLeft__INTSTAT)
    #define NeckLeft_SNAP               (* (reg8 *) NeckLeft__SNAP)
    
	#define NeckLeft_0_INTTYPE_REG 		(* (reg8 *) NeckLeft__0__INTTYPE)
#endif /* (NeckLeft__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NeckLeft_H */


/* [] END OF FILE */
