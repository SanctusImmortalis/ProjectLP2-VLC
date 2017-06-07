#ifndef PRODUCER_H
#define PRODUCER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "Thread.h"
#include "Sync.h"

void* producerCode(void* t);

class Producer : public Thread{
public:
  Producer(const char* ip, const char* port, Buffer* b) : Thread(ip, port, b) { rear = 0; pthread_create(&t, NULL, producerCode, (void*) this); }
  virtual ~Producer();
  void Produce();
private:
  int rear;
};

#endif
