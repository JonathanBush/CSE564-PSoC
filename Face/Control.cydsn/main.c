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

void set_servo_angle(void (*compare_func)(uint16), uint8 angle);

void set_servo_angle(void (*compare_func)(uint16), uint8 angle) {
    uint16 compare = angle;
    (*compare_func)(compare);
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
