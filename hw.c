#include <stdio.h>

#include "hw.h"

int say_hello(char *greet, int len)
{
	int res;
	res = printf("hello, %s\n", greet);
	return res;
}
