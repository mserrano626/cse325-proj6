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
	fst_nunchuk_reset();
	//DTIM3 INIT
	i2c_init(); //100 kHz
	//pit_init()
	//set up pit timer
	
	
}

void fst_nunchuk_on_button_c(void(*callback)(void)){
	g_callback_button_c = callback;
}

void fst_nunchuk_on_button_z(void(*callback)(void)){
	g_callback_button_z = callback;
}

void fst_nunchuk_on_stick_down(void(*callback)(void)){
	g_callback_stick_down = callback;
}

void fst_nunchuk_on_stick_left(void(*callback)(void)){
	g_callback_stick_left = callback;
}

void fst_nunchuk_on_stick_right(void(*callback)(void)){
	g_callback_stick_right = callback;
}

void fst_nunchuk_on_stick_up(void(*callback)(void)){
	g_callback_stick_up = callback;
}

void fst_nunchuk_read (){
	
	unsigned char data[6] = {0x80, 0x80, 0, 0, 0, 0};
	
	fst_nunchuk_xmit_cmd(0xF0, 0x55);
	
	fst_nunchuk_xmit_cmd(0xFB, 0x00);
	
	fst_nunchuk_xmit_cmd(0x00, 0x55);
	
	i2c_rx(FST_NUNCHUK_I2C_ADDR, 6, data, FST_NUNCHUK_DELAY_US);
	
	//checks to see if joystick is moving left or right
	if (data[0] < 30 && g_callback_stick_left){
		g_callback_stick_left();
	}
	else if (data[0] > 225 && g_callback_stick_right){
		g_callback_stick_right();
	}
	
	//checks to see if joystick is moving up or down
	if (data[1] < 30 && g_callback_stick_down){
		g_callback_stick_down();
	}
	else if (data[1] > 208 && g_callback_stick_up){
		g_callback_stick_up();
	}
	
	if ((data[5] & 0x01) == 0){
		g_callback_button_z();
	}
	
	if(((data[5] & (1 << 1)) >> 1) == 1){
		g_callback_button_c();
	}
	
}

void fst_nunchuk_reset(){
	g_callback_stick_left = 0;
	g_callback_stick_right = 0;
	g_callback_stick_down = 0;
	g_callback_stick_up = 0;
	g_callback_button_z = 0;
	g_callback_button_c = 0;
}

void fst_nunchuk_xmit_cmd (unsigned char reg, unsigned char cmd){
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
	
	
}