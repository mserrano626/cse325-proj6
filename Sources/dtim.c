/*
 * dtim.c
 *
 *  Created on: Apr 22, 2013
 *      Author: maserra3
 */

#include "global.h"

void dtim0_init(){
	/*
	MCF_DTIM0_DTMR = 0x4F0A;
	MCF_DTIM0_DTXMR = 0x40;
	*/
    MCF_DTIM0_DTMR |= (1 << 1);
    MCF_DTIM0_DTMR |= (1 << 3);
    MCF_DTIM0_DTMR |= (0xF << 8);
    MCF_DTIM0_DTMR |= 1;
}

void dtim1_init(){
	MCF_DTIM1_DTMR = 0x4F0A;
	MCF_DTIM1_DTXMR = 0x40;
}

void dtim3_init(){
	MCF_DTIM3_DTMR = 0x4F0A;
	MCF_DTIM3_DTXMR = 0x40;
	
}

void dtim0_delay(int p_delay){
	/*
	MCF_DTIM0_DTCN = 0x00;
	MCF_DTIM0_DTRR = (unsigned long)(p_delay -1);
	MCF_DTIM0_DTER |= 0x02; 
	MCF_DTIM0_DTMR |= 0x0001;
	
	while(~MCF_DTIM0_DTER & 0x02){}
	*/
	MCF_DTIM0_DTRR = ((unsigned long)5* p_delay-1);
	MCF_DTIM0_DTCN &= 0;
	                        
	while(((MCF_DTIM0_DTER & ( 1 << 1 )) >> 1) != 1)
	{
	}
	MCF_DTIM0_DTER |= (1 << 1);
	
}
void dtim3_delay(int p_delay){
	
	MCF_DTIM3_DTCN = 0x00;
	MCF_DTIM3_DTRR = (unsigned long)(p_delay -1);
	MCF_DTIM3_DTER |= 0x02;
	MCF_DTIM3_DTMR |= 0x0001;
	
	while(~MCF_DTIM3_DTER & 0x02){}
}