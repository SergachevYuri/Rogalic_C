#include "rogalic.h"


int main() {
    char* map[HEIGHT][WIDTH];
    struct Monsters mob;
    int ch = 0;
    struct Player player = initPlayer();
    initscr();
    noecho();
    curs_set(FALSE);
    dungeons(map);
    mob = Summon_Monsters();
    while (ch != 'q')
    {
        ch = getch();
        switch (ch) {
            case 'w':
                player.x--;
                break;
            case 's':
                player.x++;
                break;
            case 'a':
                player.y--;
                break;
            case 'd':
                player.y++;
                break;
        }   
        clear();
        graphic(player, map, mob);
        refresh();
        //usleep(500 * 1000);
    }
    endwin();
    return 0;
}

struct Player initPlayer() {
    struct Player player;
    player.x = 10;
    player.y = 10;
    player.hp = 10;
    player.attak = 1;
    player.gold = 0;
    player.sunduk = 0;

    return player;
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

void dungeons(char* map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if((i == 0 && j != 0 && j != WIDTH - 1) || (i == HEIGHT - 1 && j != 0 && j != WIDTH - 1)) {
                map[i][j] = "#";
            } else if((i != 0 && i != HEIGHT - 1 && j == 0) || (i != 0 && i != HEIGHT - 1 && j == WIDTH - 1)){
                map[i][j] = "#";
            } else {
                map[i][j] = " ";
            }
        }
    }
    
}

struct Monsters Summon_Monsters() {
    struct Monsters goblin;
    goblin.x = 20;
    goblin.y = 20;
    goblin.pointer = 'g';
    goblin.hp = 2;
    goblin.attak = 2;
    strcpy(goblin.name, "Goblin Moblin");

    return goblin;
}

void player_info(int i, struct Player player) {
    if (i == 1) {
        printw("  Hello player");
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