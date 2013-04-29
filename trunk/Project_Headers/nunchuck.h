/*Source File:  nunchuck.h
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
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

void nunchuk_down();
void nunchuk_up();
void nunchuk_left();
void nunchuk_right();




#endif /* NUNCHUCK_H_ */
