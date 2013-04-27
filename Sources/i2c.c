/*
 * i2c.c
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */

#include "global.h"

#define I2C_MCF52259_ADDR	0x08
#define I2C_READ			0x01
#define I2C_WRITE			0x00

int dummy;

/***********************************
 * 
 **********************************/
void i2c_acquire_bus(){
	while(MCF_I2C0_I2SR & 0x20){}
	
}

void i2c_init(){
		
	//sets pin 0 and 1 to primary function SCL0 and SDA0
	MCF_GPIO_PASPAR &= 0;
	MCF_GPIO_PASPAR |= 0x05; 
	
	//writes the address to the address data register
	MCF_I2C0_I2ADR &= 0;
	MCF_I2C0_I2ADR |= (I2C_MCF52259_ADDR << 1);
	
	//write the frequency to FDR
	MCF_I2C0_I2FDR &= 0;
	MCF_I2C0_I2FDR |= 0x3A; // 896
	
	i2c_reset();
	
	if (MCF_I2C0_I2SR & 0x20){
		
		MCF_I2C0_I2CR &= 0x00;
		MCF_I2C0_I2CR |= 0xA0;
		dummy |= MCF_I2C0_I2DR;
		MCF_I2C0_I2SR &= 0x00;
		MCF_I2C0_I2CR &= 0x00;
		MCF_I2C0_I2CR |= 0x80;
	}
}

void i2c_reset(){
	
	//MCF_I2C0_I2CR &= 0x00;
	MCF_I2C0_I2CR |= 0x80; //configure IEN
	MCF_I2C0_I2CR &= ~(0x40);
	MCF_I2C0_I2CR &= ~(0x20);
	MCF_I2C0_I2CR &= ~(0x10);
	MCF_I2C0_I2CR &= ~(0x08);
	MCF_I2C0_I2CR &= ~(0x04);

}

void i2c_rx(int addr, int count, int data[], int delay_us){
	int i;
	
	i2c_acquire_bus();
	i2c_tx_addr(addr, I2C_READ, delay_us);
	
	//clear I2CR[MTX]
	MCF_I2C0_I2CR &= ~(0x10);
	
	//clear I2CR[TXAK]
	MCF_I2C0_I2CR &= ~(0x08);
	
	dummy &= i2c_rx_byte(delay_us);
	
	
	for(i = 0; i <= (count -2); i++){
		data[i] = i2c_rx_byte(delay_us);
	}
	
	//set I2CR[TXAK]
	MCF_I2C0_I2CR |= 0x08;
	data[count -1] = i2c_rx_byte(delay_us);
	
	i2c_rxtx_end();

}

uint8 i2c_rx_byte(int delay_us){
	uint8 byte;
	byte = MCF_I2C0_I2DR;
	while(!(i2c_tx_complete())){};
	MCF_I2C0_I2SR &= ~(0x02);
	//DELAY delay_us using one of the DMA timers
	dtim0_init();
	dtim0_delay(delay_us);
	
	
	return byte;
}

void i2c_rxtx_end(){
	
	//clear I2CR[MSTA]
	MCF_I2C0_I2CR &= ~(0x20); 
	i2c_reset();
}

void i2c_tx(int addr, int count, int data[], int delay_us){
	int i;
	
	i2c_acquire_bus();
	i2c_tx_addr(addr, I2C_WRITE, delay_us);
	
	for(i = 0;i <= count -1; i++){
		i2c_tx_byte((unsigned char)data[i], delay_us);
	}
	i2c_rxtx_end();
}

void i2c_tx_addr(int addr, int rw, int delay_us){
	uint8 addr_rw = 0;
	
	MCF_I2C0_I2CR |= 0x10;
	MCF_I2C0_I2CR |= 0x20;
	
	addr_rw |= addr << 1;
	addr_rw |= rw;
	
	i2c_tx_byte(addr_rw, delay_us);
	
}

void i2c_tx_byte(uint8 byte, int delay_us){
	int_inhibit_all();
	
	MCF_I2C0_I2DR = byte;
	
	while(!(i2c_tx_complete())){}
	
	
	MCF_I2C0_I2SR &= ~(0x02);
	
	//while(1){write_matrix();}
	int_uninhibit_all();//this is where my program is not working 
	//write_matrix();
	dtim0_delay(delay_us);
}

int i2c_tx_complete(){
	if(MCF_I2C0_I2SR & 0x02){
		return 1;
	}
	else 
		return 0;
}
