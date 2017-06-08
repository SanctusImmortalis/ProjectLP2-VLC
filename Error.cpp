#include <unistd.h>
#include "Error.h"

void error(const char* msg, int code){
  perror(msg);
  _exit(code);
}
