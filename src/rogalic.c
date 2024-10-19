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