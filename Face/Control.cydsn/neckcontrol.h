/* ========================================
 *
 * Functions controlling the neck
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

#ifndef NECK_H
#define NECK_H

typedef enum {
    NECK_ROTATE_LEFT,
    NECK_ROTATE_CENTER,
    NECK_ROTATE_RIGHT
} neck_rotation;

typedef enum {
    HEAD_TILT_LEFT,
    HEAD_TILT_CENTER,
    HEAD_TILT_RIGHT,
    HEAD_TILT_BACK,
    HEAD_TILT_FORWARD
} head_tilt;
    
void rotate_set(neck_rotation option);
void tilt_set(head_tilt option);
    
#endif

/* [] END OF FILE */