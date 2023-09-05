#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 50
#define LENGTH 100

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

static int x = 2;
static int y = 2;
static char charc = 'O';

void **moving_dot()
{
    static void *elem[3];
    elem[0] = &x;
    elem[1] = &y;
    elem[2] = &charc;

    if (x < LENGTH - 2)
    {
        if (y >= HEIGHT - 2)
        {
            y = 2;
        }
        x+=3;
    }
    else
    {
        x = 2;
        y++;
    }

    return elem;
}

char **get_elements() {
    void **temp = moving_dot();
    void *elem[3] = {*(int **) temp, *(int **) (temp + 1), *(char **) (temp + 2)};

    int x_pos = *(int*) elem[0];
    int y_pos = *(int*) elem[1];
    char chr = *(char*) elem[2];

    for (int i = 0; i < HEIGHT; i++) {
        table[i] = (char *)malloc(LENGTH * sizeof(char));
        for (int j = 0; j < LENGTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == LENGTH - 1) {
                table[i][j] = '#';
            } else if (i == y_pos && j == x_pos) {
                table[i][j] = chr;
            } else {
                table[i][j] = ' ';
            }
        }
    }

    return table;
}


#endif
