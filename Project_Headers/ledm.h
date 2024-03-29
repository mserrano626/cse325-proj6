/*Source File:  ledm.h
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */


#ifndef LEDM_H_
#define LEDM_H_

extern void ledm_init();
extern void write_matrix(int pattern[8][8]);
extern void update_matrix();
extern void ledm_refresh();

#endif /* LEDM_H_ */
