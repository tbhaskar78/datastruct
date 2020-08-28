CC = gcc
CFLAGS = -Wall -g -o
all: stklist stkarray

stkarray: stkarray.c
	$(CC) $(CFLAGS) $@ $<
	
stklist: stkllist.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f stkarray stklist *.o
