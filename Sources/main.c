/*Source File:  main.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "support_common.h" /* include peripheral declarations and more */
#include "global.h"

__declspec(noreturn) void main(){
	
	
	pit_init();
	qspi_init();
	ledm_init();
	int_uninhibit_all();
	game_init();
	
	for(;;) {	   
		write_matrix();
	}
}
