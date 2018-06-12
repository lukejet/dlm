#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "library.h"

HANDLE loadLib(char* path)
{
	return dlopen(path, RTLD_LAZY );
}

Func* getFunc(char* name, HANDLE lib)
{
	return dlsym(lib, name);
}

int releaseLib(HANDLE lib)
{
	dlclose(lib);

}

