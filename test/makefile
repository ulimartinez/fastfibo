CC = gcc
INCLUDE = ..
#VPATH = ..
CFLAGS = -Wall -I$(INCLUDE)
HEADERS = bignum.h
OBJECTS = bigNumTst.o $(INCLUDE)/bignum.o
default: all
all: bigtest
bigtest: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
$(INCLUDE)/%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f bigtest
