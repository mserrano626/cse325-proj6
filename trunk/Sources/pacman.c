/*Source File:  pacman.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "global.h"


#define black 0
#define	red  1
#define	green 2
#define	orange 3

int end_game = 1;

int ghost = red;
int ghostmove = 0;
int g_col = 0;
int g_row = 0;

int pac = orange;
int p_col = 7;
int p_row = 7;


int board[8][8] = {
        { black, black, black, black, black, black, black, black},
        { black, green, green, green, green, green, black, black},
        { black, green, black, black, black, black, black, black},
        { black, green, black, green, green, green, black, black},
        { black, green, black, green, black, green, black, black},
        { black, green, black, green, black, green, black, black},
        { black, black, black, black, black, black, black, black},
        { black, black, black, black, black, black, black, black}
};
int pattern1[8][8] = {
                { orange, black, black, green, green, black, black, orange},
                { black, black, green, black, black, green, black, black},
                { black, green, black, black, black, black, green, black},
                { green, black, black, red, red, black, black, green},
                { green, black, black, red, red, black, black, green},
                { black, green, black, black, black, black, green, black},
                { black, black, green, black, black, green, black, black},
                { orange, black, black, green, green, black, black, orange}
};

int pattern2[8][8] = {
        { red, black, black, black, black, black, black, red},
        { black, black, green, black, black, green, black, black},
        { black, black, green, black, black, green, black, black},
        { black, black, black, black, black, black, black, black},
        { black, black, black, black, black, black, black, black},
        { black, green, black, black, black, black, green, black},
        { black, black, green, black, black, green, black, black},
        { orange, black, black, green, green, black, black, orange}
};





void game_refresh(){
	int p_last_row = p_row;
	int p_last_col = p_col;
	
	ghost_movement();

	write_matrix(board);
	
	if(g_col == p_col && g_row == p_row){
		note(0xFF);
		end_game = 0;
	}
	/*
	if(p_last_row != p_row || p_last_col != p_col){
		note(0x0D);
	}
	*/
	
}


void change_dir(int direction){
	switch (direction){
	case 0:	
		
		if(p_row == 0 || check_wall_up() == 0){
			board[p_col][p_row] = pac;
		}
		else{	
			clear_pac();
			p_row = p_row - 1;
			board[p_col][p_row] = pac;
			note(0x03);
			
			note(0x00);

			//printf("up");
		}
		break;
	case 1: 
		if(p_row == 7 || check_wall_down() == 0 ){
			board[p_col][p_row] = pac;
		}
		else{
			clear_pac();
			p_row = p_row + 1;
			board[p_col][p_row] = pac;
			note(0x03);
			
			note(0x00);

			//printf("down");
		}
		break;
	case 2:
		if(p_col == 7 || check_wall_left() == 0){
			board[p_col][p_row] = pac;
		}
		else{
			clear_pac();
			p_col = p_col + 1;
			board[p_col][p_row] = pac;
			note(0x03);
			
			note(0x00);

			//printf("left");
		}
		break;
	case 3: 
		if(p_col == 0 || check_wall_right() == 0){
			board[p_col][p_row] = pac;
		}
		else{
			clear_pac();
			p_col = p_col - 1;
			board[p_col][p_row] = pac;
			note(0x03);
			
			note(0x00);

			//printf("right");
		}
		break;
	case 4: 
		board[p_col][p_row] = pac;
		note(0xFF);
		//printf("stop");
		break;
	}
}

void game_reset(){
	
	
	//init ghost position
	clear_pac();
	clear_ghost();
	
	board[0][0] = ghost;
	board[7][7] = pac;
	
	ghostmove = 0;
	g_col = 0;
	g_row = 0;

	
	p_col = 7;
	p_row = 7;
	
	end_game = 1;
	
	pit0_init();
	pit1_init();
	
	
	
	
}

void ghost_movement(){
	if(ghostmove < 6){
		clear_ghost();
		g_col = g_col + 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else if(ghostmove == 6 || ghostmove < 8){
		clear_ghost();
		g_row = g_row + 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else if(ghostmove == 8 || ghostmove < 12){
		clear_ghost();
		g_col = g_col - 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else if(ghostmove == 12 || ghostmove < 16){
		clear_ghost();
		g_row = g_row + 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else if(ghostmove == 16 || ghostmove < 18){
		clear_ghost();
		g_col = g_col - 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else if(ghostmove == 18 || ghostmove < 24){
		clear_ghost();
		g_row = g_row - 1;
		board[g_col][g_row] = ghost;
		ghostmove++;
	}
	else{
		ghostmove = 0;
	}
	
}

void clear_ghost(){
	
	board[g_col][g_row] = black;
}

void pac_movement(){
	
}

void clear_pac(){
	board[p_col][p_row] = black;
	
	
}

int check_wall_up(){
	if(board[p_col][p_row-1] == green){
		return 0;
	}
	else
		return 1;
}

int check_wall_down(){
	if(board[p_col][p_row+1] == green){
		return 0;
	}
	else
		return 1;
}

int check_wall_left(){
	if(board[p_col+1][p_row] == green){
		return 0;
	}
	else
		return 1;
}

int check_wall_right(){
	if(board[p_col-1][p_row] == green){
		return 0;
	}
	else
		return 1;
}
/*
void dead_sound(){
	int i = 0;
	int deathsound[] = {0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF};
	
	note(deathsound[i]);
	i++;
	MCF_PIT1_PCSR &= ~(1);
		if(i == 7)
		{
			i = 0;
			MCF_PIT0_PCSR &= ~(1);
			MCF_PIT1_PMR = 999;
			MCF_PIT0_PMR = 4999;
		}
	
	
	
	
}
*/