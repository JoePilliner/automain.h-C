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