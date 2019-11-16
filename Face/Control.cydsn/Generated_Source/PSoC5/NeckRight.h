/*******************************************************************************
* File Name: NeckRight.h  
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

#if !defined(CY_PINS_NeckRight_H) /* Pins NeckRight_H */
#define CY_PINS_NeckRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NeckRight_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NeckRight__PORT == 15 && ((NeckRight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    NeckRight_Write(uint8 value);
void    NeckRight_SetDriveMode(uint8 mode);
uint8   NeckRight_ReadDataReg(void);
uint8   NeckRight_Read(void);
void    NeckRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   NeckRight_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the NeckRight_SetDriveMode() function.
     *  @{
     */
        #define NeckRight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define NeckRight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define NeckRight_DM_RES_UP          PIN_DM_RES_UP
        #define NeckRight_DM_RES_DWN         PIN_DM_RES_DWN
        #define NeckRight_DM_OD_LO           PIN_DM_OD_LO
        #define NeckRight_DM_OD_HI           PIN_DM_OD_HI
        #define NeckRight_DM_STRONG          PIN_DM_STRONG
        #define NeckRight_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define NeckRight_MASK               NeckRight__MASK
#define NeckRight_SHIFT              NeckRight__SHIFT
#define NeckRight_WIDTH              1u

/* Interrupt constants */
#if defined(NeckRight__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NeckRight_SetInterruptMode() function.
     *  @{
     */
        #define NeckRight_INTR_NONE      (uint16)(0x0000u)
        #define NeckRight_INTR_RISING    (uint16)(0x0001u)
        #define NeckRight_INTR_FALLING   (uint16)(0x0002u)
        #define NeckRight_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define NeckRight_INTR_MASK      (0x01u) 
#endif /* (NeckRight__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NeckRight_PS                     (* (reg8 *) NeckRight__PS)
/* Data Register */
#define NeckRight_DR                     (* (reg8 *) NeckRight__DR)
/* Port Number */
#define NeckRight_PRT_NUM                (* (reg8 *) NeckRight__PRT) 
/* Connect to Analog Globals */                                                  
#define NeckRight_AG                     (* (reg8 *) NeckRight__AG)                       
/* Analog MUX bux enable */
#define NeckRight_AMUX                   (* (reg8 *) NeckRight__AMUX) 
/* Bidirectional Enable */                                                        
#define NeckRight_BIE                    (* (reg8 *) NeckRight__BIE)
/* Bit-mask for Aliased Register Access */
#define NeckRight_BIT_MASK               (* (reg8 *) NeckRight__BIT_MASK)
/* Bypass Enable */
#define NeckRight_BYP                    (* (reg8 *) NeckRight__BYP)
/* Port wide control signals */                                                   
#define NeckRight_CTL                    (* (reg8 *) NeckRight__CTL)
/* Drive Modes */
#define NeckRight_DM0                    (* (reg8 *) NeckRight__DM0) 
#define NeckRight_DM1                    (* (reg8 *) NeckRight__DM1)
#define NeckRight_DM2                    (* (reg8 *) NeckRight__DM2) 
/* Input Buffer Disable Override */
#define NeckRight_INP_DIS                (* (reg8 *) NeckRight__INP_DIS)
/* LCD Common or Segment Drive */
#define NeckRight_LCD_COM_SEG            (* (reg8 *) NeckRight__LCD_COM_SEG)
/* Enable Segment LCD */
#define NeckRight_LCD_EN                 (* (reg8 *) NeckRight__LCD_EN)
/* Slew Rate Control */
#define NeckRight_SLW                    (* (reg8 *) NeckRight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NeckRight_PRTDSI__CAPS_SEL       (* (reg8 *) NeckRight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NeckRight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NeckRight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NeckRight_PRTDSI__OE_SEL0        (* (reg8 *) NeckRight__PRTDSI__OE_SEL0) 
#define NeckRight_PRTDSI__OE_SEL1        (* (reg8 *) NeckRight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NeckRight_PRTDSI__OUT_SEL0       (* (reg8 *) NeckRight__PRTDSI__OUT_SEL0) 
#define NeckRight_PRTDSI__OUT_SEL1       (* (reg8 *) NeckRight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NeckRight_PRTDSI__SYNC_OUT       (* (reg8 *) NeckRight__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(NeckRight__SIO_CFG)
    #define NeckRight_SIO_HYST_EN        (* (reg8 *) NeckRight__SIO_HYST_EN)
    #define NeckRight_SIO_REG_HIFREQ     (* (reg8 *) NeckRight__SIO_REG_HIFREQ)
    #define NeckRight_SIO_CFG            (* (reg8 *) NeckRight__SIO_CFG)
    #define NeckRight_SIO_DIFF           (* (reg8 *) NeckRight__SIO_DIFF)
#endif /* (NeckRight__SIO_CFG) */

/* Interrupt Registers */
#if defined(NeckRight__INTSTAT)
    #define NeckRight_INTSTAT            (* (reg8 *) NeckRight__INTSTAT)
    #define NeckRight_SNAP               (* (reg8 *) NeckRight__SNAP)
    
	#define NeckRight_0_INTTYPE_REG 		(* (reg8 *) NeckRight__0__INTTYPE)
#endif /* (NeckRight__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NeckRight_H */


/* [] END OF FILE */
