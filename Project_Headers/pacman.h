/*Source File:  pacman.h
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
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
extern void dead_sound();
#endif /* PACMAN_H_ */
