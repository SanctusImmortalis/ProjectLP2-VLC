#ifndef PRODUCER_H
#define PRODUCER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Thread.h"
#include "Sync.h"

class Producer : public Thread{
public:
  Producer(const char* ip, const char* port, Buffer* b) : Thread(ip, port, b) {}
  virtual ~Producer();
  void Produce(char* data);
private:
  sockaddr_in addr;
  Buffer* buf;
};

#endif
