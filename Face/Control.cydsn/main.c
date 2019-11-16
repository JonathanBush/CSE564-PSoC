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
#include "project.h"
#define MOTOR_CENTER 2000
#define MOTOR_LOW 1000
#define MOTOR_HIGH 3000

void set_servo_angle(void (*compare_func)(uint16), uint8 angle);

void set_servo_angle(void (*compare_func)(uint16), uint8 angle) {
    uint16 compare = MOTOR_LOW + (angle *(MOTOR_HIGH - MOTOR_LOW)) * 180;
    (*compare_func)(compare);
}

uint16 angle(uint8 angle_value) {
    return MOTOR_LOW + (angle_value *(MOTOR_HIGH - MOTOR_LOW)) / 180;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    LeftEyebrow_Start();
    for(;;)
    {
        //set_servo_angle(LeftEyebrow_WriteCompare1, 0);
        LeftEyebrow_WriteCompare1(MOTOR_LOW);
        CyDelay(3000);
        //set_servo_angle(LeftEyebrow_WriteCompare1, 90);
        LeftEyebrow_WriteCompare1(MOTOR_HIGH);
        CyDelay(3000);
    }
}

/* [] END OF FILE */
