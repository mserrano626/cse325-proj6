/*Source File:  nunchuck.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "global.h"

#define FST_NUNCHUK_I2C_ADDR	0x52
#define FST_NUNCHUK_DELAY_US	150
#define FST_NUNCHUK_REFRESH_MS	250




void fst_nunchuk_init(){
	
	dtim0_init();
	i2c_init(); //100 kHz

	
	
}

void nunchuk_down(){
	change_dir(down);
}
void nunchuk_up(){
	change_dir(up);
}
void nunchuk_left(){
	change_dir(left);
}
void nunchuk_right(){
	change_dir(right);
}


void fst_nunchuk_read(){
	
	int data[6] = {0x80, 0x80, 0, 0, 0, 0};
	
	fst_nunchuk_xmit_cmd(0xF0, 0x55);
	
	fst_nunchuk_xmit_cmd(0xFB, 0x00);
	
	fst_nunchuk_xmit_cmd(0x00, 0x00);
	
	i2c_rx(FST_NUNCHUK_I2C_ADDR, 6, data, FST_NUNCHUK_DELAY_US);
	
	//checks to see if joystick is moving left or right
	if (data[0] < 75){
		nunchuk_left();
	}
	else if (data[0] > 175){
		nunchuk_right();
	}
	else if(data[0] > 100 && data[0] < 150 && data[1] > 100 && data[1] < 150)
		fst_nunchuk_reset();
	
	//checks to see if joystick is moving up or down
	if (data[1] < 75){
		nunchuk_down();
	}
	else if (data[1] > 175){
		nunchuk_up();
	}

}

void fst_nunchuk_reset(){
	change_dir(stop);

}

void fst_nunchuk_xmit_cmd (int reg, int cmd){
	
	int data[2] = {0, 0};
	int count = 0;
	if (reg != 0x00)
	{
		data[0] = reg;
		data[1] = cmd;
		count = 2;
	}
	else{
		data[0] = cmd;
		count = 1;
	}
	
	i2c_tx(0x52, count, data, 150);
	
	//use DMA timer 3 to busy-delay for 2x FST_NUNCHUK_DELAY_US microseconds
	
	dtim0_delay(2*150);
}