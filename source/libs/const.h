#ifndef CONST_H
#define CONST_H

#define HEIGHT 50
#define LENGTH 100

struct element {
    int x_pos;
    int y_pos;
    int prev_x_pos;
    int prev_y_pos;
    int x_spd;
    int y_spd;
    char skin;
    char prev_skin;
    int color;
    int prev_color;
};

#endif
