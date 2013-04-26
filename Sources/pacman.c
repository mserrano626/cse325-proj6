/*
 * pacman.c
 *
 *  Created on: Apr 22, 2013
 *      Author: maserra3
 */

#include "global.h"
#include <stdio.h>

#define black 0
#define	red  1
#define	green 2
#define	orange 3

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
	
	write_matrix(board);
	
	
}


void change_dir(int direction){
	switch (direction){
	case 0:	printf("up");
		break;
	case 1: printf("down");
		break;
	case 2: printf("left");
		break;
	case 3: printf("right");
		break;
	case 4: printf("stop");
		break;
	}
}

void game_reset(){
	int ghost = red;
	//init ghost position
	board[0][0] = ghost;
	
	
	pit0_init();
	//pit1_init();
}

///game refresh
