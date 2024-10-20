#include "rogalic.h"
#include "dungeons.h"

void create_dungeon(char* dungeon[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            dungeon[i][j] = WALL;
        }
    }
}

void generate_rooms(int n, int rooms[][2], char* dungeon[HEIGHT][WIDTH]) {
    for (int i = 0; i < n; i++)
    {
        int room_w = rand() % (15 - 5) + 5;
        int room_h = rand() % (8 - 2) + 5;
        int room_x = rand() % (WIDTH - room_w - 1) + 1;
        int room_y = rand() % (HEIGHT - room_h - 1) + 1;

        create_rooms(room_x, room_y, room_w, room_h, dungeon);

        rooms[i][0] = room_y + room_w / 2;  // центр комнаты (x)
        rooms[i][1] = room_x + room_h / 2; // центр комнаты (y)
    }
    
}

void connect_rooms(int rooms[][2], int num_rooms, char* dungeons[HEIGHT][WIDTH]) {
    for (int i = 1; i < num_rooms; i++) {
        int y1 = rooms[i - 1][0];
        int x1 = rooms[i - 1][1];
        int y2 = rooms[i][0];
        int x2 = rooms[i][1];

        if (rand() % 2) {
            create_h_corridor(x1, x2, y1, dungeons);
            create_v_corridor(y1, y2, x2, dungeons);
        } else {
            create_v_corridor(y1, y2, x1, dungeons);
            create_h_corridor(x1, x2, y2, dungeons);
        }
    }
}

// Горизонтальный коридор
void create_h_corridor(int x1, int x2, int y, char* dungeon[HEIGHT][WIDTH]) {
    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    for (int x = x1; x <= x2; x++) {
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            dungeon[y][x] = SPACE;
        }
    }
}

// Вертикальный коридор
void create_v_corridor(int y1, int y2, int x, char* dungeon[HEIGHT][WIDTH]) {
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    for (int y = y1; y <= y2; y++) {
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            dungeon[y][x] = SPACE;
        }
    }
}

void create_rooms(int room_x, int room_y, int room_width, int room_height, char* dungeon[HEIGHT][WIDTH]) {
    for (int i = room_y; i < room_y + room_height; i++) {
        for (int j = room_x; j < room_x + room_width; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
                dungeon[i][j] = SPACE;
            }
        }
    }
}

void init_dungeons(char* dungeon[HEIGHT][WIDTH]) {

    create_dungeon(dungeon);

    int num_rooms = rand() % (12 - 6 + 1) + 6;
    int rooms[num_rooms][2];

    generate_rooms(num_rooms, rooms, dungeon);
    connect_rooms(rooms, num_rooms, dungeon);
}
