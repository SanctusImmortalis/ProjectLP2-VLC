#include <string.h>

#include "Thread.h"

Thread::Thread(const char* ip, const char* port, Buffer* b){
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  inet_aton(ip, &(addr.sin_addr));
  addr.sin_port = htons(atoi(port));
  buf = b;
  active = true;
}

bool Thread::isActive(){
  return active;
}
