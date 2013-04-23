/*
 * pacman.c
 *
 *  Created on: Apr 22, 2013
 *      Author: maserra3
 */

#include "global.h"

#define black 0
#define	red  1
#define	green 2
#define	orange 3

int pattern3[8][8] = {
        { red, black, black, black, black, black, black, black},
        { black, green, green, green, green, green, black, black},
        { black, green, black, black, black, black, black, black},
        { black, green, black, green, green, green, black, black},
        { black, green, black, green, black, green, black, black},
        { black, green, black, green, black, green, black, black},
        { black, black, black, black, black, black, black, black},
        { black, black, black, black, black, black, black, orange}
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
        { red, black, black, green, green, black, black, red}
};





void game_init(){
	
	ledm_refresh(pattern3);
	
}
