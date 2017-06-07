#include "sem.h"

Semaphore::Semaphore(int value){
  sem_init(&sem, 0, value-1);
}

Semaphore::~Semaphore(){
  sem_destroy(&sem);
}

void Semaphore::P(){
  sem_wait(&sem);
}

void Semaphore::V(){
  sem_post(&sem);
}
