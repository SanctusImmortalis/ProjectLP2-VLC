#ifndef CONSUMER_H
#define CONSUMER_H

#include "Thread.h"

#include <sys/socket.h>
#include <netinet/in.h>

void* consumerCode(void* t);

class Consumer{
public:
  Consumer(const char* ip, const char* port, Buffer* b, bool itisVIP) : Thread(ip, port, b) {
    atom->P();
    Consumer::num++;
    front = Consumer::lastFront;
    buf[front].toRead++;
    VIP = itisVIP;
    if(VIP) {Consumer::VIPs++; buf[front].VIPsToRead++;}
    atom->V();
    pthread_create(&t, NULL, consumerCode, (void*) this);
  }
  virtual ~Consumer();
  bool isVIP();
  void Consume();
private:
  int front;
  bool VIP;
public:
  static int VIPs;
  static int num;
  static int lastFront;
};

#endif
