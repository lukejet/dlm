#ifndef _LIBRARY_H_
#define _LIBRARY_H_


typedef int HANDLE;
typedef int Func;

HANDLE loadLib(char* path);
Func* getFunc(char* name, HANDLE lib);
int releaseLib(HANDLE lib);

#endif

