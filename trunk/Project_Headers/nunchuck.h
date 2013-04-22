/*
 * nunchuck.h
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */

#ifndef NUNCHUCK_H_
#define NUNCHUCK_H_

#include "global.h"

extern void fst_nunchuk_init();
void fst_nunchuk_on_button_c (void (*)(void));
void fst_nunchuk_on_button_z (void (*)(void));
void fst_nunchuk_on_stick_down (void (*)(void));
void fst_nunchuk_on_stick_left (void (*)(void));
void fst_nunchuk_on_stick_right (void (*)(void));
void fst_nunchuk_on_stick_up (void (*)(void));
extern void fst_nunchuk_read ();
extern void fst_nunchuk_reset();
extern void fst_nunchuk_xmit_cmd (unsigned char, unsigned char);

static  void (*g_callback_button_c)(void);
static  void (*g_callback_button_z)(void);
static  void (*g_callback_stick_down)(void);
static  void (*g_callback_stick_left)(void);
static  void (*g_callback_stick_right)(void);
static  void (*g_callback_stick_up)(void);




#endif /* NUNCHUCK_H_ */
