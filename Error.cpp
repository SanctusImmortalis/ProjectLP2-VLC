#include "Error.h"

void error(const char* msg, int code){
  perror(msg);
  exit(code);
}
