//every variable and function in here needs to be defined in game.cpp
#ifndef GAME_H
#define GAME_H

#include "core.h"
#include "pong.h"

extern bool key_up;
extern bool key_down;
extern bool key_left;
extern bool key_right;

void game_init();
void game_deinit();
void game_reset();
void game_draw(uint8_t* frame_buf);
void game_run();

#endif

