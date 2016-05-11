#include <stdio.h>
#include "mls_tst.h"

#define MODULE_NAME "hw"
#define NONULLHERE 0

#ifndef NULL
#define NULL (void *)0
#define NONULLHERE 1
#endif

// interface tests
void test_say_hello(void);
void test_test(void);

int main(void)
{
	if (NONULLHERE) {
		printf("NULL is not defined!!!\n");
	}
		
	print_suites();
	init_suite(MODULE_NAME, "say_hello", test_say_hello);
	print_suites();
	init_suite(MODULE_NAME, "say_goodbuy", NULL);
	print_suites();
	init_suite(MODULE_NAME, "stop_talking", test_test);
	print_suites();
	execute_tests();
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);
	init_suite(MODULE_NAME, "stop_talking", test_test);

	return 0;
}

void test_say_hello(void)
{
	printf("im testing \"say_hello\"\n");
}
void test_test(void)
{
	printf("im testing \"test\"\n");
}
