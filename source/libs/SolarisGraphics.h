#ifndef SOLARISGRAPHICS_H
#define SOLARISGRAPHICS_H

#include "screen.h"
#include <time.h>
#include <sys/resource.h>

extern int DEBUG;
extern int FREQUENCY;

void show(char **table);
void **create_table();
void **get_square();
char **get_background();
void create_element(int x, int y, char skin);
char **get_elements();


struct timespec start_time;
struct timespec from_start;
struct timespec current_time;

int _fps = 0;
int _ffs = 0;
int elapsed_time = 0;
int from_start_time = 0;
char **current_table;
struct rusage usage;
long mem;

/*
extern int x;
extern int y;
extern int prev_x_pos;
extern int prev_y_pos;
*/

void SolarisGraphics()
{
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    current_time = start_time;

    clock_gettime(CLOCK_MONOTONIC, &from_start);
    current_time = from_start;

    /* Creating Screen */

    create_table();
    get_square();

    create_element(25,50,'O');

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

            current_table = get_elements();
            show(current_table);

if (DEBUG) {
    if ((from_start_time / 1000) != 0) {
        _fps = _ffs / (from_start_time / 1000);
    }

    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        mem = usage.ru_maxrss;
    } else {
        mem = 0;
    }

    printf("time = %4d\tffs = %4d\tfps = %4d\tmem = %ld Kb\n", (from_start_time / 1000), _ffs, _fps, mem);
    printf("xy = %3d,%3d\told_xy = %3d,%3d\n", elements_list[0].x_pos, elements_list[0].y_pos, elements_list[0].prev_x_pos, elements_list[0].prev_y_pos);

}
            start_time = current_time;
            _ffs++;
        }
    }
}

#endif
