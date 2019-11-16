/*******************************************************************************
* File Name: TopLip.h  
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

#if !defined(CY_PINS_TopLip_H) /* Pins TopLip_H */
#define CY_PINS_TopLip_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TopLip_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TopLip__PORT == 15 && ((TopLip__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TopLip_Write(uint8 value);
void    TopLip_SetDriveMode(uint8 mode);
uint8   TopLip_ReadDataReg(void);
uint8   TopLip_Read(void);
void    TopLip_SetInterruptMode(uint16 position, uint16 mode);
uint8   TopLip_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TopLip_SetDriveMode() function.
     *  @{
     */
        #define TopLip_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TopLip_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TopLip_DM_RES_UP          PIN_DM_RES_UP
        #define TopLip_DM_RES_DWN         PIN_DM_RES_DWN
        #define TopLip_DM_OD_LO           PIN_DM_OD_LO
        #define TopLip_DM_OD_HI           PIN_DM_OD_HI
        #define TopLip_DM_STRONG          PIN_DM_STRONG
        #define TopLip_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TopLip_MASK               TopLip__MASK
#define TopLip_SHIFT              TopLip__SHIFT
#define TopLip_WIDTH              1u

/* Interrupt constants */
#if defined(TopLip__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TopLip_SetInterruptMode() function.
     *  @{
     */
        #define TopLip_INTR_NONE      (uint16)(0x0000u)
        #define TopLip_INTR_RISING    (uint16)(0x0001u)
        #define TopLip_INTR_FALLING   (uint16)(0x0002u)
        #define TopLip_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TopLip_INTR_MASK      (0x01u) 
#endif /* (TopLip__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TopLip_PS                     (* (reg8 *) TopLip__PS)
/* Data Register */
#define TopLip_DR                     (* (reg8 *) TopLip__DR)
/* Port Number */
#define TopLip_PRT_NUM                (* (reg8 *) TopLip__PRT) 
/* Connect to Analog Globals */                                                  
#define TopLip_AG                     (* (reg8 *) TopLip__AG)                       
/* Analog MUX bux enable */
#define TopLip_AMUX                   (* (reg8 *) TopLip__AMUX) 
/* Bidirectional Enable */                                                        
#define TopLip_BIE                    (* (reg8 *) TopLip__BIE)
/* Bit-mask for Aliased Register Access */
#define TopLip_BIT_MASK               (* (reg8 *) TopLip__BIT_MASK)
/* Bypass Enable */
#define TopLip_BYP                    (* (reg8 *) TopLip__BYP)
/* Port wide control signals */                                                   
#define TopLip_CTL                    (* (reg8 *) TopLip__CTL)
/* Drive Modes */
#define TopLip_DM0                    (* (reg8 *) TopLip__DM0) 
#define TopLip_DM1                    (* (reg8 *) TopLip__DM1)
#define TopLip_DM2                    (* (reg8 *) TopLip__DM2) 
/* Input Buffer Disable Override */
#define TopLip_INP_DIS                (* (reg8 *) TopLip__INP_DIS)
/* LCD Common or Segment Drive */
#define TopLip_LCD_COM_SEG            (* (reg8 *) TopLip__LCD_COM_SEG)
/* Enable Segment LCD */
#define TopLip_LCD_EN                 (* (reg8 *) TopLip__LCD_EN)
/* Slew Rate Control */
#define TopLip_SLW                    (* (reg8 *) TopLip__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TopLip_PRTDSI__CAPS_SEL       (* (reg8 *) TopLip__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TopLip_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TopLip__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TopLip_PRTDSI__OE_SEL0        (* (reg8 *) TopLip__PRTDSI__OE_SEL0) 
#define TopLip_PRTDSI__OE_SEL1        (* (reg8 *) TopLip__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TopLip_PRTDSI__OUT_SEL0       (* (reg8 *) TopLip__PRTDSI__OUT_SEL0) 
#define TopLip_PRTDSI__OUT_SEL1       (* (reg8 *) TopLip__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TopLip_PRTDSI__SYNC_OUT       (* (reg8 *) TopLip__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TopLip__SIO_CFG)
    #define TopLip_SIO_HYST_EN        (* (reg8 *) TopLip__SIO_HYST_EN)
    #define TopLip_SIO_REG_HIFREQ     (* (reg8 *) TopLip__SIO_REG_HIFREQ)
    #define TopLip_SIO_CFG            (* (reg8 *) TopLip__SIO_CFG)
    #define TopLip_SIO_DIFF           (* (reg8 *) TopLip__SIO_DIFF)
#endif /* (TopLip__SIO_CFG) */

/* Interrupt Registers */
#if defined(TopLip__INTSTAT)
    #define TopLip_INTSTAT            (* (reg8 *) TopLip__INTSTAT)
    #define TopLip_SNAP               (* (reg8 *) TopLip__SNAP)
    
	#define TopLip_0_INTTYPE_REG 		(* (reg8 *) TopLip__0__INTTYPE)
#endif /* (TopLip__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TopLip_H */


/* [] END OF FILE */
