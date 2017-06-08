#include <string.h>
#include <stdlib.h>

#include "Thread.h"

Thread::Thread(const char* ip, const char* port, Buffer* b){
  memset(&(this->addr), 0, sizeof(this->addr));
  this->addr.sin_family = AF_INET;
this->addr.sin_addr.s_addr = INADDR_ANY;
  //this->addr.sin_addr.s_addr = inet_addr(ip);
  this->addr.sin_port = htons(atoi(port));
  this->buf = b;
  this->active = true;
}

void Thread::Join(){
  pthread_join(this->t, NULL);
}

bool Thread::isActive(){
  return this->active;
}

void Thread::deactivate(){
  this->active = false;
}
