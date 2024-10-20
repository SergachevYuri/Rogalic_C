#include "rogalic.h"
#include "monsters.h"

extern char* map[HEIGHT][WIDTH];

const char *goblin_names[] = {
    "Grognar", "Squizz", "Urknak", "Blizztok", "Shnagg", "Trogzik",
    "Krivz", "Mokshak", "Gnurt", "Plok", "Vreksh", "Zurmp", "Kraksh",
    "Ligzt", "Skriptz", "Raglok", "Grumps", "Flingar", "Churk", "Skrolt"
};

const char *troll_names[] = {
    "Grullnar", "Troggrog", "Vurtog", "Drogmar", "Kragtor", "Zugnar", "Hurg",
    "Torgrog", "Murlok", "Urtag", "Brognor", "Granchar", "Varkgrim", "Klarog",
    "Zognur", "Trognar", "Drungor", "Hrolg", "Brogar", "Grumtor"
};

const char *orc_names[] = {
    "Grakhar", "Durgash", "Mogrok", "Hurgash", "Braggok", "Vorgat", "Kragmar",
    "Torgash", "Grodmar", "Grizmak", "Zargul", "Roknar", "Mugrok", "Shragor", 
    "Vorkgat", "Urzog", "Brognar", "Hurzul", "Drogash", "Zurmar"
};


int count_goblin_names = sizeof(goblin_names) / sizeof(goblin_names[0]);
int count_troll_names = sizeof(troll_names) / sizeof(troll_names[0]);
int count_orc_names = sizeof(orc_names) / sizeof(orc_names[0]);


struct Monsters Summon_Monsters()
{
    int who = rand() % (3 - 0);
    struct Monsters monsters;
    int rand_name;

    switch (who)
    {
    case 0:
        rand_name = rand() % count_goblin_names;
        put_place(&monsters);
        monsters.pointer = 'g';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, goblin_names[rand_name]);
        break;
    case 1:
        rand_name = rand() % count_troll_names;
        put_place(&monsters);
        monsters.pointer = 't';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, troll_names[rand_name]);
        break;
    case 2:
        rand_name = rand() % count_orc_names;
        put_place(&monsters);
        monsters.pointer = 'o';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, orc_names[rand_name]);
        break;
    default:
        rand_name = rand() % count_goblin_names;
        put_place(&monsters);
        monsters.pointer = 'g';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, goblin_names[rand_name]);
        break;
    }

    return monsters;
}


void put_place(struct Monsters* monster) {
    int x;
    int y;
    do {
        x = rand() % (HEIGHT - 2) + 1;
        y = rand() % (WIDTH - 2) + 1;
    }while(*map[x][y] == '#');

    monster->x = x;
    monster->y = y;
}