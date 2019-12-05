/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef MOUTH_H
#define MOUTH_H
    
typedef enum {
    MOUTH_OPEN,
    MOUTH_CLOSE
} mouth_position;

typedef enum {
    LIP_NORMAL,
    LIP_LEFT_SMIRK,
    LIP_RIGHT_SMIRK,
    LIP_BOTH_DOWN
} lip_position;

void mouth_set(mouth_position option);
void lip_set(lip_position option);
    
#endif

/* [] END OF FILE */
