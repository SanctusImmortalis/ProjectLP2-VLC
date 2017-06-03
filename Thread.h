#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <sched.h>
#include <sys/types>

class Thread {
private:
  pthread_t threadID;
  unsigned char asleep;
  unsigned char running;
public:
  Thread(void* (*startroutine) (void*), void* arg);
  ~Thread();
  int join(void** value);
  void sleep();
  void awake();
};

#endif
