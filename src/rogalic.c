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
    start_color(); // Инициализация цветов ncurses
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Красный текст на черном фоне
    init_pair(2, COLOR_RED, COLOR_BLACK); // Зеленый текст на черном фоне
    init_pair(3, COLOR_GREEN, COLOR_BLACK); // Желтый текст на черном фоне

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if(i == player.x && j == player.y){
                printw("@");
            } else if(i == mob.x && j == mob.y){
                switch (mob.pointer) {
                    case 'g':
                        attron(COLOR_PAIR(1));
                        break;
                    case 't':
                        attron(COLOR_PAIR(2));
                        break;
                    case 'o':
                        attron(COLOR_PAIR(3));
                        break;
                }
                printw("%c", mob.pointer);
                attroff(COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3));
            } else {
                printw("%s", map[i][j]);
            }
        }
        player_info(i, player);
        printw("\n");
    }
    printw("\n");
    switch (mob.pointer)
    {
    case 'g':
        printw("Kill Goblin: %s", mob.name);
        break;
    case 't':
        printw("Kill Troll: %s", mob.name);
        break;
    case 'o':
        printw("Kill Ork: %s", mob.name);
        break;
    }
    
}