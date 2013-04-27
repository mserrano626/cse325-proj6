/*
 * gpt.c
 *
 *  Created on: Apr 26, 2013
 *      Author: maserra3
 */
#include "global.h"


void gpt_init(){
	
    MCF_GPIO_PTAPAR |= 1;
    
    
    MCF_GPIO_DDRTA &= 0;
	
	
    MCF_GPT_GPTIOS &= ~(0x7);
    
    MCF_GPT_GPTCTL2 |= MCF_GPT_GPTCTL2_EDG0A; // # 3
    MCF_GPT_GPTCTL2 &= ~MCF_GPT_GPTCTL2_EDG0B;
    
    //MCF_GPT_GPTFLG1 &= 0xE;
    
    MCF_GPT_GPTIE |= 0x1;
    
    MCF_GPT_GPTSCR1 |= 0x80;
    
    MCF_GPT_GPTDDR &= 0xE;
    
    interupt_config(44, 1, 7, gpt0_isr);
    
    
}