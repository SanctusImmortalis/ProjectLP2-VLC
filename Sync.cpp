#include "Sync.h"
#include "Error.h"


void initSync(int n){
  atom = new Semaphore(1);
  full = new Semaphore(0);
  empty = new Semaphore(n);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock<0) error("Socket error\n", -1);
}


int FetchAndAdd(int* ptr, int val){
  atom->P();
  int aux = *ptr;
  *ptr = aux + val;
  atom->V();
  return aux;
}
