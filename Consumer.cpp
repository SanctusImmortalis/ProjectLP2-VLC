#include "Consumer.h"
#include <stdio.h>

int Consumer::VIPs = 0;
int Consumer::num = 0;
int Consumer::lastFront = 0;
bool Consumer::firstIn = false;
Semaphore* Consumer::VIPOnly = new Semaphore(1);
Semaphore* Consumer::access = new Semaphore(1);

void* consumerCode(void* arg){
  Consumer* t = (Consumer*) arg;
  if(t->isVIP()) {
    Consumer::access -> P();
    t->front = Consumer::lastFront;
    //if(!TestAndSet(&Consumer::firstIn)) Consumer::VIPOnly -> P();
  }
  while(t->isActive()){
    if(t->isVIP()){
      t->buf[t->front].filled -> P();
      t->Consume();
      t->front = (t->front + 1) % BUFFERSIZE;
      Consumer::lastFront = t->front;
      getEmpty()->V();
    }else{
      if(Consumer::VIPs){
        Consumer::VIPOnly -> P();
        t->front = Consumer::lastFront;
      }
      //getAtom()->P();
      if(!CompareAndSwap(&(t->buf[t->front].toRead), 0, 0)){
        //getAtom()->V();
        t->buf[t->front].filled -> P();
        //getAtom()->P();
      }else{
        getAtom()->P();
	t->buf[t->front].toRead--;
        if(!(t->buf[t->front].toRead)) {
		
		Consumer::lastFront = (t->front + 1) % BUFFERSIZE;
		
	}
	getAtom()->V();
        /*if(!TestAndSet(&(t->buf[t->front].inUse)))
          //t->buf[t->front].inUse = true;
          //getAtom()->V();
          t->buf[t->front].filled -> P();
          //getAtom()->P();
          */
      }
      //getAtom()->V();
      t->Consume();
      getAtom()->P();
      if(!(t->buf[t->front].toRead)){
        //Consumer::lastFront = (t->front + 1) % BUFFERSIZE;
        //t->buf[t->front].inUse = false;
        t->front = Consumer::lastFront;
    if(t->buf[t->front].toRead <= 1)
        	getEmpty()->V();
      }
      getAtom()->V();
    }
  }
  FetchAndAdd(&Consumer::num, -1);
  if(t->isVIP()) {
    if(FetchAndAdd(&(Consumer::VIPs), -1) == 1) {
      //Consumer::firstIn = false;
      for(int i = 0; i<=Consumer::num; i++) {Consumer::VIPOnly -> V();}
    }
    Consumer::access -> V();
  }
  delete t;
  return NULL;
}

void Consumer::Consume(){
  char* temp;
  temp = buf[front].data;
  if(VIP) fprintf(stderr, "High priority - Sending data\n");
	else fprintf(stderr, "Sending data\n");
  sendto(getSock(), temp, PACKETSIZE, 0, (sockaddr*) &addr, sizeof(addr));
}

bool Consumer::isVIP(){
  return VIP;
}
