#ifndef PLAYER_H_
#define PLAYER_H_
#include "constant.h"
#include "rogalic.h"



struct Player {
    char name[20];
    int x;
    int y;
    int hp;
    int attak;
    int gold;
    int sunduk;
};

struct Player initPlayer();
void move_usr(struct Player *p, int ch, char* map[HEIGHT][WIDTH]);
void player_info(int i, struct Player player);
void put_place_player(struct Player* player);



#endif