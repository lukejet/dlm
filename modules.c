#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "list.h"
#include "modules.h"

typedef int (*Func_init)(char**, char**);
typedef int (*Func_release)();

static Module_t* sm;

static int  initMod(Module_t* module)
{
	// get module_init function in so 
	Func_init init_func;
	int ret;
	init_func = getFunc("module_init", module->lib);
	if (NULL == init_func) 
	{
		printf("error: no init function found.");
		return -1;
	}
	ret = init_func(&(module->name), &(module->version));
	if (ret < 0)
	{
		return  ret;
	}
    return 0;
}

static int  releaseMod(Module_t* module)
{
	// get module_init function in so 
	Func_release release_func;
	int ret;
	release_func = getFunc("module_remove", module->lib);
	if (NULL == release_func) 
	{
		printf("error: no release function found.");
		return -1;
	}
	ret = release_func();
	if (ret < 0)
	{
		return  ret;
	}

	ret = releaseLib(module->lib);
	
	if (ret < 0)
	{
		return  ret;
	}
  return 0;
}
static int addtoModList(Module_t* mod)
{
	sm = mod;
	return 0;
}
static Module_t*  findMod(char* name)
{
	return sm;
	return 0;
}

int lsMods()
{
   // listOfModule;

    //printModules();
    return 0;
}
int insMod(char* path, int mode)
{
	int ret = 0;
	Module_t *module = (Module_t*)malloc(sizeof (Module_t));
	//memset(module, 0, sizeof (Module_t));
	
	strcpy(module->so_path, path);
	
	
    HANDLE lib = loadLib(path);
    if (0 == lib )
    {
    	return -1;
    }
    printf("load library %s success!\n", path);
    module->lib = lib;
    ret = initMod(module);
    if (ret <0)
    {
    	return ret;
    }
    
    printf("load module %s success!\n", module->name);
    
    addtoModList(module);
}
int uninsMod(char* name)
{
	int ret;
	Module_t* module;
	module = findMod(name);
	if(NULL == module)
	{
	    printf("can't find the module :%s .\n", name);
	    return -1;
	}

	ret = releaseMod(module);
	if (ret <0)
	{
		return ret;
	}
	printf("release module %s success!\n", module->name);
	return 0;
}


