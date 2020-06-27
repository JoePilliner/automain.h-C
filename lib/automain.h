#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern inline int automain(const register int argc, register int vargc, register char **vargv); //automain is passed argc (the number of actual arguments), vargc (the number of virtual arguments), and vargv (the vector of C-string virtual arguments)

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        printf("%s Automain Arguments:\r\n", argv [0]);
        for(int i = 1; i < argc; i++)
        {
            printf("%s\r\n", argv [i]);
        }
        printf("\r\n%s Automain:\r\n", argv [0]);
        automain(argc, argc, argv);
    }
    else
    {
        int vargc = argc;
        char **vargv = NULL;

        if(vargc == 0)
        {
            vargc = 1;
            if((vargv = calloc(1, sizeof(char *))) == NULL)
            {
                perror("");
                exit(EXIT_FAILURE);
            }
            vargv [0] = NULL;
        }
        else if(vargc == 1)
        {
            char *buffer_chunk = calloc(BUFSIZ, sizeof(char));

            puts("Anonymous Automain Arguments:");
            while(fgets(buffer_chunk, BUFSIZ, stdin) != NULL)
            {
                if((vargv = realloc((void *) vargv, (vargc + 1) * sizeof(char *))) == NULL)
                {
                    perror("");
                    exit(EXIT_FAILURE);
                }
                if((vargv [vargc] = calloc(strlen(buffer_chunk), sizeof(char))) == NULL)
                {
                    perror("");
                    exit(EXIT_FAILURE);
                }
                strncpy(vargv [vargc], buffer_chunk, strlen(buffer_chunk));
                vargc++;
            }
            puts("\r\nAnonymous Automain:");
            vargv [vargc] = NULL;
            free(buffer_chunk);
            automain(argc, vargc, vargv);
        }
        else
        {
            fputs("Automain argc changed between comparisons. As of the 4th of June 2020 BCE (Gregorian Calendar), this error should be impossible.\r\n", stderr);
        }
    }
}