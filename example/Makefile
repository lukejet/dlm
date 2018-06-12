

all: topdown.so modB.so
	cp *.so ../

topdown.so: topdown.c  
	gcc -shared -o topdown.so topdown.c  -I..
	
modB.so: 
	gcc -shared -o $@ modB.c  -I..

clean: 
	rm -rf *.so
