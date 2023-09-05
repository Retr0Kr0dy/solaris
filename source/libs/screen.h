#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define HEIGHT 30
#define LENGTH 60

char *table[HEIGHT];

void show(char **table) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGTH; j++) {
            printf ("%c", table[i][j]);
        }
        printf ("\n");
    }
}

char **get_background() {
    for (int i = 0; i < HEIGHT; i++) {
        table[i] = (char *)malloc(LENGTH * sizeof(char));
        for (int j = 0; j < LENGTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == LENGTH - 1) {
                table[i][j] = '#';
            } else {
                table[i][j] = ' ';
            }
        }
    }

    return table;
}

#endif
