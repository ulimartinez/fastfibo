CC = gcc
HEADERS = mt.h
OBJECTS = fibo.o
DEPS = fibo.c
default: all
all: fibo
fibo: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
%.o:%.c $(HEADERS)
	$(CC) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f fibo
