CFLAGS := -O0 -g -DDPDK=1 -I/usr/include/vpp-dpdk
svmtest: svmtest.c ssvm_eth.c node.c
	gcc ${CFLAGS} -c svmtest.c
	gcc ${CFLAGS} -c ssvm_eth.c
	gcc ${CFLAGS} -g -c node.c
	gcc ${CFLAGS} -g -o svmtest svmtest.o node.o ssvm_eth.o -lsvm -lvppinfra -lpthread -lrt -lvlibmemory -lvlibapi -lvlib_unix -ldl -lvlib
clean:
	rm -f svmtest *.o
