#ifndef CONSUMER_H
#define CONSUMER_H

#include "Thread.h"
#include "sem.h"

#include <sys/socket.h>
#include <netinet/in.h>

void* consumerCode(void* arg);

class Consumer : public Thread{
public:
  Consumer(bool* result, const char* ip, const char* port, Buffer* b, bool itisVIP) : Thread(result, ip, port, b) {
    if(*result){
        getAtom()->P();
        Consumer::num++;
        front = Consumer::lastFront;
        buf[front].toRead++;
        VIP = itisVIP;
        if(VIP) {
          if(!Consumer::VIPs) Consumer::VIPOnly -> P();
          Consumer::VIPs++;
        }
        getAtom()->V();
        pthread_create(&t, NULL, consumerCode, (void*) this);
    }
  }
  bool isVIP();
  void Consume();

  int front;
  bool VIP;
  static Semaphore* VIPOnly;
  static Semaphore* access;
  static int VIPs;
  static int num;
  static int lastFront;
  static bool firstIn;
};

#endif
