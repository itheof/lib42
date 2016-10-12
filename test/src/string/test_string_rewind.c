#include "header.h"

static t_string		string;

static void	setup(void)
{
	string_init(&string, 120);
	string_ncat(&string, "Hello World!", 12);
}

static void	teardown(void)
{
	free(string.str);
}

static void	test_00_string_rewind_SimpleSize(void)
{
	int res;
	setup();

	res = string_rewind(&string, 3);
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(9, ==, string.len);
	v_assert_str("Hello Wor", string.str);
	v_assert_int(9, ==, res);

	teardown();
	VTS;
}

static void	test_01_string_rewind_ZeroSize(void)
{
	int res;
	setup();

	res = string_rewind(&string, 0);
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(12, ==, string.len);
	v_assert_str("Hello World!", string.str);
	v_assert_int(12, ==, res);

	teardown();
	VTS;
}

static void	test_02_string_rewind_FullSize(void)
{
	int res;
	setup();

	res = string_rewind(&string, 12);
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(0, ==, string.len);
	v_assert_str("", string.str);
	v_assert_int(0, ==, res);

	teardown();
	VTS;
}

static void	test_03_string_rewind_SizeOverflow(void)
{
	int res;
	setup();

	res = string_rewind(&string, 42);
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(12, ==, string.len);
	v_assert_str("Hello World!", string.str);
	v_assert_int(-1, ==, res);

	teardown();
	VTS;
}

void	suite_string_rewind(void)
{
	test_00_string_rewind_SimpleSize();
	test_01_string_rewind_ZeroSize();
	test_02_string_rewind_FullSize();
	test_03_string_rewind_SizeOverflow();

	VSS;
}
