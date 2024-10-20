#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  100
#define HEIGHT 30

// Символы для карты
#define WALL '#'
#define FLOOR '.'

// Карта подземелья
char dungeon[HEIGHT][WIDTH];

// Функция для создания комнаты
void create_room(int x, int y, int w, int h) {
    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
                dungeon[i][j] = FLOOR;
            }
        }
    }
}

// Горизонтальный коридор
void create_h_corridor(int x1, int x2, int y) {
    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    for (int x = x1; x <= x2; x++) {
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            dungeon[y][x] = FLOOR;
        }
    }
}

// Вертикальный коридор
void create_v_corridor(int y1, int y2, int x) {
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    for (int y = y1; y <= y2; y++) {
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            dungeon[y][x] = FLOOR;
        }
    }
}

// Генерация комнат
void generate_rooms(int num_rooms, int rooms[][2]) {
    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand() % 12 + 4;
        int room_height = rand() % 8 + 4;
        int room_x = rand() % (WIDTH - room_width - 1) + 1;
        int room_y = rand() % (HEIGHT - room_height - 1) + 1;

        create_room(room_x, room_y, room_width, room_height);
        rooms[i][0] = room_x + room_width / 2;  // центр комнаты (x)
        rooms[i][1] = room_y + room_height / 2; // центр комнаты (y)
    }
}

// Соединение комнат коридорами
void connect_rooms(int rooms[][2], int num_rooms) {
    for (int i = 1; i < num_rooms; i++) {
        int x1 = rooms[i - 1][0];
        int y1 = rooms[i - 1][1];
        int x2 = rooms[i][0];
        int y2 = rooms[i][1];

        if (rand() % 2) {
            create_h_corridor(x1, x2, y1);
            create_v_corridor(y1, y2, x2);
        } else {
            create_v_corridor(y1, y2, x1);
            create_h_corridor(x1, x2, y2);
        }
    }
}

// Инициализация подземелья
void init_dungeon() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dungeon[i][j] = WALL;
        }
    }
}

// Вывод карты подземелья
void print_dungeon() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    // Инициализация карты
    init_dungeon();

    // Количество комнат
    int num_rooms = 8;
    int rooms[8][2];  // Координаты центров комнат

    // Генерация комнат и коридоров
    generate_rooms(num_rooms, rooms);
    connect_rooms(rooms, num_rooms);

    // Вывод подземелья
    print_dungeon();

    return 0;
}
