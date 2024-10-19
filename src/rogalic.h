#ifndef ROGALIC_H_
#define ROGALIC_H_
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "constant.h"
#include "monsters.h"
#include "player.h"
#include "dungeons.h"


void init_games();
void graphic(struct Player player, char* map[HEIGHT][WIDTH], struct Monsters mob);

int check_kill(struct Player *p, struct Monsters m);
#endif