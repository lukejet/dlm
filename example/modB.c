#include <string.h>
#include "service.h"

static int modBProc(void* args)
{
	printf("call modB proc  \n");
	return 0;
}

static Service serv = {
    .name = "hello_world",
    .description = "",
    .fn = modBProc,

    .next = 0
};


static char* module_name = "mod B plan";
static char* module_version = "1.0";

//module_type = ;

int module_init(Service* srv, char* name, char* version)
{
    int ret =0;
    strcpy(name, module_name);
    strcpy(version, module_version);

    // add code here
    
    return 0;
}

int module_remove()
{
    int ret =0;
    // add release code here
    
  return 0;
}



