#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "Sync.h"

class Thread{
public:
  Thread(bool* result, const char* ip, const char* port, Buffer* b);
  ~Thread() {}
  bool isActive();
  void deactivate();
  void Join();

  bool active;
  pthread_t t;
  sockaddr_in addr;
  Buffer* buf;
};

#endif
