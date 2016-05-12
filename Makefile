DBG_FLAGS=-std=c11 -g -Wall -Wextra -Wpedantic

srcs=hw.c hw_test.c mls_tst.c mls_error.c

all: out
	@if [ -f a.out ]; then ./a.out; rm a.out; fi
out:
	$(CC) $(DBG_FLAGS) $(srcs) 
