#ifndef PLAYER_H
#define PLAYER_H
struct Player {
    char name[20];
    int x;
    int y;
    int hp;
    int attak;
    int gold;
    int sunduk;
};


void moveple(struct Player *p, int ch);


#endif