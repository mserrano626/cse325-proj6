/*Source File:  pwm.c
 *Project Name: Project 4
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "global.h"
#include "pwm.h"

struct Note{
        int pre;
        int scale;
        int period;
        int duty;
        int led;
}Note;

void init_pwm(){
		MCF_GPIO_PTAPAR |= MCF_GPIO_PTAPAR_PTAPAR3(3);
	
		MCF_GPIO_DDRTA |= MCF_GPIO_DDRTA_DDRTA3;
	
	
	
		/*enables PWM7 which is connected to the speaker*/
        MCF_PWM_PWME = MCF_PWM_PWME_PWME7; 
        
        /*sets the polarity to start at 0*/
        MCF_PWM_PWMPOL = 0x00;
        
        /*sets pwm7 to clk SB*/
        MCF_PWM_PWMCLK = 0x80;
        
        /*sets channel 7 to left align*/
        MCF_PWM_PWMCAE = 0x00;
        
        /*sets channel 7 to have a seperate 8bit PWM*/
        MCF_PWM_PWMCTL = 0x00;
        
        /*Initializes controls for setting pitch*/
        MCF_PWM_PWMPRCLK = 0x0;
        MCF_PWM_PWMSCLB = 0x0;
        MCF_PWM_PWMPER7 = 0x0;
        MCF_PWM_PWMDTY7 = 0x0;
        
}

void set_pitch(int pre, int scale, int period, int duty){
        MCF_PWM_PWMPRCLK = (unsigned char)pre;
        MCF_PWM_PWMSCLB = (unsigned char)scale;
        MCF_PWM_PWMPER7 = (unsigned char)period;
        MCF_PWM_PWMDTY7 = (unsigned char)duty;
}




void note(int p_note)
{
        
        
        if(p_note == 0x00){
                /*B3 - 246.94 Hz*/
                Note.pre = 0x01;
                Note.scale = 0xA2;
                Note.period = 0xFA;
                Note.duty = 0xC8;
                
        }
        else if (p_note == 0x01){
                /*C4 - 261.63*/
                Note.pre = 2;
                Note.scale = 149;
                Note.period = 255;
                Note.duty = 204;
                
        }
        else if (p_note == 0x02){
                        /*C#4 - 277.18*/
                Note.pre = 0x01;
                Note.scale = 0xCD;
                Note.period = 0xB0;
                Note.duty = 0x84;
               
                }
        else if (p_note == 0x03){
                        /*D4 - 293.66*/
                Note.pre = 0x01;
                Note.scale = 0xC6;
                Note.period = 0xAC;
                Note.duty = 0x81;
               
                }
        else if (p_note == 0x04){
                        /*D#4 - 311.13*/
                Note.pre = 0x01;
                Note.scale = 0xCE;
                Note.period = 0x9C;
                Note.duty = 0x75;
               
                }
        else if (p_note == 0x05){
                        /*E4 - 329.63*/
                Note.pre = 0x01;
                Note.scale = 0xED;
                Note.period = 0x80;
                Note.duty = 0x60;
               
                }
        else if (p_note == 0x06){
                        /*F4 - 349.23*/
                Note.pre = 0x00;
                Note.scale = 0xE6;
                Note.period = 0xF9;
                Note.duty = 0xBB;
                
                }
        else if (p_note == 0x07){
                        /*F#4 - 369.99*/
                Note.pre = 0x00;
                Note.scale = 0xE8;
                Note.period = 0xE9;
                Note.duty = 0xAF;
                
                }
        else if (p_note == 0x08){
                        /*G4 - 392.00*/
                Note.pre = 0x00;
                Note.scale = 0xEA;
                Note.period = 0xDA;
                Note.duty = 0xA4;
               
                }
        else if (p_note == 0x09){
                        /*G#4 - 415.30*/
                Note.pre = 0x00;
                Note.scale = 0xF2;
                Note.period = 0xC7;
                Note.duty = 0x95;
                
                }
        else if (p_note == 0x0A){
                        /*A4 - 440 Hz*/
                Note.pre = 0x00;
                Note.scale = 0xF3;
                Note.period = 0xBB;
                Note.duty = 0x8C;
                
                }
        else if (p_note == 0x0B){
                        /*A#4 - 466.16*/
                Note.pre = 0x00;
                Note.scale = 0xBD;
                Note.period = 0xE3;
                Note.duty = 0xAA;
                
                }
        else if (p_note == 0x0C){
                /*B3 - 246.94 Hz*/
                Note.pre = 0x00;
                Note.scale = 0xA2;
                Note.period = 0xFA;
                Note.duty = 0xC8;
                
        }
        else if (p_note == 0x0D){
                        /*C5 - 523.25*/
                Note.pre = 0x00;
                Note.scale = 0xF5;
                Note.period = 0x9C;
                Note.duty = 0x75;
                
                }
        else{
                //pause
                Note.pre = 0x00;
                Note.scale = 0x0;
                Note.period = 0x0;
                Note.duty = 0x0;
                
                
        }
        
        set_pitch(Note.pre, Note.scale, Note.period, Note.duty);
             
}