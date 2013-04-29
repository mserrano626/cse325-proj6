/*Source File:  dtim.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "global.h"

void dtim0_init(){
	
	MCF_DTIM0_DTMR = 0x0F0B;
	
    
}

void dtim1_init(){
	MCF_DTIM1_DTMR = 0x0F0B;
}

void dtim3_init(){
	MCF_DTIM3_DTMR = 0x0F0B;
	
}

void dtim0_delay(int p_delay){
	
	MCF_DTIM0_DTCN = 0x00;
	MCF_DTIM0_DTRR = (unsigned long)(5*(p_delay -1));
	MCF_DTIM0_DTER |= 0x02; 
	MCF_DTIM0_DTMR |= 0x0001;
	
	while(~MCF_DTIM0_DTER & 0x02){}
	

	
}
void dtim3_delay(int p_delay){
	
	MCF_DTIM3_DTCN = 0x00;
	MCF_DTIM3_DTRR = (unsigned long)(p_delay -1);
	MCF_DTIM3_DTER |= 0x02;
	MCF_DTIM3_DTMR |= 0x0001;
	
	while(~MCF_DTIM3_DTER & 0x02){}
}