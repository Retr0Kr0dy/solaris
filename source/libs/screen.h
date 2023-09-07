#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 50
#define LENGTH 100

extern int DEBUG;

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


void **create_table() {
  for (int i = 0; i < HEIGHT; i++) {
    table[i] = (char *)malloc(LENGTH * sizeof(char));
  }
}


void **get_square() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < LENGTH; j++) {
      if (i == 0 || j == 0 || i == HEIGHT - 1 || j == LENGTH - 1) {
        table[i][j] = '#';
      } else {
        table[i][j] = ' ';
      }
    }
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

static int x = 25;
static int y = 50;
int prev_x_pos;
int prev_y_pos;
int x_spd = 1;
int y_spd = 1;
static char charc = 'O';
static char prev_char = ' ';

void **moving_dot()
{
    static void *elem[6];
    elem[0] = &x;
    elem[1] = &y;
    elem[2] = &prev_x_pos;
    elem[3] = &prev_y_pos;
    elem[4] = &charc;
    elem[5] = &prev_char;

    prev_x_pos = x;
    prev_y_pos = y;

    if (x <= 1 || x >= HEIGHT - 2)
    {
        x_spd = -x_spd;
    }
    if (y <= 1 || y >= LENGTH - 2)
    {
        y_spd = -y_spd;
    }
    x+=x_spd;
    y+=y_spd;

    return elem;
}

char **get_elements() {
    void **temp = moving_dot();
    void *elem[6] = {*(int **) temp, *(int **) (temp + 1),*(int **) (temp + 2), *(int **) (temp + 3), *(char **) (temp + 4), *(char **) (temp + 5)};

    int x_pos = *(int*) elem[0];
    int y_pos = *(int*) elem[1];
    int prev_x_pos = *(int*) elem[2];
    int prev_y_pos = *(int*) elem[3];
    char chr = *(char*) elem[4];
    char prev_char = *(char*) elem[5];

    table[x_pos][y_pos] = chr;
    table[prev_x_pos][prev_y_pos] = prev_char;

    return table;
}


#endif
