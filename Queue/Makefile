CC=gcc

CFLAGS=-I.

ifdef capacity
CFLAGS+=-DQUEUE_CAPACITY=$(capacity)
else
CFLAGS+=-DQUEUE_CAPACITY=5
endif

DEPS = queue.h

all: unit_test

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

queue: queue.o
	@$(CC) -o $@ $^ $(CFLAGS)

unit_test: queue.o unit_test.o
	@$(CC) -o $@ $^ $(CFLAGS)

test: unit_test
	@./unit_test

clean:
	@rm -f *.o unit_test

doc:
	doxygen queue.h
