#include "lib/screen.h"
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int DEBUG = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) {
            DEBUG = 1;
        }
    }



    int ifs = 0;
    int ips;
    int sec = 0;
    clock_t t1 = clock();


    while (1)
    {
        char **bkgd = get_background();
        show(bkgd);
        //DEBUG
        if (DEBUG) {
            ifs++;
            clock_t t2 = clock() - t1;
            sec = t2 * 100 / CLOCKS_PER_SEC;
            if (sec != 0) {
                ips = ifs / sec;
            } else {
                ips = 0;
            }
            printf("time = %4d\tifs = %4d\tips = %4d\n", sec, ifs, ips);
        }
        //ENDUG
        usleep(66000);
    }

    return 0;
}
