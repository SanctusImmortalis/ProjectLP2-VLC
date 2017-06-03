#include "Thread.h"

Thread::Thread(void* (*startroutine) (void*), void* arg){
  if(!pthread_create(&threadID, NULL, startroutine, arg)){
    asleep = 0;
    running = 1;
  }else{
    running = 0;
  }
}

Thread::~Thread(){
  pthread_cancel(threadID);
}

int Thread::join(void** value){
  return pthread_join(threadID, value);
}

void Thread::sleep(){

}

void Thread::awake(){

}
