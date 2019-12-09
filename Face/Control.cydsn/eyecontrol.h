/* ========================================
 *
 * Functions controlling the eyes
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

#ifndef EYECONTROL_H
#define EYECONTROL_H
    
typedef enum {
    EYELID_CLOSED,
    EYELID_CENTER,
    EYELID_DOWN,
    EYELID_UP
} eyelid_position;

typedef enum {
    EYEBALL_CENTER,
    EYEBALL_LEFT,
    EYEBALL_RIGHT,
    EYEBALL_UP,
    EYEBALL_DOWN,
    CROSS_EYE
} eyeball_position;

typedef enum {
    EYEBROW_NORMAL,
    EYEBROW_LEFTRAISE,
    EYEBROW_RIGHTRAISE,
    EYEBROW_BOTHRAISE
} eyebrow_position;

void eyelid_set(eyelid_position option);
void eyeball_set(eyeball_position option);
void eyebrow_set(eyebrow_position option);
    
#endif

/* [] END OF FILE */
