/*
  *  sample test modules feature.
  */
  
#include "modules.h"
#include "service.h"

Service* lst_srvs;

int main()
{
	lst_srvs = 0;
	int ret = 0;
	ret = insMod("./modB.so", 0, lst_srvs);
	if (ret)
	{
		printf("Failed install module %s.  \n", "modB.so");
		return -1;
	}
	ret = insMod("./topdown.so", 0, lst_srvs);
	if (ret)
	{
		printf("Failed install module %s.  \n", "topdown.so");
		return -1;
	}

	//while(1)
	{
	do_services(lst_srvs);
	}
	lsMods();

	
	uninsMod("topdown");

	uninsMod("mod B plan");
	
	return 0;
}
