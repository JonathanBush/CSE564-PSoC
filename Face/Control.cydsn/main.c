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
#include "servocontrol.h"


CY_ISR_PROTO(periodic_task);


/* called at 200 Hz */
CY_ISR(periodic_task) {
    Timer_ReadStatusRegister();
    update_servos();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    LeftEyebrow_Start();
    RightEyebrow_Start();
    RightEyeball_Start();
    //LeftEyeball_Start();
    
    Neck_Start();
    
    set_smooth_servo_angle(NECK_LEFT, 160);
    set_smooth_servo_angle(NECK_RIGHT, 30);
    set_smooth_servo_angle(LEFT_EYEBROW_RIGHT, 90);
    
    Timer_Start();
    
    timer_isr_StartEx(periodic_task);
    for(;;)
    {
        //set_servo_angle(LeftEyebrow_WriteCompare1, 0);
        
        //update_servos();
//        LeftEyebrow_WriteCompare1(MOTOR_CENTER);
//        LeftEyebrow_WriteCompare2(MOTOR_CENTER);
//        RightEyebrow_WriteCompare1(MOTOR_CENTER);
//        RightEyebrow_WriteCompare2(MOTOR_CENTER);
//        
//        RightEyeball_WriteCompare1(MOTOR_CENTER);
//        RightEyeball_WriteCompare2(MOTOR_CENTER);
//        LeftEyeball_WriteCompare1(MOTOR_CENTER);
//        LeftEyeball_WriteCompare2(MOTOR_CENTER);
//        
//        Neck_WriteCompare1(MOTOR_CENTER);
//        Neck_WriteCompare2(MOTOR_CENTER);
        
        //set_servo_angle(LeftEyebrow_WriteCompare1, 90);
        //LeftEyebrow_WriteCompare1(MOTOR_HIGH);
        //LeftEyebrow_WriteCompare2(MOTOR_HIGH);
        
        //Neck_WriteCompare1(MOTOR_HIGH);
        //Neck_WriteCompare2(MOTOR_HIGH);
        
        CyDelay(10);
    }
}

/* [] END OF FILE */
