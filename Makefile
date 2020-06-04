bin-example/automain_example : src-example/automain_example.c lib/automain.h Makefile
	mkdir -p bin-example
	cc -o bin-example/automain_example src-example/automain_example.c

clean :
	rm -f bin-example/automain_example