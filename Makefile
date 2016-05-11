CFLAGS=-std=c11 -g -Wall -Wextra -Wpedantic

srcs=hw.c hw_test.c mls_tst.c mls_error.c

all:
	$(CC) $(CFLAGS) $(srcs);
