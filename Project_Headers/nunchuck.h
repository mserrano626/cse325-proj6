/*
 * nunchuck.h
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */

#ifndef NUNCHUCK_H_
#define NUNCHUCK_H_

#include "global.h"

#define up 0
#define down 1
#define left 2
#define right 3
#define stop 4

extern void fst_nunchuk_init();

extern void fst_nunchuk_read ();
extern void fst_nunchuk_reset();
extern void fst_nunchuk_xmit_cmd (int, int);

/*
static  void (*g_callback_button_c)(void);
static  void (*g_callback_button_z)(void);
static  void (*g_callback_stick_down)(void);
static  void (*g_callback_stick_left)(void);
static  void (*g_callback_stick_right)(void);
static  void (*g_callback_stick_up)(void);
*/



void nunchuk_down();
void nunchuk_up();
void nunchuk_left();
void nunchuk_right();




#endif /* NUNCHUCK_H_ */
