#include "../lib/automain.h"

inline int automain(const register int argc, const register int vargc, register char **vargv)
{
    for(register int i = 1; i < vargc; i++)
    {
        printf("%s\r\n", vargv [i]);
    }
    exit(EXIT_SUCCESS);
}