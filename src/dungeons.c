#include "rogalic.h"
#include "dungeons.h"


void dungeons(char* map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if((i == 0 && j != 0 && j != WIDTH - 1) || (i == HEIGHT - 1 && j != 0 && j != WIDTH - 1)) {
                map[i][j] = WALL;
            } else if((i != 0 && i != HEIGHT - 1 && j == 0) || (i != 0 && i != HEIGHT - 1 && j == WIDTH - 1)){
                map[i][j] = WALL;
            } else {
                map[i][j] = SPACE;
            }
        }
    }
    
}

/*

void create_dungeon(char* dungeon[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            dungeon[i][j] = WALL;
        }
        
    }
    
}

void generate_rooms(int n, int rooms[][2]) {
    for (int i = 0; i < n; i++)
    {
        int room_h = rand() % (12 - 6 + 1) + 6;
        int room_w = rand() % (20 - 10 + 1) + 10;
    }
    
}

void init_dungeons(char* dungeon[HEIGHT][WIDTH]) {

    create_dungeon(dungeon);

    int num_rooms = rand() % (12 - 6 + 1) + 6;
    int rooms[num_rooms][2];

    generate_rooms(num_rooms, rooms);
}

*/