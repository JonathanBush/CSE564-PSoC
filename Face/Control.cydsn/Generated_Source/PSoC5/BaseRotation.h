/*******************************************************************************
* File Name: BaseRotation.h  
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

#if !defined(CY_PINS_BaseRotation_H) /* Pins BaseRotation_H */
#define CY_PINS_BaseRotation_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BaseRotation_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BaseRotation__PORT == 15 && ((BaseRotation__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BaseRotation_Write(uint8 value);
void    BaseRotation_SetDriveMode(uint8 mode);
uint8   BaseRotation_ReadDataReg(void);
uint8   BaseRotation_Read(void);
void    BaseRotation_SetInterruptMode(uint16 position, uint16 mode);
uint8   BaseRotation_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BaseRotation_SetDriveMode() function.
     *  @{
     */
        #define BaseRotation_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BaseRotation_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BaseRotation_DM_RES_UP          PIN_DM_RES_UP
        #define BaseRotation_DM_RES_DWN         PIN_DM_RES_DWN
        #define BaseRotation_DM_OD_LO           PIN_DM_OD_LO
        #define BaseRotation_DM_OD_HI           PIN_DM_OD_HI
        #define BaseRotation_DM_STRONG          PIN_DM_STRONG
        #define BaseRotation_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BaseRotation_MASK               BaseRotation__MASK
#define BaseRotation_SHIFT              BaseRotation__SHIFT
#define BaseRotation_WIDTH              1u

/* Interrupt constants */
#if defined(BaseRotation__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BaseRotation_SetInterruptMode() function.
     *  @{
     */
        #define BaseRotation_INTR_NONE      (uint16)(0x0000u)
        #define BaseRotation_INTR_RISING    (uint16)(0x0001u)
        #define BaseRotation_INTR_FALLING   (uint16)(0x0002u)
        #define BaseRotation_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BaseRotation_INTR_MASK      (0x01u) 
#endif /* (BaseRotation__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BaseRotation_PS                     (* (reg8 *) BaseRotation__PS)
/* Data Register */
#define BaseRotation_DR                     (* (reg8 *) BaseRotation__DR)
/* Port Number */
#define BaseRotation_PRT_NUM                (* (reg8 *) BaseRotation__PRT) 
/* Connect to Analog Globals */                                                  
#define BaseRotation_AG                     (* (reg8 *) BaseRotation__AG)                       
/* Analog MUX bux enable */
#define BaseRotation_AMUX                   (* (reg8 *) BaseRotation__AMUX) 
/* Bidirectional Enable */                                                        
#define BaseRotation_BIE                    (* (reg8 *) BaseRotation__BIE)
/* Bit-mask for Aliased Register Access */
#define BaseRotation_BIT_MASK               (* (reg8 *) BaseRotation__BIT_MASK)
/* Bypass Enable */
#define BaseRotation_BYP                    (* (reg8 *) BaseRotation__BYP)
/* Port wide control signals */                                                   
#define BaseRotation_CTL                    (* (reg8 *) BaseRotation__CTL)
/* Drive Modes */
#define BaseRotation_DM0                    (* (reg8 *) BaseRotation__DM0) 
#define BaseRotation_DM1                    (* (reg8 *) BaseRotation__DM1)
#define BaseRotation_DM2                    (* (reg8 *) BaseRotation__DM2) 
/* Input Buffer Disable Override */
#define BaseRotation_INP_DIS                (* (reg8 *) BaseRotation__INP_DIS)
/* LCD Common or Segment Drive */
#define BaseRotation_LCD_COM_SEG            (* (reg8 *) BaseRotation__LCD_COM_SEG)
/* Enable Segment LCD */
#define BaseRotation_LCD_EN                 (* (reg8 *) BaseRotation__LCD_EN)
/* Slew Rate Control */
#define BaseRotation_SLW                    (* (reg8 *) BaseRotation__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BaseRotation_PRTDSI__CAPS_SEL       (* (reg8 *) BaseRotation__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BaseRotation_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BaseRotation__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BaseRotation_PRTDSI__OE_SEL0        (* (reg8 *) BaseRotation__PRTDSI__OE_SEL0) 
#define BaseRotation_PRTDSI__OE_SEL1        (* (reg8 *) BaseRotation__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BaseRotation_PRTDSI__OUT_SEL0       (* (reg8 *) BaseRotation__PRTDSI__OUT_SEL0) 
#define BaseRotation_PRTDSI__OUT_SEL1       (* (reg8 *) BaseRotation__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BaseRotation_PRTDSI__SYNC_OUT       (* (reg8 *) BaseRotation__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BaseRotation__SIO_CFG)
    #define BaseRotation_SIO_HYST_EN        (* (reg8 *) BaseRotation__SIO_HYST_EN)
    #define BaseRotation_SIO_REG_HIFREQ     (* (reg8 *) BaseRotation__SIO_REG_HIFREQ)
    #define BaseRotation_SIO_CFG            (* (reg8 *) BaseRotation__SIO_CFG)
    #define BaseRotation_SIO_DIFF           (* (reg8 *) BaseRotation__SIO_DIFF)
#endif /* (BaseRotation__SIO_CFG) */

/* Interrupt Registers */
#if defined(BaseRotation__INTSTAT)
    #define BaseRotation_INTSTAT            (* (reg8 *) BaseRotation__INTSTAT)
    #define BaseRotation_SNAP               (* (reg8 *) BaseRotation__SNAP)
    
	#define BaseRotation_0_INTTYPE_REG 		(* (reg8 *) BaseRotation__0__INTTYPE)
#endif /* (BaseRotation__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BaseRotation_H */


/* [] END OF FILE */
