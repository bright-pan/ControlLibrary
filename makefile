# C compiler
CC = gcc
# preprocessor flags
CPPFLAGS = -I./mylib/include
# compiler flags
CFLAGS = -g -Wall
# linker flags
LDFLAGS = -L./mylib/lib
# linked libraries
LDLIBS = -lmylib
# LOADLIBES is a deprecated and badly spelled alternative to LDLIBS
# target architecture
TARGET_ARCH = -march=native
# remove object files from project folder
RM = rm -f

run: test_bench
	./test_bench

test_bench: test_bench.o control.o

# implicit rules
%: %.o
	$(CC) $(CFLAGS) $(TARGET_ARCH) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(TARGET_ARCH) -c -o $@ $<

.PHONY: run clean

clean:
	$(RM) *.o test_bench
