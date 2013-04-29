/*Source File:  pit.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "pit.h"
#include "global.h"

void pit0_init(){
	
    MCF_PIT0_PCSR &= ~(1);
    MCF_PIT0_PCSR |= 1 << 5;
    MCF_PIT0_PCSR |= 1 << 4;
    MCF_PIT0_PCSR |= 1 << 3;
    MCF_PIT0_PCSR |= 1 << 2;
    MCF_PIT0_PCSR |= 1 << 1;
    MCF_PIT0_PMR = 1000;
    MCF_PIT0_PCSR |= (3) << 8;
    interupt_config(55, 5, 7, pit0_isr);
    
    MCF_PIT0_PCSR |= 1; // Enable timer
    
}

void pit1_init(){
    MCF_PIT1_PCSR &= ~(1);       
    MCF_PIT1_PCSR |= 1 << 5;
    MCF_PIT1_PCSR |= 1 << 4;
    MCF_PIT1_PCSR |= 1 << 3;
    MCF_PIT1_PCSR |= 1 << 2;
    MCF_PIT1_PCSR |= 1 << 1;
    MCF_PIT1_PMR = 5000;
    MCF_PIT1_PCSR |= (11) << 8;
    
    interupt_config(56, 5, 7, pit1_isr);
    
    MCF_PIT1_PCSR |= 1;
	
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