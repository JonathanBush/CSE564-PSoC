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


#define STEP_DELAY 1000


CY_ISR_PROTO(periodic_task);
CY_ISR_PROTO(button_press);

volatile uint8 button_click = 0;


/* called at 200 Hz */
CY_ISR(periodic_task) {
    Timer_ReadStatusRegister();
    update_servos();
}

CY_ISR(button_press) {
    button_click = 1;
    button_isr_ClearPending();
}

/* facial expressions */

void blink(int x){
	for(int i = 0; i < x; i++){
		eyelid_set(EYELID_CLOSED);
		CyDelay(600);
		eyelid_set(EYELID_CENTER);
		CyDelay(500);
	}
}

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
  eyebrow_set(EYEBROW_NORMAL);
  mouth_set(MOUTH_CLOSE);
  lip_set(LIP_FROWN);
  eyelid_set(EYELID_CLOSED);
  eyeball_set(EYEBALL_CENTER);
  tilt_set(HEAD_TILT_FORWARD);
  rotate_set(NECK_ROTATE_CENTER);
}

void surprised() {
    neutral();
	rotate_set(NECK_ROTATE_CENTER);
	tilt_set(HEAD_TILT_BACK);
	mouth_set(MOUTH_OPEN);
	lip_set(LIP_NORMAL);
	eyelid_set(EYELID_CENTER);
	eyeball_set(EYEBALL_CENTER);
	eyebrow_set(EYEBROW_BOTHRAISE);
}

void anguish() {
    neutral();
    tilt_set(HEAD_TILT_BACK);
    mouth_set(MOUTH_AGAPE);
    eyebrow_set(EYEBROW_BOTHRAISE);
    tilt_set(HEAD_TILT_LEFT);
    rotate_set(NECK_ROTATE_LEFT);
    eyeball_set(EYEBALL_CENTER);   
}

void confused() {
    neutral();
    eyebrow_set(EYEBROW_LEFTRAISE);
    eyeball_set(EYEBALL_UP);
    lip_set(LIP_LEFT_SMIRK);
    rotate_set(NECK_ROTATE_LEFT);
    tilt_set(HEAD_TILT_RIGHT);
    blink(4);
    eyelid_set(EYELID_UP);
}

void eyeroll() {
    // eyeroll
    neutral();
    mouth_set(MOUTH_CLOSE);
    eyebrow_set(EYEBROW_BOTHRAISE);
    tilt_set(HEAD_TILT_BACK);
    rotate_set(NECK_ROTATE_CENTER);
    eyeball_set(EYEBALL_UP);    
}

void button_wait() {
    while (!button_click) {
        CyDelay(10);
    }
    button_click = 0;
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    neutral();  // start everything in the neutral position
    
    Timer_Start();  // start the timer that drives the asynchronous servo update loop
    
    timer_isr_StartEx(periodic_task);   // connect the interrupt handlers
    button_isr_StartEx(button_press);
    
    CyDelay(1000);

    LeftEyebrow_Start();
    RightEyebrow_Start();
    RightEyeball_Start();
    LeftEyeball_Start();
    Eyelids_Start();
    Lips_Start();
    Base_Start();
    Neck_Start();
    button_wait();
    for(;;)
    {
        confused();
        button_wait();
        anguish();
        button_wait();
        sad();
        button_wait();
        surprised();
        button_wait();
        eyeroll();
        button_wait();
        neutral();
        button_wait();

    }
}

/* [] END OF FILE */
