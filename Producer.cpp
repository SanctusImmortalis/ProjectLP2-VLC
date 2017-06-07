#include "Producer.h"

void* producerCode(void* t){
  while(t->isActive()){
    empty->P();
    t->Produce();
    full->V();
  }
}

void Producer::Produce(){
  char temp[PACKETSIZE];
  recvfrom(sock, temp, PACKETSIZE, 0, NULL, NULL);
  rear = (rear + 1) % BUFFERSIZE;
}
