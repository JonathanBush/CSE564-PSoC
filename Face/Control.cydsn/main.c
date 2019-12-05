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
#include "neckcontrol.h"
#include "mouthcontrol.h"
#include "eyecontrol.h"
#include "project.h"


#define STEP_DELAY 400000


CY_ISR_PROTO(periodic_task);


/* called at 200 Hz */
CY_ISR(periodic_task) {
    Timer_ReadStatusRegister();
    update_servos();
}

/* facial expressions */

void neutral() {
	rotate_set(NECK_ROTATE_CENTER);
	tilt_set(HEAD_TILT_CENTER);
	mouth_set(MOUTH_CLOSE);
	lip_set(LIP_NORMAL);
	eyelid_set(EYELID_CENTER);
	eyeball_set(EYEBALL_CENTER);
	eyebrow_set(EYEBROW_NORMAL);
}

void sad() {
  neutral();
  eyebrow_set(EYEBROW_BOTHRAISE);
  mouth_set(MOUTH_CLOSE);
  lip_set(LIP_BOTH_DOWN);
  eyelid_set(EYELID_CENTER);
  eyeball_set(EYEBALL_CENTER);
  tilt_set(HEAD_TILT_FORWARD);
  rotate_set(NECK_ROTATE_CENTER);
}

void anguish() {
    neutral();
	rotate_set(NECK_ROTATE_CENTER);
	tilt_set(HEAD_TILT_BACK);
	mouth_set(MOUTH_OPEN);
	lip_set(LIP_NORMAL);
	eyelid_set(EYELID_CENTER);
	eyeball_set(EYEBALL_CENTER);
	eyebrow_set(EYEBROW_BOTHRAISE);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    LeftEyebrow_Start();
    RightEyebrow_Start();
    RightEyeball_Start();
    LeftEyeball_Start();
    Eyelids_Start();
    Lips_Start();
    Base_Start();
    Neck_Start();
    
    Timer_Start();
    
    timer_isr_StartEx(periodic_task);

    neutral();
    
    for(;;)
    {
//        eyelid_set(EYELID_CENTER);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_CLOSED);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_UP);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_DOWN);
//        CyDelay(STEP_DELAY);
        
        
//        neutral();
//        CyDelay(STEP_DELAY);
//        sad();
//        CyDelay(STEP_DELAY);
//        anguish();
//        CyDelay(STEP_DELAY);
//        tilt_set(HEAD_TILT_BACK);
//        CyDelay(STEP_DELAY);
//        tilt_set(HEAD_TILT_CENTER);
//        CyDelay(STEP_DELAY);
//        tilt_set(HEAD_TILT_FORWARD);
//        CyDelay(STEP_DELAY);
//        tilt_set(HEAD_TILT_LEFT);
//        CyDelay(STEP_DELAY);
//        tilt_set(HEAD_TILT_RIGHT);
//        CyDelay(STEP_DELAY);
//        rotate_set(NECK_ROTATE_LEFT);
//        CyDelay(STEP_DELAY);
//        rotate_set(NECK_ROTATE_CENTER);
//        CyDelay(STEP_DELAY);
//        rotate_set(NECK_ROTATE_RIGHT);
//        CyDelay(STEP_DELAY);
//        mouth_set(MOUTH_CLOSE);
//        CyDelay(STEP_DELAY);
//        mouth_set(MOUTH_OPEN);
//        CyDelay(STEP_DELAY);
//        lip_set(LIP_NORMAL);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_CLOSED);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_CENTER);
//        CyDelay(STEP_DELAY);
//        eyelid_set(EYELID_DOWN);
//        CyDelay(STEP_DELAY);
//        eyeball_set(EYEBALL_CENTER);
//        CyDelay(STEP_DELAY);
//        eyebrow_set(EYEBROW_NORMAL);
//        CyDelay(STEP_DELAY);
//        eyebrow_set(EYEBROW_LEFTRAISE);
//        CyDelay(STEP_DELAY);
//        eyebrow_set(EYEBROW_RIGHTRAISE);
//        CyDelay(STEP_DELAY);
//        eyebrow_set(EYEBROW_BOTHRAISE);
//        CyDelay(STEP_DELAY);

    }
}

/* [] END OF FILE */
