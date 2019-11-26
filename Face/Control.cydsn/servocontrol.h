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

#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H
    
#include "project.h"
    
#define MOTOR_LOW (280)
#define MOTOR_HIGH (2200)
#define MOTOR_CENTER (((MOTOR_HIGH + MOTOR_LOW) / 2))
#define DEFAULT_STEP 5
    
typedef struct {
    void (*write_compare)(uint16);
    uint16 current;
    uint16 target;
    uint16 step;
} servo_state;

typedef enum {
    BASE_ROTATE = 0,
    NECK_LEFT,
    NECK_RIGHT,
    JAW,
    LIP_LEFT,
    LIP_RIGHT,
    LEFT_EYEBALL_TOP,
    LEFT_EYEBALL_BOTTOM,
    RIGHT_EYEBALL_TOP,
    RIGHT_EYEBALL_BOTTOM,
    EYELID_TILT,
    EYELID_CLOSE,
    LEFT_EYEBROW_LEFT,
    LEFT_EYEBROW_RIGHT,
    RIGHT_EYEBROW_LEFT,
    RIGHT_EYEBROW_RIGHT,
} servo;

//extern servo_state servo_map[];

void set_smooth_servo_angle(servo servo_id, uint8 angle);
void update_servos();
    
#endif

/* [] END OF FILE */
