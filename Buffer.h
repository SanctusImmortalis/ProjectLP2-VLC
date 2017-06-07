#ifndef BUFFER_H
#define BUFFER_H

#define BUFFERSIZE 120
#define PACKETSIZE 1316

#include "sem.h"

typedef struct {
  Semaphore* VIP;
  Semaphore* access;
  Semaphore* filled;
  bool firstIn;
  int VIPsToRead;
  int toRead;
  char data[PACKETSIZE];
} Buffer;

#endif
