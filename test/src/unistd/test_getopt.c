#include "header.h"

static int g_test_getopt_err_ref = 0;
static int g_test_getopt_err = 0;
static int g_test_getopt_diagnostic = 0;

static void reset_getopt_gvars(void)
{
	optarg = NULL;
	opterr = g_test_getopt_err_ref;
	optind = 1;
	optopt = 0;
}

static void assert_silent_getopt_values(int argc, char *const argv[], const char *optstring)
{
	t_opt	state;
	int		ret_ref;
	int		ret;

	state.optind = 1;
	state.opterr = g_test_getopt_err;
	state.optarg = NULL;
	state.optopt = 0;
	state.optoff = 0;

	reset_getopt_gvars();
	ret_ref = 0;

	while (ret_ref != -1) {
		ret_ref = getopt(argc, argv, optstring);
		ret = ft_getopt(argc, argv, optstring, &state);

		v_assert_char(ret_ref, ==, ret);
		if (ret_ref == -1)
			break;
		v_assert_char(optind, ==, state.optind);
		v_assert_int(opterr, ==, state.opterr);
		v_assert_char(optopt, ==, state.optopt);
		v_assert_ptr(optarg, ==,state.optarg);
	}
}

static void panic_syscall_failed(void)
{
	perror("test PANIC");
	exit(1);
}

static void assert_getopt_diagnostics(int argc, char *const argv[], const char *optstring)
{
	int filedes[2][2];
	char buf1[512];
	char buf2[512];

	if (pipe(filedes[0]) < 0 && pipe(filedes[1]) < 0)
		panic_syscall_failed();

	g_test_getopt_diagnostic = 1;
	g_test_getopt_err_ref = filedes[0][1];
	g_test_getopt_err = filedes[1][1];

	assert_silent_getopt_values(argc, argv, optstring);
	close(filedes[0][1]);
	close(filedes[1][1]);

	buf1[511] = 0;
	buf2[511] = 0;
	if (read(filedes[0][0], buf1, 511) < 0 || read(filedes[1][0], buf2, 511) < 0)
		panic_syscall_failed();

	printf("salut !!: %s\n", buf1);
	printf("salut !!: %s\n", buf2);
	close(filedes[0][0]);
	close(filedes[1][0]);
	v_assert_str(buf1, buf2);
	g_test_getopt_err_ref = 0;
	g_test_getopt_err = 0;
	g_test_getopt_diagnostic = 0;
}

static void test_00_no_opts(void)
{
	assert_silent_getopt_values(
		2, (char*[])
		{"./test", "hahahaaha", NULL},
		":a"
	);
	assert_silent_getopt_values(
		2, (char*[])
		{"./test", "hahahaaha", NULL},
		":a:"
	);

	VTS;
}

static void test_01_empty_optstring(void)
{
	assert_silent_getopt_values(
		2, (char*[])
		{"./test", "coucou", NULL},
		""
	);
	assert_silent_getopt_values(
		2, (char*[])
		{"./test", "coucou", NULL},
		":"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a", "coucou", NULL},
		""
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a", "coucou", NULL},
		":"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-ab", "coucou", NULL},
		""
	);

	VTS;
}

static void test_02_one_simple_opt(void)
{
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a", "coucou", NULL},
		":abA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-A", "coucou", NULL},
		":abA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a", "coucou", NULL},
		"abA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a", "coucou", NULL},
		":abA"
	);

	VTS;
}

static void test_03_multiple_simple_opts(void)
{
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-a", "-b", "coucou", NULL},
		"abA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-ab", "coucou", NULL},
		"abA"
	);
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-ab", "-a", "coucou", NULL},
		"abA"
	);
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-ba", "-a", "coucou", NULL},
		"abA"
	);

	VTS;
}

static void test_04_one_operand_opt(void)
{
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-a", "-a", "coucou", NULL},
		"a:bA"
	);
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-a", "-a", "coucou", NULL},
		":a:bA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a-a", "coucou", NULL},
		"a:bA"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-a-a", "coucou", NULL},
		":a:bA"
	);
	assert_silent_getopt_values(
		4, (char*[])
		{"./test", "-a", "--", "coucou", NULL},
		":bAa:"
	);

	VTS;
}

static void test_05_multiple_operand_opts(void)
{
	assert_silent_getopt_values(
		5, (char*[])
		{"./test", "-a", "--", "-A","coucou", NULL},
		":bA:a:"
	);
	assert_silent_getopt_values(
		5, (char*[])
		{"./test", "-a", "--", "-A","coucou", NULL},
		"bA:a:"
	);

	VTS;
}

static void test_06_multiple_different_opts(void)
{
	assert_silent_getopt_values(
		7, (char*[])
		{"./test", "-a", "-ab", "-habc", "-t", "chose", "arg", NULL},
		":abh:t:"
	);
	assert_silent_getopt_values(
		7, (char*[])
		{"./test", "-a", "-ab", "-habc", "-t", "chose", "arg", NULL},
		"abh:t:"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-abhtruc", "arg", NULL},
		":abh:t:"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-abhtruc", "arg", NULL},
		"abh:t:"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-abh", "operand", NULL},
		":abh:t:"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-abh", "operand", NULL},
		"abh:t:"
	);

	VTS;
}

static void test_07_double_dash_spec(void)
{
	assert_silent_getopt_values(
		6, (char*[])
		{"./test", "-abh", "--", "--", "-arg", "arg", NULL},
		"abh:t:"
	);
	assert_silent_getopt_values(
		6, (char*[])
		{"./test", "-ab", "-------", "--", "-arg", "arg", NULL},
		"abh:t:"
	);
	assert_silent_getopt_values(
		6, (char*[])
		{"./test", "-ab", "--", "--", "-arg", "arg", NULL},
		"abh:t:"
	);

	VTS;
}

static void test_08_error_bad_opt(void)
{
/*	assert_getopt_diagnostics(
		2, (char*[])
		{"./test", "-F", NULL},
		"a"
	);*/

	VTS;
}

static void test_09_error_missing_operand(void)
{

	VTS;
}

static void test_10_unspecified_optstring_chars(void)
{
	assert_silent_getopt_values(
		5, (char*[])
		{"./test", "--", "- ", "-	", "-\n", "arg", NULL},
		"-	 \n"
	);

	VTS;
}

static void test_11_doubles_in_optstring(void)
{
	assert_silent_getopt_values(
		6, (char*[])
		{"./test", "-aa", "--", "--", "-arg", "arg", NULL},
		"abah:t:"
	);
	assert_silent_getopt_values(
		6, (char*[])
		{"./test", "-aa", "--", "--", "-arg", "arg", NULL},
		":abah:t:"
	);

	VTS;
}

static void test_12_doubles_in_opts(void)
{
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-Ilib/include", "-I./include", NULL},
		"I:"
	);
	assert_silent_getopt_values(
		3, (char*[])
		{"./test", "-Ilib/include", "-I./include", NULL},
		":I:"
	);

	VTS;
}

void suite_unistd_getopt(void)
{
	test_00_no_opts();
	test_01_empty_optstring();
	test_02_one_simple_opt();
	test_03_multiple_simple_opts();
	test_04_one_operand_opt();
	test_05_multiple_operand_opts();
	test_06_multiple_different_opts();
	test_07_double_dash_spec();
	test_08_error_bad_opt();
	test_09_error_missing_operand();
	test_10_unspecified_optstring_chars();
	test_11_doubles_in_optstring();
	test_12_doubles_in_opts();

	VSS;
}
