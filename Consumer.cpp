#include "Consumer.h"

Consumer::VIPs = 0;
Consumer::num = 0;
Consumer::lastFront = 0;

void* consumerCode(void* t){
  while(t->isActive()){
    t->buf[t->front].filled -> P();
    t->buf[t->front].filled -> V();
    atom -> P();
    if(t->buf[t->front].VIPsToRead && !TestAndSet(&(t->buf[t->front].firstIn))) t->buf[t->front].VIP->P();
    atom -> V();
    if((!t->isVIP()) && t->buf[t->front].VIPsToRead){
      t->buf[t->front].VIP->P();
      t->buf[t->front].VIP->V();
    }
    if(t->isVIP()) t->buf[t->front].access -> P();
    t->Consume();
    if(t->isVIP()) t->buf[t->front].access -> V();
    if(FetchAndAdd(&(t->buf[(t->front)].VIPsToRead), -1) == 1) {t->buf[t->front].VIP->V();}
    atom->P();
    if(!t->buf[(t->front)].toRead) { Consumer::lastFront = (t->front + 1)%BUFFERSIZE; atom->V(); t->buf[t->front].filled -> P(); t->buf[t->front].firstIn = false; empty->V(); }
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
