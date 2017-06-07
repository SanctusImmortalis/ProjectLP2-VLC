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
  Thread(const char* ip, const char* port, Buffer* b);
  virtual ~Thread();
  bool isActive();
  void deactivate();
  void Join();
private:
  bool active;
  pthread_t t;
  sockaddr_in addr;
public:
  Buffer* buf;
};

#endif
