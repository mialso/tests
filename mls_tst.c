#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "mls_tst_error.h"

struct test_suite {
	char *module_name;
	char *interface;
	void (*run_test)(void);
};

#define MAX_SUITES 10
#define SUITE_PRINT_MES "suite %2d: \"%s\" <%s>\n"

// static data
struct {
	size_t num;
	struct test_suite *arr[MAX_SUITES];
} suites;

// interface definition


// static declarations
void clear_suites(void);
static inline void suites_data_check(void);
static void suites_for_each(void (*)(struct test_suite *, size_t));
static void suite_run_test(struct test_suite *suite, size_t num);
static void suite_print(struct test_suite *suite, size_t num);
static void suite_clear(struct test_suite *suite, size_t num);

void init_suite(char *module_name, char *interface, void (*test)(void))
{
	struct test_suite *suite = NULL;

	suites_data_check();

	// suite_create block
	suite = calloc(1, sizeof (struct test_suite));
	if (!suite) {
		internal_fatal_error(
			&module_err_data,
			SUITE_MEMORY_ERR,
			INIT_SUITE);
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
	/*
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
	*/
	suites_for_each(suite_run_test);
}
void print_suites(void)
{
	int print_suite = suites.num;
	
	// suites_empty decision
	if (!suites.num) {
		// suites_empty_print block
		printf("no suites_data available\n");
		return;
	}
	// suites_not_empty decision
	/*
	while (print_suite)
	{
		// suite_print block
		--print_suite;
		printf(SUITE_PRINT_MES,
			print_suite+1,
			suites.arr[print_suite]->module_name,
			suites.arr[print_suite]->interface);
	}
	*/
	suites_for_each(suite_print);
}
void clear_suites(void)
{
	/*
	while (suites.num)
	{
		--suites.num;
		if (suites.arr[suites.num]) {
			free(suites.arr[suites.num]);
		}
	}
	*/
	suites_for_each(suite_clear);
}
void suite_run_test(struct test_suite *suite, size_t num)
{
	if (suite->run_test) {
		suite->run_test();
	}
}
void suite_clear(struct test_suite *suite, size_t num)
{
	if (!suite) {
		return;
	}
	free(suite);
	if (!num) {
		suites.num = 0;
	}
}
void suite_print(struct test_suite *suite, size_t num)
{
	printf(SUITE_PRINT_MES,
		num+1,
		suite->module_name,
		suite->interface);
}
void suites_for_each(void (*doit)(struct test_suite *, size_t))
{
	size_t suites_num = suites.num;
	if (!suites_num) {
		return;
	}
	while (suites_num)
	{
		--suites_num;
		doit(suites.arr[suites_num], suites_num);
	}
}
void suites_data_check(void)
{
	// suites_number_check decision
	if (0 == suites.num) {
		// suites_init_cleanup handler
		atexit(clear_suites);
	}
	if (MAX_SUITES < suites.num) {
		// suites_max_value error block
		internal_fatal_error(
			&module_err_data,
			SUITES_LIMIT,
			INIT_SUITE);
	}
}
