#ifndef SOLARISGRAPHICS_H
#define SOLARISGRAPHICS_H

#include "screen.h"
#include <time.h>

extern int DEBUG;
extern int FREQUENCY;

void show(char **table);
char **get_back_ground();
char **get_elements();

struct timespec start_time;
struct timespec from_start;
struct timespec current_time;

int ips = 0;
int ifs = 0;
int elapsed_time = 0;
int from_start_time = 0;
char **elem;



extern int x;
extern int y;
extern int prev_x_pos;
extern int prev_y_pos;


void SolarisGraphics()
{
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    current_time = start_time;

    clock_gettime(CLOCK_MONOTONIC, &from_start);
    current_time = from_start;

    /* Creating Screen */

    create_table();
    get_square();

    /* End */

    while (1)
    {
        clock_gettime(CLOCK_MONOTONIC, &current_time);

        from_start_time= (current_time.tv_sec - from_start.tv_sec) * 1000 +
                       (current_time.tv_nsec - from_start.tv_nsec) / 1000000;

        elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000 +
                       (current_time.tv_nsec - start_time.tv_nsec) / 1000000;

        if (elapsed_time >= FREQUENCY)
        {
            elem = get_elements();
            show(elem);

if (DEBUG) {
    if ((from_start_time / 1000) != 0) {
        ips = ifs / (from_start_time / 1000);
    }
    printf("time = %4d\tifs = %4d\tips = %4d\txy = %3d,%3d\told_xy = %3d,%3d\n", (from_start_time / 1000), ifs, ips, x, y, prev_x_pos, prev_y_pos);
}

            start_time = current_time;
            ifs++;
        }
    }
}

#endif
