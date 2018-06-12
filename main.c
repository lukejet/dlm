/*
  *  sample test modules feature.
  */
  
#include "modules.h"
#include "service.h"

int main()
{
	int ret = 0;
	insMod("topdown.so", 0);

	while(1)
	{
	do_services();
	}
	lsMods();
	uninsMod("topdown");
	
	return 0;
}
