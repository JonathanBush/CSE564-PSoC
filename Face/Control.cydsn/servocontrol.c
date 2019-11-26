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

#include "servocontrol.h"

servo_state servo_map[] = {
    {.write_compare = Base_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Neck_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Neck_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Base_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Lips_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Lips_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyeball_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyeball_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyeball_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyeball_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Eyelids_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = Eyelids_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyebrow_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = LeftEyebrow_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyebrow_WriteCompare1, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP},
    {.write_compare = RightEyebrow_WriteCompare2, .current = MOTOR_CENTER, .target = MOTOR_CENTER, .step = DEFAULT_STEP}    
};


uint16 angle_to_compare(uint16 angle_value) {
    return MOTOR_LOW + (angle_value * (MOTOR_HIGH - MOTOR_LOW)) / 180;
}

//void set_servo_angle(void (*compare_func)(uint16), uint8 angle) {
//    uint16 compare = MOTOR_LOW + (angle *(MOTOR_HIGH - MOTOR_LOW)) * 180;
//    (*compare_func)(compare);
//}

void set_smooth_servo_angle(servo servo_id, uint8 angle) {
    servo_map[(uint8)servo_id].target = angle_to_compare(angle);
}


void update_servos() {
    servo_state *serv;
    
    for (uint8 i = 0; i < 16; ++i) {
        serv = &servo_map[i];
        if (serv->current < serv->target && serv->current + serv->step < serv->target) {
            serv->current += serv->step;
        } else if (serv->current > serv->target && serv->current - serv->step > serv->target) {
            serv->current -= serv->step;
        } else {
            serv->current = serv->target;
        }
        //Neck_WriteCompare1(serv->current);
        (*serv->write_compare)(serv->current);
    }
}

/* [] END OF FILE */
