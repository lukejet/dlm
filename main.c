/*
  *  sample test modules feature.
  */
  
#include "modules.h"
#include "service.h"

int main()
{
	int ret = 0;
	ret = insMod("./topdown.so", 0);
	if (ret)
	{
		printf("Failed install module %s.  \n", "topdown.so");
		return -1;
	}
	ret = insMod("./modB.so", 0);
	if (ret)
	{
		printf("Failed install module %s.  \n", "modB.so");
		return -1;
	}

	//while(1)
	{
	do_services();
	}
	lsMods();

	
	uninsMod("topdown");

	uninsMod("mod B plan");
	
	return 0;
}
