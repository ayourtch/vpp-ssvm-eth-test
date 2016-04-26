// #include <x86intrin.h>

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ssvm.h>


// vlib_main_t vlib_global_main;




int main(int argc, char *argv[]) {
  uword main_heap_size = (1ULL << 30);
  unformat_input_t input;

  clib_mem_init(0, main_heap_size);
  unformat_init_command_line (&input, (char **)argv);
  ssvm_eth_init();
  ssvm_config(NULL, &input);
  unformat_free (&input);


  int count = 0;
  char tmpbuf[100];

  ssvm_eth_print_config();

  while (1) {
    sleep(1);
    u16 cnt = ssvm_eth_input_node_fn();
    printf("Received: %d packets\n", cnt);
    if (argc > 1) {
      printf("I am slave\n");
      sprintf(tmpbuf, "Counter value: %d", count++);
      run_interface_tx(tmpbuf, 100);
    }
  }
}

