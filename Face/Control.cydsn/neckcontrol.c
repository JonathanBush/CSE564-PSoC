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

#include "neckcontrol.h"
#include "servocontrol.h"

void rotate_set(neck_rotation option) {
    switch (option) {
        case NECK_ROTATE_LEFT:
            set_smooth_servo_angle(BASE_ROTATE, 90);
            break;
        case NECK_ROTATE_CENTER:
            set_smooth_servo_angle(BASE_ROTATE, 135);
            break;        
        case NECK_ROTATE_RIGHT:
            set_smooth_servo_angle(BASE_ROTATE, 180);
            break;
        default:
            break;
    }
}

void tilt_set(head_tilt option) {
    switch (option) {
        case HEAD_TILT_RIGHT:
            set_smooth_servo_angle(NECK_LEFT, 140);
            set_smooth_servo_angle(NECK_RIGHT, 120);
            break;
        case HEAD_TILT_CENTER:
            set_smooth_servo_angle(NECK_LEFT, 90);
            set_smooth_servo_angle(NECK_RIGHT, 100);
            break;
        case HEAD_TILT_LEFT:
            set_smooth_servo_angle(NECK_LEFT, 80);
            set_smooth_servo_angle(NECK_RIGHT, 70);
            break;
        case HEAD_TILT_BACK:
            set_smooth_servo_angle(NECK_LEFT, 60);
            set_smooth_servo_angle(NECK_RIGHT, 130);
            break;
        case HEAD_TILT_FORWARD:
            set_smooth_servo_angle(NECK_LEFT, 160);
            set_smooth_servo_angle(NECK_RIGHT, 30);
            break;
        default:
            break;
        
    }
}

/* [] END OF FILE */
