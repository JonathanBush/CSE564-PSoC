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
#include "eyecontrol.h"

void eyelid_set(eyelid_position option) {
    switch (option) {
        case EYELID_CLOSED:
            set_smooth_servo_angle(EYELID_CLOSE, 5);
            set_smooth_servo_angle(EYELID_TILT, 60);
            break;
        case EYELID_CENTER:
            set_smooth_servo_angle(EYELID_CLOSE, 80);
            set_smooth_servo_angle(EYELID_TILT, 60);
            break;
        case EYELID_DOWN:
            set_smooth_servo_angle(EYELID_CLOSE, 80);
            set_smooth_servo_angle(EYELID_TILT, 30);
            break;
        case EYELID_UP:
            set_smooth_servo_angle(EYELID_CLOSE, 80);
            set_smooth_servo_angle(EYELID_TILT, 100);
            break;
        default:
            break;
    }
}

void eyeball_set(eyeball_position option) {
    switch (option) {
        case EYEBALL_CENTER:
            set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 20); // Good
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 80); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 90); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 80); // Good
            break;
        case EYEBALL_LEFT:
            set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 0); // Goodish
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 80); // Goodish
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 100); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 170); // Good
            break;
        case EYEBALL_RIGHT:
            set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 110); // Good
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 180); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 90); // Goodish
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 80); // Goodish
            break;
        case EYEBALL_UP:
           set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 0); // Good
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 50);; // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 70); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 30); // Good
            break;
        case EYEBALL_DOWN:
            set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 120);
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 100);
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 130);
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 120);
            break;
        case CROSS_EYE:
            set_smooth_servo_angle(LEFT_EYEBALL_BOTTOM, 110); // Good
            set_smooth_servo_angle(LEFT_EYEBALL_TOP, 180); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_BOTTOM, 90); // Good
            set_smooth_servo_angle(RIGHT_EYEBALL_TOP, 80); // Good
            break;
        default:
            break;
    }
}

void eyebrow_set(eyebrow_position option) {
    switch (option) {
        case EYEBROW_NORMAL:
            set_smooth_servo_angle(LEFT_EYEBROW_LEFT, 90);
            set_smooth_servo_angle(LEFT_EYEBROW_RIGHT, 90);
            set_smooth_servo_angle(RIGHT_EYEBROW_LEFT, 90);
            set_smooth_servo_angle(RIGHT_EYEBROW_RIGHT, 90);
            break;
        case EYEBROW_LEFTRAISE:
            set_smooth_servo_angle(LEFT_EYEBROW_LEFT, 45);
            set_smooth_servo_angle(LEFT_EYEBROW_RIGHT, 135);
            set_smooth_servo_angle(RIGHT_EYEBROW_LEFT, 90);
            set_smooth_servo_angle(RIGHT_EYEBROW_RIGHT, 90);
            break;
        case EYEBROW_RIGHTRAISE:
            set_smooth_servo_angle(LEFT_EYEBROW_LEFT, 90);
            set_smooth_servo_angle(LEFT_EYEBROW_RIGHT, 90);
            set_smooth_servo_angle(RIGHT_EYEBROW_LEFT, 135);
            set_smooth_servo_angle(RIGHT_EYEBROW_RIGHT, 45);
            break;
        case EYEBROW_BOTHRAISE:
            set_smooth_servo_angle(LEFT_EYEBROW_LEFT, 45);
            set_smooth_servo_angle(LEFT_EYEBROW_RIGHT, 135);
            set_smooth_servo_angle(RIGHT_EYEBROW_LEFT, 135);
            set_smooth_servo_angle(RIGHT_EYEBROW_RIGHT, 45);
            break;
    }
}

/* [] END OF FILE */
