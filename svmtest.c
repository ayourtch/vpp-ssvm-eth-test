
#include <ssvm.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  ssvm_private_t ssvm;
  memset(&ssvm, 0, sizeof(ssvm));
  ssvm.ssvm_size = 1024;
  ssvm.i_am_master = 1;
  ssvm.name = "ayourtch-test";
  ssvm.my_pid = getpid();
  int res = ssvm_master_init(&ssvm, 42);
  printf("Init result: %d\n", res);
  while (1) {
    sleep(1);
  
  }
  
  // ssvm_master_init
}

