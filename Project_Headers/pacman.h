/*
 * pacman.h
 *
 *  Created on: Apr 22, 2013
 *      Author: maserra3
 */

#ifndef PACMAN_H_
#define PACMAN_H_

extern void game_refresh();
extern void change_dir(int);
extern void game_reset();
extern void ghost_movement();
extern void clear_ghost();
extern void pac_movement();
extern void clear_pac();
extern int check_wall_up();
extern int check_wall_down();
extern int check_wall_left();
extern int check_wall_right();
#endif /* PACMAN_H_ */
