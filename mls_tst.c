#include <stdio.h>
#include <stdlib.h>
#include "mls_tst_error.h"

struct test_suite {
	char *module_name;
	char *interface;
	void (*run_test)(void);
};

#define MAX_SUITES 10

// static data
struct {
	int num;
	struct test_suite *arr[MAX_SUITES];
} suites;

// interface definition


// static declarations
void clear_suites(void);
static inline void suites_data_check(void);

void init_suite(char *module_name, char *interface, void (*test)(void))
{
	suites_data_check();
	// suite_create block
	struct test_suite *suite = calloc(1, sizeof (struct test_suite));

	// suite_create_fail external decision
	if (!suite) {
		internal_fatal_error(
			&module_err_data,
			SUITE_MEMORY_ERR,
			INIT_SUITE);
		/*
		fprintf(stderr, "[ERROR]: <mls_tst>: init_suite(): memory error\n");
		exit(EXIT_FAILURE);
		*/
	}

	// suite_add_data block
	suite->module_name = module_name;
	suite->interface = interface;
	suite->run_test = test;

	// suites_add_suite block
	suites.arr[suites.num] = suite;
	++suites.num;
}
void execute_tests(void)
{
	// local_data init
	int suite_to_test = suites.num;
	void (*run_test)(void);
	// suites_empty decision
	if (!suites.num) {
		return;
	}
	// suites_not_empty decision
	while (suite_to_test)
	{
		// suite_test_execute block
		--suite_to_test;
		if ((run_test = suites.arr[suite_to_test]->run_test)) {
			run_test();
		}
	}
}
void print_suites(void)
{
	int print_suite = suites.num;
	// suites_empty decision
	if (!suites.num) {
		// suites_empty print block
		printf("no suites_data available\n");
		return;
	}
	// suites_not_empty decision
	while (print_suite)
	{
		// suite_print block
		--print_suite;
		printf("suite %d: \"%s\" <%s>\n",
			print_suite+1,
			suites.arr[print_suite]->module_name,
			suites.arr[print_suite]->interface);
	}
}
void clear_suites(void)
{
	while (suites.num)
	{
		--suites.num;
		if (suites.arr[suites.num]) {
			free(suites.arr[suites.num]);
		}
	}
}
void suites_data_check(void)
{
	// suites_number out of bounds decision
	if (suites.num <= 0 || MAX_SUITES < suites.num) {
		// suites_init_cleanup decision
		if (0 == suites.num) {
			// suites_init_cleanup handler
			atexit(clear_suites);
		}
		else if (MAX_SUITES < suites.num) {
			// suites_max_value error block
			internal_fatal_error(
				&module_err_data,
				SUITES_LIMIT,
				INIT_SUITE);
		}
		else {
			// suites_check error block
			internal_fatal_error(
				&module_err_data,
				SUITES_COUNTER_ERROR,
				INIT_SUITE);
		}
	}
}
