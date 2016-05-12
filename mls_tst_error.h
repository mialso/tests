#ifndef _MLS_TST_ERROR_H
#define _MLS_TST_ERROR_H

#include "mls_error.h"

static char *error_descriptions[5] = {
	"max suites limit reached, change \"MAX_SUITES\" value to increase",
	"memory error while suite struct allocation"
};
static char *proc_names[5] = {
	"init_suite"
};
static struct module_error module_err_data = {
	.name = "mls_tst",
	.errors = error_descriptions,
	.procs = proc_names
};
enum module_error_num {
	SUITES_LIMIT,
	SUITE_MEMORY_ERR
};
enum module_proc_num {
	INIT_SUITE
};

#endif
