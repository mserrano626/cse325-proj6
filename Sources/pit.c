/*
 * pit.c
 *
 *  Created on: Apr 19, 2013
 *      Author: maserra3
 */
#include "pit.h"
#include "global.h"

void pit_init(){
	MCF_PIT0_PCSR &= 0x0000;
	MCF_PIT0_PCSR |= 0x0F3E;
	MCF_PIT0_PMR = 610;
}

void pit0_enable(){
         MCF_PIT0_PCSR |= 0x1;
}

void pit_off() {
        //clear PCSR0[0] EN bit
        MCF_PIT0_PCSR &= ~(0x0001);
}