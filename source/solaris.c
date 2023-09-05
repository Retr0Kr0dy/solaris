#include "libs/SolarisGraphics.h"
#include <string.h>

int DEBUG = 0; // default no debug
int FREQUENCY = 33; // default 33 milliseconds for 30 frame per second.

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
