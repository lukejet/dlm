#include <string.h>
#include "service.h"

static int topdownProc(void* args)
{
	printf("call topdown proc  \n");
	return 0;
}

static Service serv = {
    .name = "top",
    .description = "",
    .fn = topdownProc,
    .next = 0
};

static char* module_name = "topdown";
static char* module_version = "1.0";

//module_type = ;

int module_init(Service* srv, char* name, char* version)
{
    int ret =0;
    strcpy(name, module_name);
    strcpy(version, module_version);

    // service filter listener driver and so on..
    ret = registerService(srv, &serv);
    if (ret < 0)
    {
    	return  ret;
    }
/*
    ret = registerListener();
    if (ret < 0)
    {
    	return  ret;
    }
   */

   // if we  do new thread here
    return 0;
}

int module_remove()
{
    int ret =0;
    ret = unregisterService();
    if (ret < 0)
    {
    	return  ret;
    }
    
  return 0;
}


