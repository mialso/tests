#ifndef _MLS_TST_H
#define _MLS_TST_H

/*
struct test_suite {
	char *module_name;
	char *interface;
};
*/

extern void init_suite(char *module_name, char *interface, void (*test)(void));
extern void print_suites(void);
extern void execute_tests(void);

#endif
