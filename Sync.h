#ifndef SYNC_H_PROJ
#define SYNC_H_PROJ

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "sem.h"

int sock;

Semaphore* full, empty, atom;

void initSync(int n);
void terminateSync();
int FetchAndAdd(int* ptr, int val);

#endif
