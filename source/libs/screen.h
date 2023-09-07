#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define HEIGHT 50
#define LENGTH 100
#define MAX_ELEMENTS 256

extern int DEBUG;

struct element {
    int x_pos;
    int y_pos;
    int prev_x_pos;
    int prev_y_pos;
    int x_spd;
    int y_spd;
    char skin;
    char prev_skin;
};

char *table[HEIGHT];
struct element elements_list[MAX_ELEMENTS];
int elements_count = 0;

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
/*
static int x = 25;
static int y = 50;
int prev_x_pos;
int prev_y_pos;
int x_spd = 1;
int y_spd = 1;
static char charc = 'O';
static char prev_char = ' ';
*/
void create_element(int x, int y, char skin) {
    struct element new_elem;
    new_elem.x_pos = x;
    new_elem.y_pos = y;
    new_elem.prev_x_pos = -1;
    new_elem.prev_y_pos = -1;
    new_elem.x_spd = 1;
    new_elem.y_spd = 1;
    new_elem.skin = skin;
    new_elem.prev_skin = '$';

    elements_list[elements_count] = new_elem;
    elements_count++;
}

void moving_dot(struct element elem)
{
    int x = elem.x_pos;
    int y = elem.y_pos;
    int prev_x_pos = elem.prev_x_pos;
    int prev_y_pos = elem.prev_y_pos;
    int x_spd = elem.x_spd;
    int y_spd = elem.y_spd;
    char charc = elem.skin;
    elem.prev_skin = elem.skin;

    elem.prev_x_pos = x;
    elem.prev_y_pos = y;

    if (x <= 1 || x >= HEIGHT - 2)
    {
        x_spd = -x_spd;
    }
    if (y <= 1 || y >= LENGTH - 2)
    {
        y_spd = -y_spd;
    }

    elem.x_pos = x + x_spd;
    elem.y_pos = y + y_spd;
}

char **get_elements()
{
//    void **temp = moving_dot();
//    void *elem[6] = {*(int **) temp, *(int **) (temp + 1),*(int **) (temp + 2), *(int **) (temp + 3), *(char **) (temp + 4), *(char **) (temp + 5)};

    int c = 0;
    while (c < sizeof(elements_list))
    {
        struct element elem;
        elem = elements_list[c];

        moving_dot(elem);

        int x_pos = elem.x_pos;
        int y_pos = elem.y_pos;

        printf ("%d:%d",x_pos,y_pos);

        int prev_x_pos = elem.prev_x_pos;
        int prev_y_pos = elem.prev_y_pos;
        int x_spd = elem.x_spd;
        int y_spd = elem.y_spd;
        char chr = elem.skin;
        char prev_char = elem.prev_skin;


        table[x_pos][y_pos] = chr;
        if (prev_x_pos < 0 || prev_y_pos < 0) {
            break;
        } else {
            table[prev_x_pos][prev_y_pos] = prev_char;
        }
    }

    return table;
}
#endif
