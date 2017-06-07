#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "Sync.h"

class Thread{
public:
  Thread(const char* ip, const char* port, Buffer* b);
  virtual ~Thread();
  bool isActive();
private:
  bool active;
  pthread_t t;
  sockaddr_in addr;
  Buffer* buf;
};

#endif
