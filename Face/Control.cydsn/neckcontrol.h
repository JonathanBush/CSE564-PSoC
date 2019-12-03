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

/* [] END OF FILE */

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
