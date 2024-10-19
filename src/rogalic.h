#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "player.h"
#include "monsters.h"

#define HEIGHT 30
#define WIDTH 100


void graphic(struct Player player, char* map[HEIGHT][WIDTH], struct Monsters mob);
void dungeons(char* map[HEIGHT][WIDTH]);
struct Monsters Summon_Monsters();
void player_info(int i, struct Player player);
