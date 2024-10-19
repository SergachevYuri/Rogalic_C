#include "rogalic.h"


int main() {
    struct Player player;
    char* map[HEIGHT][WIDTH];
    struct Monsters mob;
    player.x = 5;
    player.y = 5;
    player.hp = 10;
    player.attak = 5;
    player.gold = 0;
    player.sunduk = 0;
    dungeons(map);
    mob = Summon_Monsters();
    graphic(player, map, mob);
    return 0;
}

void graphic(struct Player player, char* map[HEIGHT][WIDTH], struct Monsters mob) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if(i == player.x && j == player.y){
                printf("@");
            } else if(i == mob.x && j == mob.y){
                printf("%c", mob.pointer);
            } else {
                printf("%s", map[i][j]);
            }
        }
        printf("\n");
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
        printf("  Hello player");
    }
    else if (i == 2) {
        printf("  HP : %d", player.hp);
    }
    else if (i == 3 ) {
        printf ("  Attak : %d", player.attak);
    }
    else if (i == 4) {
        printf ("  Gold : %d", player.gold);
    }
    else if (i == 5) {
        printf("  Sunduk : %d", player.sunduk);
    }
}