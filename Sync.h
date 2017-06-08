#ifndef SYNC_H_PROJ
#define SYNC_H_PROJ

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "sem.h"
#include "Buffer.h"



Semaphore* getEmpty();
Semaphore* getAtom();
int getSock();
void initSync(Buffer b[]);
//void terminateSync();
int FetchAndAdd(int* ptr, int val);
int CompareAndSwap(int* ptr, int old, int nu);
bool TestAndSet(bool* ptr);

#endif
