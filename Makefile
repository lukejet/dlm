all: test topdown

topdown: 
	cd example; make

test: modules.c main.c library.c
	gcc -g -o test modules.c main.c library.c service.c -ldl -rdynamic

clean:
	rm test *.so
	cd example; make clean