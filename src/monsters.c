#include "rogalic.h"

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
        rand_name = rand() % (count_goblin_names - 0);
        monsters.x = rand() % (HEIGHT + 1 - 1) + 1;
        monsters.y = rand() % (WIDTH + 1 - 1) + 1;
        monsters.pointer = 'g';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, goblin_names[rand_name]);
        break;
    case 1:
        rand_name = rand() % (count_troll_names - 0);
        monsters.x = rand() % (HEIGHT + 1 - 1) + 1;
        monsters.y = rand() % (WIDTH + 1 - 1) + 1;
        monsters.pointer = 't';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, troll_names[rand_name]);
        break;
    case 2:
        rand_name = rand() % (count_orc_names - 0);
        monsters.x = rand() % (HEIGHT + 1 - 1) + 1;
        monsters.y = rand() % (WIDTH + 1 - 1) + 1;
        monsters.pointer = 'o';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, orc_names[rand_name]);
        break;
    default:
        rand_name = rand() % (count_goblin_names - 0);
        monsters.x = rand() % (HEIGHT + 1 - 1) + 1;
        monsters.y = rand() % (WIDTH + 1 - 1) + 1;
        monsters.pointer = 'g';
        monsters.hp = 2;
        monsters.attak = 2;
        strcpy(monsters.name, goblin_names[rand_name]);
        break;
    }

    return monsters;
}