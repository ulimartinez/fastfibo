CC = gcc
HEADERS = mt.h bignum.h
OBJECTS = fibo.o bignum.o
default: all
all: fibo
fibo: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
%.o:%.c $(HEADERS)
	$(CC) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f fibo
bigtest: bigNumTst.o bignum.o
	$(CC) $^ -o $@
bigNumTst.o: bigNumTst.c bignum.h
	$(CC) -c $< -o $@
bignum.o: bignum.c bignum.h
	$(CC) -c $< -o $@
