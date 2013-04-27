/*
 * pwm.h
 *
 *  Created on: Apr 26, 2013
 *      Author: maserra3
 */

#ifndef PWM_H_
#define PWM_H_

#include "support_common.h"

extern void init_pwm();
extern void set_pitch(int, int, int, int);
extern void note(int p_note);
#endif /* PWM_H_ */
