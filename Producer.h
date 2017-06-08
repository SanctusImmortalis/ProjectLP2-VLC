#ifndef PRODUCER_H
#define PRODUCER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "Thread.h"
#include "Sync.h"

void* producerCode(void* arg);

class Producer : public Thread{
public:
  Producer(bool* result, const char* ip, const char* port, Buffer* b) : Thread(result, ip, port, b) { if(*result) {rear = 0; bind(getSock(), (sockaddr*) &addr, sizeof(addr)); pthread_create(&t, NULL, producerCode, (void*) this);} }
  void Produce();

  int rear;
};

#endif
