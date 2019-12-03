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

#include "mouthcontrol.h"
#include "servocontrol.h"

void mouth_set(mouth_position option) {
    switch (option) {
        case MOUTH_OPEN:
            set_smooth_servo_angle(JAW, 90);
            break;
        case MOUTH_CLOSE:
            set_smooth_servo_angle(JAW, 130);
            break;
        default:
            break;
    }
}

void lip_set(lip_position option) {
    switch (option) {
        case LIP_NORMAL:
            set_smooth_servo_angle(LIP_LEFT, 80);
            set_smooth_servo_angle(LIP_RIGHT, 90);
            break;
        case LIP_LEFT_SMIRK:
            set_smooth_servo_angle(LIP_LEFT, 60);
            set_smooth_servo_angle(LIP_RIGHT, 90);
            break;
        case LIP_RIGHT_SMIRK:
            set_smooth_servo_angle(LIP_LEFT, 80);
            set_smooth_servo_angle(LIP_RIGHT, 120);
            break;
        default:
            break;
    }
}

/* [] END OF FILE */
