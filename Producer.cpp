#include "Producer.h"
#include "Consumer.h"
#include <stdio.h>

int Producer::rear = 0;

void* producerCode(void* arg){
  Producer* t = (Producer*) arg;
  while(t->isActive()){
    getEmpty()->P();
    t->Produce();
    getAtom()->P();
    t->buf[Producer::rear].toRead = Consumer::num;
    getAtom()->V();
    t->buf[Producer::rear].filled -> V();
    Producer::rear = (Producer::rear + 1) % BUFFERSIZE;
  }
  delete t;
  return NULL;
}

void Producer::Produce(){
	fprintf(stderr, "Getting data\n");
  recvfrom(sock, &(buf[Producer::rear].data), PACKETSIZE, 0, NULL, NULL);

}
