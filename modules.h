#ifndef _MODULES_H_
#define _MODULES_H_

#include "service.h"
#include "library.h"

typedef enum {
  MT_CORE, 
  MT_WORK,
}MODULE_TYPE;

typedef struct Module
{
    char so_path[256];
    char name[32];
    char version[32];
    HANDLE lib;
    Service* srv_;

    struct Module* next;
} Module_t;


int lsMods();
int insMod();
int uninsMod();


#endif /*_MODULES_H_*/
