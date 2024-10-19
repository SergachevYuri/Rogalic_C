#include "player.h"
#include "rogalic.h"

void moveple(struct Player *p, int ch) {
    switch (ch)
    {
        case 'w':
            if(p->x - 1 > 0) p->x--;
            break;
        case 's':
            if(p->x + 1 < HEIGHT - 1) p->x++;
            break;
        case 'a':
            if(p->y - 1 > 0) p->y--;
            break;
        case 'd':
            if(p->y + 1 < WIDTH - 1)p->y++;
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