#include <string.h>
#include <stdlib.h>

#include "Thread.h"

Thread::Thread(bool* result, const char* ip, const char* port, Buffer* b){
  memset(&(this->addr), 0, sizeof(this->addr));
  this->addr.sin_family = AF_INET;
  //this->addr.sin_addr.s_addr = INADDR_ANY;
  if(inet_aton(ip, &(this->addr.sin_addr))){
      this->addr.sin_port = htons(atoi(port));
      this->buf = b;
      this->active = true;
      *result = true;
  }else{
      *result = false;
      //delete this;
  }
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
