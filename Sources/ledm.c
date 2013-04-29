/*Source File:  ledm.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "ledm.h"
#include "global.h"


uint8 g_green[8];
uint8 g_red[8];
uint8 row;

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

void write_matrix(int pattern[8][8]){
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
		g_red[i] = 0x00;
		g_green[i] = 0x00;
		for(j = 0 ; j < 8; j++){
			if(new_pattern[i][j] == red){
				g_red[i] |= 1 << j;
			}
			else if(new_pattern[i][j] == green){
				g_green[i] |= 1 << j;
			}
			else if(new_pattern[i][j] == orange){
				g_red[i] |= 1 << j;
				g_green[i] |= 1 << j;
			}
		}
	}
	ledm_refresh();
	pit0_enable();
}

void ledm_refresh(){
	uint8 data[3];
	data[0] = g_red [row];
	data[1] = g_green [row];
	data[2] = (unsigned char) ~(1 << row);
			
	MCF_GPIO_SETTH |= 0x80;
	MCF_GPIO_CLRTH &= 0xBF;
		
	qspi_transmit(data); 
	
	MCF_GPIO_SETTH |= 0x40;
	MCF_GPIO_CLRTH &= 0x7F;
			
	row = row + 1;

	if(row == 8)
	{
		row = 0;
	}
}
