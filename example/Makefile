

all: topdown.so modB.so
	cp *.so ../

topdown.so: topdown.c  
	gcc -g -shared -o $@ topdown.c ../service.c -I.. -fPIC
	
modB.so: 
	gcc -g -shared -o $@ modB.c  -I.. -fPIC

clean: 
	rm -rf *.so
