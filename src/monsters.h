#ifndef MONSTERS_H_
#define MONSTERS_H_
#include "constant.h"
#include "rogalic.h"


struct Monsters {
    int x;
    int y;

    char pointer;
    
    int hp;
    int attak;
    char name[20];
};


struct Monsters Summon_Monsters();
void put_place(struct Monsters* monster);
#endif