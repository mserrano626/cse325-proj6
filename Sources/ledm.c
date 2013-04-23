/*
 * ledm.c
 *
 *  Created on: Apr 19, 2013
 *      Author: maserra3
 */
#include "ledm.h"
#include "global.h"


uint8 Green[8];
uint8 Red[8];
uint8 Row;

#define black 0
#define	red  1
#define	green 2
#define	orange 3



int new_pattern[8][8];

void ledm_init(){
	MCF_GPIO_PTHPAR &= 0;
	MCF_GPIO_PTHPAR = 0xFFF;
	
	MCF_GPIO_DDRTH &= 0;
	MCF_GPIO_DDRTH = 0xC0;

	MCF_GPIO_SETTH |= 0x80;
	
}

void ledm_refresh(int pattern[8][8]){
	int i;
	int j;
	
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 8 ; j++){
			new_pattern[i][j] = pattern[i][j];
		}
	}
	update_matrix();
}

void update_matrix(){
	int i;
	int j;
	
	for(i = 0 ; i < 8; i++){
		Red[i] = 0x00;
		Green[i] = 0x00;
		for(j = 0 ; j < 8; j++){
			if(new_pattern[i][j] == red){
				Red[i] |= 1 << j;
			}
			else if(new_pattern[i][j] == green){
				Green[i] |= 1 << j;
			}
			else if(new_pattern[i][j] == orange){
				Red[i] |= 1 << j;
				Green[i] |= 1 << j;
			}
		}
	}
	write_matrix();
	pit0_enable();
}

void write_matrix(){
	uint8 data[3];
	data[0] = Red [Row];
	data[1] = Green [Row];
	data[2] = (unsigned char) ~(1 << Row);
			
	MCF_GPIO_SETTH |= 0x80;
	MCF_GPIO_CLRTH &= 0xBF;
		
	qspi_transmit(data); 
	
	MCF_GPIO_SETTH |= 0x40;
	MCF_GPIO_CLRTH &= 0x7F;
			
	Row = Row + 1;

	if(Row == 8)
	{
		Row = 0;
	}
}
