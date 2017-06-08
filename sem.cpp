#include "sem.h"
#include <stdio.h>

Semaphore::Semaphore(int value){
  sem_init(&sem, 0, value);
}

Semaphore::~Semaphore(){
  sem_destroy(&sem);
}

void Semaphore::P(){
  //int aux;
  //sem_getvalue(&sem, &aux);
  //fprintf(stderr, "P op %d thread id: %lx\n", aux, pthread_self());
  sem_wait(&sem);
}

void Semaphore::V(){
  //int aux;
  //sem_getvalue(&sem, &aux);
  //fprintf(stderr, "V op %d thread id: %lx\n", aux, pthread_self());
  sem_post(&sem);
}
