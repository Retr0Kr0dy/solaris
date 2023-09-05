#include "libs/screen.h"
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int DEBUG = 0;
    int FREQUENCY = 33;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) {
            DEBUG = 1;
        }
    }

    struct timespec start_time;
    struct timespec from_start;
    struct timespec current_time;
    int ips = 0;
    int ifs = 0;
    int elapsed_time = 0;
    int from_start_time = 0;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    current_time = start_time;

    clock_gettime(CLOCK_MONOTONIC, &from_start);
    current_time = from_start;

    while (1)
    {
        clock_gettime(CLOCK_MONOTONIC, &current_time);

        from_start_time= (current_time.tv_sec - from_start.tv_sec) * 1000 +
                       (current_time.tv_nsec - from_start.tv_nsec) / 1000000;

        elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000 +
                       (current_time.tv_nsec - start_time.tv_nsec) / 1000000;

        if (elapsed_time >= FREQUENCY)
        {
            char **bkgd = get_background();
            show(bkgd);
// DEBUG
if (DEBUG) {
    if ((from_start_time / 1000) != 0) {
        ips = ifs / (from_start_time / 1000);
    }
    printf("time = %4d\tifs = %4d\tips = %4d\n", (from_start_time / 1000), ifs, ips);
}
// END DEBUG
            start_time = current_time;
            ifs++;
        }
    }

    return 0;
}
