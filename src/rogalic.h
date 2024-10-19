#ifndef ROGALIC_H
#define ROGALIC_H
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#include "monsters.h"

#define HEIGHT 30
#define WIDTH 100

struct Player initPlayer();
void graphic(struct Player player, char* map[HEIGHT][WIDTH], struct Monsters mob);
void dungeons(char* map[HEIGHT][WIDTH]);
struct Monsters Summon_Monsters();
void player_info(int i, struct Player player);
int check_kill(struct Player *p, struct Monsters m);
#endif