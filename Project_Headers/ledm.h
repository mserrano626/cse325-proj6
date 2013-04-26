/*
 * ledm.h
 *
 *  Created on: Apr 19, 2013
 *      Author: maserra3
 */

#ifndef LEDM_H_
#define LEDM_H_

extern void ledm_init();
extern void write_matrix(int pattern[8][8]);
extern void update_matrix();
extern void ledm_refresh();

#endif /* LEDM_H_ */
