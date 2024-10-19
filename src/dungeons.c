#include "dungeons.h"
#include "rogalic.h"


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