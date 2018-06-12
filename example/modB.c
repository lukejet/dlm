#include <string.h>
#include "service.h"

static int modBProc(void* args)
{
}

static Service serv = {
    .name = "hello_world",
    .description = "",
    .fn = modBProc,
};


static char* module_name = "mod B plan";
static char* module_version = "1.0";

//module_type = ;

int module_init(char** name, char** version)
{
    int ret =0;
    strcpy(*name, module_name);
    strcpy(*version, module_version);

    // add code here
    
    return 0;
}

int module_remove()
{
    int ret =0;
    // add release code here
    
  return 0;
}



