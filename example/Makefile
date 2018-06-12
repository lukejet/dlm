

all: topdown.so
	cp *.so ../

topdown.so: topdown.c  
	gcc -shared -o topdown.so topdown.c  -I..

clean: 
	rm -rf *.so
