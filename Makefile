svmtest: svmtest.c
	gcc -c svmtest.c
	gcc -o svmtest svmtest.o -lsvm -lvppinfra -lpthread -lrt
