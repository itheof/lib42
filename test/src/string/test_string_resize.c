#include "header.h"

static t_string		string;

static void	teardown(void)
{
	free(string.str);
}

static void	test_00_string_resize_ExpandNotMuch(void)
{
	string_init(&string, 4);
	v_assert_size_t(STRING_INIT_SIZE, ==, string.capacity);

	priv_string_resize(&string, 7);
	v_assert_size_t(STRING_INIT_SIZE * 2, ==, string.capacity);

	teardown();
	VTS;
}

static void	test_01_string_resize_ExpandMoreThan2(void)
{
	string_init(&string, 1111);
	v_assert_size_t(2048, ==, string.capacity);

	priv_string_resize(&string, 5555);
	v_assert_size_t(8192, ==, string.capacity);

	teardown();
	VTS;
}

static void	test_02_string_resize_ExpandPowerOf2(void)
{
	string_init(&string, 256);
	v_assert_size_t(512, ==, string.capacity);

	priv_string_resize(&string, 256);
	v_assert_size_t(1024, ==, string.capacity);

	teardown();
	VTS;
}

void	suite_string_resize(void)
{
	test_00_string_resize_ExpandNotMuch();
	test_01_string_resize_ExpandMoreThan2();
	test_02_string_resize_ExpandPowerOf2();

	VSS;
}
