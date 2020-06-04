#include "../lib/automain.h"

int automain(int argc, int vargc, char **vargv)
{
    for(register int i = 1; i < vargc; i++)
    {
        printf("%s\r\n", vargv [i]);
    }
    exit(EXIT_SUCCESS);
}