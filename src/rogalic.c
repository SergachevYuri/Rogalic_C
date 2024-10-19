#include "rogalic.h"
#include "player.h"


int main() {
    setlocale(LC_CTYPE, "ru_RU.UTF8");
    char* map[HEIGHT][WIDTH];
    struct Monsters mob;
    int ch = 0;
    srand(time(0));
    system("clear");
    struct Player player = initPlayer();
    initscr();
    noecho();
    curs_set(FALSE);
    dungeons(map);
    mob = Summon_Monsters();
    graphic(player, map, mob);
    while (ch != 'q')
    {
        ch = getch();
        moveple(&player, ch);
        if(check_kill(&player, mob)) {
            mob = Summon_Monsters();
        }
        clear();
        graphic(player, map, mob);
        refresh();
    }
    endwin();
    return 0;
}

int check_kill(struct Player *p, struct Monsters m) {
    if (p->x == m.x && p->y == m.y) {
        p->gold = p->gold + 10;
        return 1;
    } else {
        return 0;
    }
}

void graphic(struct Player player, char* map[HEIGHT][WIDTH], struct Monsters mob) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if(i == player.x && j == player.y){
                printw("@");
            } else if(i == mob.x && j == mob.y){
                printw("%c", mob.pointer);
            } else {
                printw("%s", map[i][j]);
            }
        }
        player_info(i, player);
        printw("\n");
    }
}

struct Monsters Summon_Monsters() {
    struct Monsters goblin;
    goblin.x = rand() % (HEIGHT + 1 - 1) + 1;
    goblin.y = rand() % (WIDTH + 1 - 1) + 1;
    goblin.pointer = 'g';
    goblin.hp = 2;
    goblin.attak = 2;
    strcpy(goblin.name, "Goblin Moblin");

    return goblin;
}