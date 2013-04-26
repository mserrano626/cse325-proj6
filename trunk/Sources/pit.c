/*
 * pit.c
 *
 *  Created on: Apr 19, 2013
 *      Author: maserra3
 */
#include "pit.h"
#include "global.h"

void pit0_init(){
    //re-write this function
	
	//PIT 1 // LED REFRESH TIMER
    MCF_PIT0_PCSR &= ~(1); // disable timer
    
    MCF_PIT0_PCSR |= 1 << 5; // DEBUG MODE ENABLED
    MCF_PIT0_PCSR |= 1 << 4; // Immediately overwrite value in PIT counter
    MCF_PIT0_PCSR |= 1 << 3; // Enable Interrupts
    MCF_PIT0_PCSR |= 1 << 2; // Clear interrupt request flag
    MCF_PIT0_PCSR |= 1 << 1; // Make PCNTR0 value into PMR0
    
    MCF_PIT0_PMR = 999;
    MCF_PIT0_PCSR |= (3) << 8;
    
    interupt_config(55, 5, 7, pit0_isr);
    
    MCF_PIT0_PCSR |= 1; // Enable timer
    
}

void pit1_init(){
    MCF_PIT1_PCSR &= ~(1); // disable timer
            
    MCF_PIT1_PCSR |= 1 << 5; // DEBUG MODE ENABLED
    MCF_PIT1_PCSR |= 1 << 4; // Immediately overwrite value in PIT counter
    MCF_PIT1_PCSR |= 1 << 3; // Enable Interrupts
    MCF_PIT1_PCSR |= 1 << 2; // Clear interrupt request flag
    MCF_PIT1_PCSR |= 1 << 1; // Make PCNTR0 value into PMR0
    
    MCF_PIT1_PMR = 49999;
    MCF_PIT1_PCSR |= (11) << 8;
    
    
    interupt_config(56, 5, 7, pit1_isr);
    
    
    MCF_PIT1_PCSR |= 1; // Enable timer
	
}


void pit0_enable(){
         MCF_PIT0_PCSR |= 0x1;
}

void pit1_enable(){
	MCF_PIT1_PCSR |= 0x1;
}

void pit0_off() {
        //clear PCSR0[0] EN bit
        MCF_PIT0_PCSR &= ~(0x0001);
}

void pit1_off() {
        //clear PCSR1[0] EN bit
        MCF_PIT1_PCSR &= ~(0x0001);
}