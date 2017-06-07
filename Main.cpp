#include "Buffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "Sync.h"

Buffer b[BUFFERSIZE];

int main(){
  initSync(b);
  Producer* prod = new Producer("127.0.0.1", "4000", b);
  Consumer* cons[5];

  cons[0] = new Consumer("127.0.0.1", "4500", b, false);
  cons[1] = new Consumer("127.0.0.1", "5000", b, false);
  cons[2] = new Consumer("127.0.0.1", "5500", b, true);
  cons[3] = new Consumer("127.0.0.1", "6000", b, false);
  cons[4] = new Consumer("127.0.0.1", "6500", b, true);
  prod->Join();

  exit 0;
}
