/* ========================================
 *
 * Functions controlling the mouth
 * 
 * Developed for CSE 564
 * Arizona State University
 * 
 * Authors:
 * Jonathan Bush
 * Zachary Monroe
 * Maurice Ajluni
 *
 * Released under the BSE 3-Clause License
 * 2019
 *
 * ========================================
*/

#ifndef MOUTH_H
#define MOUTH_H
    
typedef enum {
    MOUTH_OPEN,
    MOUTH_CLOSE,
    MOUTH_AGAPE
} mouth_position;

typedef enum {
    LIP_NORMAL,
    LIP_LEFT_SMIRK,
    LIP_RIGHT_SMIRK,
    LIP_FROWN,
    LIP_SMILE,
} lip_position;

void mouth_set(mouth_position option);
void lip_set(lip_position option);
    
#endif

/* [] END OF FILE */
