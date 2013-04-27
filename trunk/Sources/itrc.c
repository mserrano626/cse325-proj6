/*Source File:  itrc.c
 *Project Name: Project 5
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "itrc.h"
#include "global.h"



extern uint32 __VECTOR_RAM[];
int screencount;
#define ICR_BASE (volatile uint8 *)(0x40000C40)

void interupt_config(int src, int level, int priority, isr_funct isr){
        volatile uint8 *icr;
        
        /* Write the address of the ISR (in p_isr) into the exception vector table at the proper offset from the beginning of the table.
        */
        __VECTOR_RAM[64 + src] = (uint32)isr;

        /* Write the level and priority for the interrupt source into the appropriate ICR register. */
        icr = (volatile uint8 *)(ICR_BASE + src);
        *icr = (uint8)(level << 3 | priority);

        /* Unmask interrupts from the interrupt source. */
        interupt_unmask_src(src);
}

void interupt_unmask_src(int src){
        /* The mask bits for interrupt sources 32-63 are in the IMRH registers. The mask bits for interrupt sources 1-31 are in the IMRL registers. Note, when clearing bits in IMRL it is important not to write 1 to IMRL[0] because this is the MASKALL bit.
        */

        if (src > 31) {
                MCF_INTC0_IMRH &= ~(1 << (src - 32));
        } 
        else {
                MCF_INTC0_IMRL &= ~(1 << src) & 0xFFFFFFFE;
        }
}

asm __declspec(standard_abi) void int_uninhibit_all(){
        
        move.w SR, d0
        andi.l #0xF8FF, d0
        move.w d0, SR
        rts
        
}

asm __declspec(standard_abi) void int_inhibit_all(){
        
        move.w SR, d0
        ori.l #0x0700, d0
        move.w d0, SR
        rts
        
}


__declspec(interrupt) void pit0_isr(){


                MCF_PIT0_PCSR |= 0x0004;
               
                screencount++;
                
                ledm_refresh();
                if(screencount == (4*256)){
                	screencount = 0;
                	if(end_game != 0){
                		game_refresh();
                	}
                	else if(end_game == 0){
                		//dead_sound();
                	}
           
                	
                }

                
}

__declspec(interrupt) void pit1_isr(){

              	
                //Clear pit 1 channel 0 interrupt request flag
                //disable pit 1
				MCF_PIT1_PCSR &= ~(0x01) << 0;
				//clear interupt
				MCF_PIT1_PCSR &= ~((0x01) << 2);

                
				//play note
				note(0xFF);

                //nunchuck read
                fst_nunchuk_read();
                //enable pit 1
                MCF_PIT1_PCSR |= 0x01;
}


__declspec(interrupt) void gpt0_isr()
{
        //Clear the interrupt request flag
        MCF_GPT_GPTFLG1 |= 0x01;
        
        game_reset();
        
}

//__declspec(interrput) void qspi_isr()
//{
        //interupt_config(18, 4, 6, isr_funct qspi_isr);
        //clear request flag
        //MCF_QSPI_QIR &= (~(0x1) << 8);
        
//}
 
 