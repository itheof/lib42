#include "header.h"

static int g_test_getopt_diagnostic = 0;

static void reset_getopt_vars(t_opt *state)
{
	optarg = NULL;
	opterr = g_test_getopt_diagnostic;
	optind = 1;
	optopt = 0;
	state->optind = 1;
	state->opterr = g_test_getopt_diagnostic;
	state->optarg = NULL;
	state->optopt = 0;
	state->optoff = 0;
}

static void panic_syscall_failed(void)
{
	perror("test panic");
	exit(1);
}

static int	getopt_stderr_wrap(int argc, char *const argv[], const char *optstring, t_opt *state, int fd)
{
	int stderr_save;
	int ret;

	if ((stderr_save = dup(2)) < 0)
		panic_syscall_failed();

	if (dup2(fd, 2) < 0)
		panic_syscall_failed();

	if (!state)
		ret = getopt(argc, argv, optstring);
	else
		ret = ft_getopt(argc, argv, optstring, state);

	if (close(2) < 0 || close(fd) < 0)
		panic_syscall_failed();
	if (dup2(stderr_save, 2) < 0)
		panic_syscall_failed();
	if (close(stderr_save) < 0)
		panic_syscall_failed();
	return (ret);
}

static void assert_silent_getopt_values(int argc, char *const argv[], const char *optstring)
{
	t_opt	state;
	int		ret_ref;
	int		ret;
	int		filedes[2][2];
	char	buf_ref[512];
	char	buf[512];
	pid_t	son_pid;
	int		status;

	son_pid = fork();
	if (!son_pid)
	{
		reset_getopt_vars(&state);
		ret_ref = 0;

		while (ret_ref != -1) {

			if (pipe(filedes[0]) < 0 || pipe(filedes[1]) < 0)
				panic_syscall_failed();

			ret_ref = getopt_stderr_wrap(argc, argv, optstring, NULL, filedes[0][1]);
			ret = getopt_stderr_wrap(argc, argv, optstring, &state, filedes[1][1]);

			memset(buf, 0, 512);
			memset(buf_ref, 0, 512);
			if (read(filedes[0][0], buf_ref, 511) < 0 || read(filedes[1][0], buf, 511) < 0 || close(filedes[0][0]) < 0 || close(filedes[1][0]))
				panic_syscall_failed();
			v_assert_char(ret_ref, ==, ret);
			if (ret_ref == -1)
				break;
			v_assert_char(optind, ==, state.optind);
			v_assert_int(opterr, ==, state.opterr);
			if (ret_ref == '?' || ret_ref == ':')
//			{
				v_assert_char(optopt, ==, state.optopt);
//				if (g_test_getopt_diagnostic)
					v_assert_str(buf_ref, buf);
//			}
			v_assert_ptr(optarg, ==,state.optarg);

		}
		exit(0);
	}
	else if (son_pid > 0)
	{
		wait(&status);
		if (status){
			exit(1);
		}
	}
	else
		panic_syscall_failed();
}

static void assert_getopt_diagnostics(int argc, char *const argv[], const char *optstring)
{
	g_test_getopt_diagnostic = 1;
	assert_silent_getopt_values(argc, argv, optstring);
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
	assert_getopt_diagnostics(
		2, (char*[])
		{"./test", "-F", NULL},
		"a"
	);
	assert_getopt_diagnostics(
		2, (char*[])
		{"./test", "-aF", NULL},
		"a"
	);
	assert_getopt_diagnostics(
		3, (char*[])
		{"./test", "-a", "-Fa", NULL},
		"a"
	);
	assert_getopt_diagnostics(
		3, (char*[])
		{"./test", "-Fa", "-b", NULL},
		"ab"
	);
	assert_getopt_diagnostics(
		4, (char*[])
		{"./test", "-a", "--", "-Fa", NULL},
		"a"
	);

	VTS;
}

static void test_09_error_missing_operand(void)
{
	assert_getopt_diagnostics(
		2, (char*[])
		{"./test", "-ab", NULL},
		"ab:"
	);

	assert_getopt_diagnostics(
		2, (char*[])
		{"./test", "-ab", NULL},
		":ab:"
	);

	assert_getopt_diagnostics(
		3, (char*[])
		{"./test", "-a", "-b", NULL},
		"ab:"
	);

	assert_getopt_diagnostics(
		3, (char*[])
		{"./test", "-a", "-b", NULL},
		":ab:"
	);

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
