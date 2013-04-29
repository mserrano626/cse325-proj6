/*Source File:  gpt.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "global.h"


void gpt_init(){
	
    MCF_GPIO_PTAPAR |= 1;
    MCF_GPIO_DDRTA &= 0;
    MCF_GPT_GPTIOS &= ~(0x7);
    MCF_GPT_GPTCTL2 |= MCF_GPT_GPTCTL2_EDG0A;
    MCF_GPT_GPTCTL2 &= ~MCF_GPT_GPTCTL2_EDG0B;
    MCF_GPT_GPTIE |= 0x1;
    MCF_GPT_GPTSCR1 |= 0x80;
    MCF_GPT_GPTDDR &= 0xE;
    
    interupt_config(44, 1, 7, gpt0_isr);
    
    
}