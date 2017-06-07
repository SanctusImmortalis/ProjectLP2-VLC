#include "Consumer.h"

Consumer::VIPs = 0;
Consumer::num = 0;
Consumer::lastFront = 0;

void* consumerCode(void* t){
  while(t->isActive()){
    buf[t->front].filled -> P();
    buf[t->front].filled -> V();
    atom -> P();
    if(buf[t->front].VIPsToRead && !TestAndSet(&(buf[t->front].firstIn))) buf[t->front].VIP->P();
    atom -> V();
    if((!t->isVIP()) && buf[t->front].VIPsToRead){
      buf[t->front].VIP->P();
      buf[t->front].VIP->V();
    }
    if(t->isVIP()) buf[t->front].access -> P();
    t->Consume();
    if(t->isVIP()) buf[t->front].access -> V();
    if(FetchAndAdd(&(buf[(t->front)].VIPsToRead), -1) == 1) {buf[t->front].VIP->V();}
    atom->P();
    if(!buf[(t->front)].toRead) { Consumer::lastFront = (t->front + 1)%BUFFERSIZE; atom->V(); buf[t->front].filled -> P(); buf[t->front].firstIn = false; empty->V(); }
    t->front = (t->front + 1) % BUFFERSIZE;
  }
  delete t;
}

void Consumer::Consume(){
  char* temp;
  temp = buf[front].data;
  sendto(sock, temp, PACKETSIZE, addr, sizeof(addr));
}

bool Consumer::isVIP(){
  return VIP;
}
