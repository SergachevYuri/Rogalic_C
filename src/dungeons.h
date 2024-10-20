#ifndef DUNGEONS_H_
#define DUNGEONS_H_
#include "constant.h"
#include "rogalic.h"


#define WALL "#"
#define SPACE " "

void init_dungeons(char* dungeons[HEIGHT][WIDTH]);
void create_dungeon(char* map[HEIGHT][WIDTH]);
void generate_rooms(int n, int rooms[][2], char* dungeon[HEIGHT][WIDTH]);
void create_rooms(int room_x, int room_y, int room_width, int room_height, char* dungeon[HEIGHT][WIDTH]);
void connect_rooms(int rooms[][2], int num_rooms, char* dungeons[HEIGHT][WIDTH]);

void create_h_corridor(int x1, int x2, int y, char* dungeons[HEIGHT][WIDTH]);
void create_v_corridor(int y1, int y2, int x, char* dungeons[HEIGHT][WIDTH]);

#endif