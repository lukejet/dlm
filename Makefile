all: test topdown

topdown: 
	cd example; make

test: modules.c main.c library.c
	gcc -o test modules.c main.c library.c -ldl

clean:
	rm test *.so
	cd example; make clean