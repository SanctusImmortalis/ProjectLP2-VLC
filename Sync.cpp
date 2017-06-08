#include "Sync.h"
#include "Error.h"
#include "Buffer.h"


int sock;

Semaphore* empty, * atom;

int getSock(){
  return sock;
}

Semaphore* getEmpty(){
  return empty;
}

Semaphore* getAtom(){
  return atom;
}

void initSync(Buffer b[]){
  atom = new Semaphore(1);
  empty = new Semaphore(BUFFERSIZE);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock<0) error("Socket error\n", -1);

  for(int i=0;i<BUFFERSIZE;i++){
    //b[i].VIP = new Semaphore(1);
    //b[i].access = new Semaphore(1);
    b[i].filled = new Semaphore(0);
    b[i].toRead = 0;
    //b[i].VIPsToRead = 0;
    //b[i].firstIn = false;
    //b[i].inUse = false;
  }
}

int FetchAndAdd(int* ptr, int val){
  atom->P();
  int aux = *ptr;
  *ptr = aux + val;
  atom->V();
  return aux;
}

int CompareAndSwap(int* ptr, int old, int nu){
  atom->P();
  int aux = *ptr;
  if(old==aux){
    *ptr = nu;
  }
  atom->V();
  return aux;
}

bool TestAndSet(bool* ptr){
  atom->P();
  bool aux = *ptr;
  *ptr = true;
  atom->V();
  return aux;
}
