#include "Producer.h"

void* producerCode(void* arg){
  Producer* t = (Producer*) arg;
  while(t->isActive()){
    empty->P();
    t->Produce();
    CompareAndSwap(&(t->buf[t->rear].toRead), 0, Consumer::n);
    CompareAndSwap(&(t->buf[t->rear].VIPsToRead), 0, Consumer::VIPs);
    t->buf[t->rear].filled -> V();
    t->rear = (t->rear + 1) % BUFFERSIZE;
  }
  delete t;
}

void Producer::Produce(){
  recvfrom(sock, &(buf[rear].data), PACKETSIZE, 0, NULL, NULL);

}
