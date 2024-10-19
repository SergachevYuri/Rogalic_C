#ifndef DUNGEONS_H_
#define DUNGEONS_H_
#include "constant.h"
#include "rogalic.h"


#define WALL "#"
#define SPACE " "

void dungeons(char* map[HEIGHT][WIDTH]);
void create_dungeon(char* map[HEIGHT][WIDTH]);
#endif