#include "rogalic.h"
#include "player.h"

extern char* map[HEIGHT][WIDTH];

struct Player initPlayer() {
    struct Player player;
    player.x = 10;
    player.y = 10;
    player.hp = 10;
    player.attak = 1;
    player.gold = 0;
    player.sunduk = 0;
    printf("Ты просыпаешься в холодном, тёмном подземелье, окружённый древними каменными стенами, покрытыми плесенью и паутиной. В воздухе стоит затхлый запах, а где-то вдали слышны тихие капли воды, падающие на пол. Твоя голова пульсирует от недавнего удара, воспоминания о произошедшем размыты. Ты помнишь, как стоял перед воротами величественного города, который когда-то был процветающим, но теперь лежит в руинах. Ходят легенды, что в его подземельях скрыты древние сокровища, но ещё чаще рассказывают о тех, кто оттуда не вернулся.\n");
    printf("На твоём поясе — скромное оружие и горсть провизии. Твои мысли обрываются, когда впереди раздаются шаги и злобное хихиканье. Гоблины. Эти мерзкие существа захватили подземелья после падения города, обжились в них и стали ещё более дерзкими. Но за гоблинами всегда скрывается нечто большее — легенды шепчут о древнем зле, которое веками покоилось в самых глубинах.\n");
    printf("Теперь твоё время пришло. Ты должен выжить, выбраться из этих проклятых коридоров и найти ответы: что здесь произошло? Почему все, кто осмеливался зайти сюда, исчезли? И какова твоя настоящая роль в этой тёмной истории?\n");
    printf("Но прежде чем ты начнёшь свой путь, как тебя зовут, герой?\n");
    scanf("%s", player.name);

    return player;
}

void move_usr(struct Player *p, int ch, char* map[HEIGHT][WIDTH]) {
    switch (ch)
    {
        case 'w':
            if(*map[p->x - 1][p->y] != '#') p->x--;
            break;
        case 's':
            if(*map[p->x + 1][p->y] != '#') p->x++;
            break;
        case 'a':
            if(*map[p->x][p->y - 1] != '#') p->y--;
            break;
        case 'd':
            if(*map[p->x][p->y + 1] != '#')p->y++;
            break;
    }
}

void player_info(int i, struct Player player) {
    if (i == 1) {
        printw("  Hello %s", player.name);
    }
    else if (i == 2) {
        printw("  HP : %d", player.hp);
    }
    else if (i == 3 ) {
        printw("  Attak : %d", player.attak);
    }
    else if (i == 4) {
        printw("  Gold : %d", player.gold);
    }
    else if (i == 5) {
        printw("  Sunduk : %d", player.sunduk);
    }
}

void put_place_player(struct Player* player) {
    int x, y;
    do{
        x = rand() % (HEIGHT - 2) + 1;
        y = rand() % (WIDTH - 2) + 1;
    }while(*map[x][y] == '#');
    player->x = x;
    player->y = y;
}