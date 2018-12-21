#include "service.h"


extern Service* lst_srvs;

int registerService(Service* lst, Service* srv)
{
	Service* p = lst;
	if (!lst)
	{
		 lst = srv;
		 return 0;
	}
	while(p->next) p=p->next;
	p->next = srv;
	srv->next = 0;

	printf("registerService success \n");
    return 0;
}
int unregisterService()
{
    return 0;
}

int do_services(Service* lst)
{
	Service* p = lst;
	for(;p ; p=p->next)
	{
		p->fn(p);
	}
	return 0;
}

