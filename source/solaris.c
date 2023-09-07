#include "libs/SolarisGraphics.h"
#include <string.h>

int DEBUG = 0; // default no debug
int FREQUENCY = 16; // default 16 ms for approx. 60 fps, 33 ms for 30 fps.

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) {
            DEBUG = 1;
        }
    }

    SolarisGraphics();

    return 0;
}
