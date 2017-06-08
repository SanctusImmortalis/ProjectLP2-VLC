#include "Producer.h"
#include <stdio.h>

void* producerCode(void* arg){
  Producer* t = (Producer*) arg;
  while(t->isActive()){
    getEmpty()->P();
    t->Produce();
    t->buf[t->rear].filled -> V();
    t->rear = (t->rear + 1) % BUFFERSIZE;
  }
  delete t;
}

void Producer::Produce(){
	fprintf(stderr, "Getting data\n");
  recvfrom(getSock(), &(buf[rear].data), PACKETSIZE, 0, NULL, NULL);

}
