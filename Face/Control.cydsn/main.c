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
    uint16 compare = angle;
    (*compare_func)(compare);
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    LeftEyebrow_Start();
    for(;;)
    {
        set_servo_angle(LeftEyebrow_WriteCompare1, 0);
        CyDelay(1000);
        set_servo_angle(LeftEyebrow_WriteCompare1, 90);
    }
}

/* [] END OF FILE */
