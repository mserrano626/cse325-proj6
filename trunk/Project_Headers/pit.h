/*Source File:  pit.h
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */


#ifndef PIT_H_
#define PIT_H_

extern void pit0_init();
extern void pit1_init();
extern void pit0_enable();
extern void pit1_enable();
extern void pit0_off();
extern void pit1_off();

#endif /* PIT_H_ */
