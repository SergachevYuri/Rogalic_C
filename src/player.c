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