/* ========================================
 *
 * Function definitions for smooth servo control
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

#include "servocontrol.h"

typedef struct {
    void (*write_compare)(uint16);
    uint16 current;
    uint16 target;
    uint16 step;
} servo_state;

/* this maps each servo defined in the servo struct to its respective compare function and settings */
servo_state servo_map[] = {
    {.write_compare = Base_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = (DEFAULT_STEP - 2)},
    {.write_compare = Neck_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Neck_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Base_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = (DEFAULT_STEP + 2)},
    {.write_compare = Lips_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Lips_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyeball_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyeball_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyeball_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyeball_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Eyelids_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Eyelids_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = (DEFAULT_STEP + 5)},
    {.write_compare = LeftEyebrow_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyebrow_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyebrow_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyebrow_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP}    
};


uint16 angle_to_compare(uint16 angle_value) {
    return MOTOR_LOW + (angle_value * (MOTOR_HIGH - MOTOR_LOW)) / 180;
}

void set_smooth_servo_angle(servo servo_id, uint8 angle) {
    servo_map[(uint8)servo_id].target = angle_to_compare(angle);
}

void update_servos() {
    servo_state *serv;
    
    for (uint8 i = 0; i < 16; ++i) {
        serv = &servo_map[i];
        if (serv->current + serv->step < serv->target) {
            serv->current += serv->step;
        } else if (serv->current - serv->step > serv->target) {
            serv->current -= serv->step;
        } else {
            serv->current = serv->target;
        }
        (*serv->write_compare)(serv->current);
    }
}

void start_servos() {
    LeftEyebrow_Start();
    RightEyebrow_Start();
    RightEyeball_Start();
    LeftEyeball_Start();
    Eyelids_Start();
    Lips_Start();
    Base_Start();
    Neck_Start();
}

/* [] END OF FILE */
