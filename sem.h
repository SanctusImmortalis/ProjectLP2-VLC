#ifndef SEMAPHORE_CUSTOM_H
#define SEMAPHORE_CUSTOM_H

#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>

class Semaphore{
public:
  Semaphore(int value);
  ~Semaphore();
  void P();
  void V();
private:
  sem_t sem;
};

#endif
