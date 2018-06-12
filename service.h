/**
 * make the service and module seperated.
 */
#ifndef _SERVICE_H_
#define _SERVICE_H_


typedef int (*Proc)(void* args);
typedef struct Service
{
    char* name;
    char* description;
    Proc fn;
} Service;

int do_services();

int registerService();
int unregisterService();


#endif

