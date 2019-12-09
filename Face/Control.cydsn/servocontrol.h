/* ========================================
 *
 * Functions smooth servo control
 * 
 * Developed for CSE 564
 * Arizona State University
 * 
 * Authors:
 * Jonathan Bush
 * Zachary Monroe
 *
 * Released under the BSE 3-Clause License
 * 2019
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
    

/* identifiers for each servo */
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

/* move the specified servo smoothly to the angle in 0-180 */
void set_smooth_servo_angle(servo servo_id, uint8 angle);

/* update the servos, moving each one step closer to the target */
void update_servos();

/* start the PWM components for all servos */
void start_servos();
    
#endif

/* [] END OF FILE */
