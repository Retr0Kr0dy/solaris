#ifndef LOGIC_H
#define LOGIC_H

#include "const.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

FILE *debug_file;
extern int DEBUG;

extern char *table[];

void moving_dot(struct element *elem)
{
    int x = elem->x_pos;
    int y = elem->y_pos;
    elem->prev_x_pos = elem->x_pos;
    elem->prev_y_pos = elem->y_pos;
    int x_spd = elem->x_spd;
    int y_spd = elem->y_spd;
    char charc = elem->skin;


    if (x <= 1 || x >= HEIGHT - 2)
    {
        x_spd = -x_spd;
    }
    if (y <= 1 || y >= LENGTH - 2)
    {
        y_spd = -y_spd;
    }

    elem->x_pos = x + x_spd;
    elem->y_pos = y + y_spd;
    elem->prev_skin = table[elem->x_pos][elem->y_pos];
    elem->x_spd = x_spd;
    elem->y_spd = y_spd;

    fprintf(debug_file, "%3d,%3d\tMOV\n",elem->x_pos,elem->y_pos);
}

#endif
