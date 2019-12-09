/* ========================================
 *
 * Robotic face controller
 * 
 * Developed for CSE 564
 * Arizona State University
 * 
 * Authors:
 * Jonathan Bush
 * Zachary Monroe
 * Maurice Ajluni
 * Vatricia Edgar
 * Matthew Frautnick
 *
 * Released under the BSE 3-Clause License
 * 2019
 *
 * ========================================
*/

#include "servocontrol.h"
#include "neckcontrol.h"
#include "mouthcontrol.h"
#include "eyecontrol.h"
#include "project.h"

/* time between steps in case of autonatic advancement */
#define STEP_DELAY 1000

/* prototypes for interrupt handlers */
CY_ISR_PROTO(periodic_task);
CY_ISR_PROTO(button_press);

volatile uint8 button_click = 0;    // set on debounced rising edge

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

/* makes the eyes blink x times */
void blink(int x){
	for(int i = 0; i < x; i++){
		eyelid_set(EYELID_CLOSED);
		CyDelay(600);
		eyelid_set(EYELID_CENTER);
		CyDelay(500);
	}
}

/* neutral facial expression, can be called to reset face after other expressions */
void neutral() {
	rotate_set(NECK_ROTATE_CENTER);
	tilt_set(HEAD_TILT_CENTER);
	mouth_set(MOUTH_CLOSE);
	lip_set(LIP_NORMAL);
	eyelid_set(EYELID_CENTER);
	eyeball_set(EYEBALL_CENTER);
	eyebrow_set(EYEBROW_NORMAL);
}

/* sad facial expression */
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

/* surprised facial expression */
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

/* anguished facial expression */
void anguish() {
    neutral();
    tilt_set(HEAD_TILT_BACK);
    mouth_set(MOUTH_AGAPE);
    eyebrow_set(EYEBROW_BOTHRAISE);
    tilt_set(HEAD_TILT_LEFT);
    rotate_set(NECK_ROTATE_LEFT);
    eyeball_set(EYEBALL_CENTER);   
}

/* confused facial expression */
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

/* rolled eyes facial expression */
void eyeroll() {
    neutral();
    mouth_set(MOUTH_CLOSE);
    eyebrow_set(EYEBROW_BOTHRAISE);
    tilt_set(HEAD_TILT_BACK);
    rotate_set(NECK_ROTATE_CENTER);
    eyeball_set(EYEBALL_UP);    
}

/* wait until the button is pressed */
void button_wait() {
    while (!button_click) {
        CyDelay(10);
    }
    button_click = 0;
}

/* wait until the button is pressed or the timeout is reached */
void button_wait_timeout(uint16 milliseconds) {
    while (!button_click && milliseconds) {
        CyDelay(1);
        milliseconds--;
    }
    button_click = 0;   
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    neutral();  // start everything in the neutral position
    
    Timer_Start();  // start the timer that drives the asynchronous servo update loop
    
    timer_isr_StartEx(periodic_task);   // connect the interrupt handlers
    button_isr_StartEx(button_press);
    
    CyDelay(1000);  // give time for the servo positions to update

    start_servos(); // start the PWM generators
    
    button_wait();  // wait until the button is pressed
    
    for(;;)
    {
        // loop through the different expressions, with at button wait between each
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
