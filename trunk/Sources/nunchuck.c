/*
 * nunchuck.c
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */
#include "global.h"

#define FST_NUNCHUK_I2C_ADDR	0x52
#define FST_NUNCHUK_DELAY_US	150
#define FST_NUNCHUK_REFRESH_MS	250

int count;


void fst_nunchuk_init(){
	//fst_nunchuk_reset();
	dtim0_init();
	i2c_init(); //100 kHz
	//pit1_init();
	//set up pit timer
	
	
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
	
	fst_nunchuk_xmit_cmd(0x00, 0x55);
	
	i2c_rx(FST_NUNCHUK_I2C_ADDR, 6, data, FST_NUNCHUK_DELAY_US);
	
	//checks to see if joystick is moving left or right
	if (data[0] < 30){
		nunchuk_left();
	}
	else if (data[0] > 225){
		nunchuk_right();
	}
	else 
		fst_nunchuk_reset();
	
	//checks to see if joystick is moving up or down
	if (data[1] < 30){
		nunchuk_down();
	}
	else if (data[1] > 208){
		nunchuk_up();
	}
	/*
	if ((data[5] & 0x01) == 0){
		g_callback_button_z();
	}
	
	if(((data[5] & (1 << 1)) >> 1) == 1){
		g_callback_button_c();
	}
	*/
}

void fst_nunchuk_reset(){
	change_dir(stop);

}

void fst_nunchuk_xmit_cmd (unsigned char reg, unsigned char cmd){
	
	int data[2] = {0, 0};
	
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
	
	i2c_tx(FST_NUNCHUK_I2C_ADDR, count, data, FST_NUNCHUK_DELAY_US);
	
	//use DMA timer 3 to busy-delay for 2x FST_NUNCHUK_DELAY_US microseconds
	
	dtim0_delay(2*FST_NUNCHUK_DELAY_US);
}