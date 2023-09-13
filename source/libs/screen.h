#ifndef SCREEN_H
#define SCREEN_H

#include "const.h"
#include "logic.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ELEMENTS 256

FILE *debug_file;
extern int DEBUG;

char *table[HEIGHT];
struct element elements_list[MAX_ELEMENTS];
int elements_count = 0;

void show_char(struct element *elem)
{
    int x = elem->x_pos;
    int y = elem->y_pos;
    int px = elem->prev_x_pos;
    int py = elem->prev_y_pos;
    char c = elem->skin;
    char pc = elem->prev_skin;
    int col = elem->color;
    int pcol = elem->prev_color;


    printf("\033[%d;%dH\033[48;5;%dm%c", x+1, y+1, col, c);
    printf("\033[%d;%dH\033[48;5;%dm%c", px+1, py+1, pcol, pc);
}

void show(char **table) {
    printf ("\033[H\033[2J");

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

void create_element(int x, int y, char skin, int color) {
    struct element new_elem;
    new_elem.x_pos = x;
    new_elem.y_pos = y;
    new_elem.prev_x_pos = -1;
    new_elem.prev_y_pos = -1;
    new_elem.x_spd = 1;
    new_elem.y_spd = 1;
    new_elem.skin = skin;
    new_elem.prev_skin = '$';
    new_elem.color = color;
    new_elem.prev_color = 0;


    elements_list[elements_count] = new_elem;
    elements_count++;
}

char **get_elements()
{
    debug_file = fopen("DEBUG_OUTPUT", "a");

    int c = 0;
    while (c < elements_count)
    {
        struct element * Pelem = &elements_list[c];

        moving_dot(Pelem);

        struct element elem = elements_list[c];

        int x_pos = elem.x_pos;
        int y_pos = elem.y_pos;
        int prev_x_pos = elem.prev_x_pos;
        int prev_y_pos = elem.prev_y_pos;
        int x_spd = elem.x_spd;
        int y_spd = elem.y_spd;
        char chr = elem.skin;
        char prev_char = elem.prev_skin;

        table[x_pos][y_pos] = chr;
        if (prev_x_pos < 0 || prev_y_pos < 0) {

        } else {
            table[prev_x_pos][prev_y_pos] = prev_char;
        }

        show_char (Pelem);

        c++;
    }

    fclose(debug_file);


    return table;
}
#endif
