#include "Consumer.h"
#include <stdio.h>

int Consumer::VIPs = 0;
int Consumer::num = 0;
int Consumer::lastFront = 0;

void* consumerCode(void* arg){
  Consumer* t = (Consumer*) arg;
  while(t->isActive()){
    t->buf[t->front].filled -> P();
    t->buf[t->front].filled -> V();
    CompareAndSwap(&(t->buf[t->front].toRead), 0, Consumer::num);
    CompareAndSwap(&(t->buf[t->front].VIPsToRead), 0, Consumer::VIPs);
    getAtom() -> P();
    if(t->buf[t->front].VIPsToRead && !(t->buf[t->front].firstIn)) t->buf[t->front].VIP->P(); t->buf[t->front].firstIn = true;
    getAtom() -> V();
    if((!t->isVIP()) && t->buf[t->front].VIPsToRead){
      t->buf[t->front].VIP->P();
      t->buf[t->front].VIP->V();
    }
    if(t->isVIP()) t->buf[t->front].access -> P();
    t->Consume();
    if(t->isVIP()) {t->buf[t->front].access -> V();
    if(FetchAndAdd(&(t->buf[(t->front)].VIPsToRead), -1) == 1) {t->buf[t->front].VIP->V();}}
    getAtom()->P();
    t->buf[(t->front)].toRead--;
    if(!(t->buf[(t->front)].toRead)) { Consumer::lastFront = (t->front + 1)%BUFFERSIZE; t->buf[t->front].filled -> P(); t->buf[t->front].firstIn = false; getEmpty()->V(); }
    getAtom()->V();
    t->front = (t->front + 1) % BUFFERSIZE;
  }
  delete t;
}

void Consumer::Consume(){
  char* temp;
  temp = buf[front].data;
	fprintf(stderr, "Sending data\n");
  sendto(getSock(), temp, PACKETSIZE, 0, (sockaddr*) &addr, sizeof(addr));
}

bool Consumer::isVIP(){
  return VIP;
}
