#include "rogalic.h"

char *map[HEIGHT][WIDTH];

int main()
{
    struct Monsters mob;
    int ch = 0;
    system("clear");
    struct Player player = initPlayer();

    init_games();

    init_dungeons(map);
    put_place_player(&player);
    mob = Summon_Monsters();
    graphic(player, map, mob);
    while (ch != 'q')
    {
        ch = getch();
        move_usr(&player, ch, map);
        if (check_kill(&player, mob))
        {
            mob = Summon_Monsters();
        }
        clear();
        graphic(player, map, mob);
        refresh();
    }
    endwin();
    return 0;
}

void init_games() {
    srand(time(0));
    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);    // Красный текст на черном фоне
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // Зеленый текст на черном фоне
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // Желтый текст на черном фоне
}

int check_kill(struct Player *p, struct Monsters m)
{
    if (p->x == m.x && p->y == m.y)
    {
        p->hp -= m.attak;
        p->gold = p->gold + 10;
        return 1;
    }
    else
    {
        return 0;
    }
}

void graphic(struct Player player, char *map[HEIGHT][WIDTH], struct Monsters mob)
{
    print_dungeons(map);
    print_player(player);
    print_monsters(mob);
}

void print_dungeons(char *map[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            mvprintw(i, j, "%s", map[i][j]);
        }
    }
}

void print_player(struct Player player)
{
    mvaddch(player.x, player.y, '@');
}

void print_monsters(struct Monsters monsters)
{
    int color_pair = 0;

    switch (monsters.pointer)
    {
    case 'g':
        color_pair = 1;
        break;
    case 't':
        color_pair = 2;
        break;
    case 'o':
        color_pair = 3;
        break;
    }
    attron(COLOR_PAIR(color_pair));
    mvaddch(monsters.x, monsters.y, monsters.pointer);
    attroff(COLOR_PAIR(color_pair));

}