# Automain

## Current Specification

automain.h is a C header file that defines a standard C main function ```int main (argc, char **argv)``` that calls an externally-defined automain function ```int automain (int argc, int vargc, char **vargv)``` and:

* passes through ```argc```; and

* either:

    * passes through ```vargc = argc``` and ```vargv = argv``` if ```argc > 1```; or

    * reads a ```BUFSIZ```-size buffer string from ```stdin``` into each element of the dynamically-allocated virtual argument string vector ```vargv```, storing the number of virtual argument strings read in ```vargc```, and passing through ```vargc``` and ```vargv```.

## Target Specification

automain.h will be a C header file that defines a standard C main function ```int main (argc, char **argv)``` that calls an externally-defined automain function ```int automain (int argc, int vargc, char **vargv)``` and:

* passes through ```argc```; and

* either:

    * passes through ```vargc = argc``` and ```vargv = argv``` if ```argc > 1```; or

    * reads an arbitrary-length string from ```stdin``` into each element of the dynamically-allocated virtual argument string vector ```vargv```, storing the number of virtual argument strings read in ```vargc```, and passing through ```vargc``` and ```vargv```.

## Portability
automain.h includes stdio.h, stdlib.h, and string.h from the C Standard Library and is portable across all Operating Systems that support and are supported by the C Standard Library

## Example Program

src-example/automain_example.c is an example program that sequentially echoes back the virtual argument strings in the virtual argument string vector it is passed as a parameter.

src-example/automain_example.c can be compiled to bin-example/automain_example by invoking GNU ```make``` on the included Makefile within a 'Nix shell