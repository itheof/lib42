#include "header.h"

static t_string	*string;

static void	teardown(void)
{
	free(TBUFFER_GET(string));
	free(string);
}

static void	test_00_string_new_SizeBelowMinimum(void)
{
	string = string_new(4);

	v_assert_size_t(STRING_INIT_SIZE, ==, TBUFFER_MAX(string));

	teardown();
	VTS;
}

static void	test_01_string_new_SizeAboveMinimum(void)
{
	string = string_new(1111);

	v_assert_size_t(2048, ==, TBUFFER_MAX(string));

	teardown();
	VTS;
}

static void	test_02_string_new_SizePowerOf2(void)
{
	string = string_new(256);

	v_assert_size_t(512, ==, TBUFFER_MAX(string));

	teardown();
	VTS;
}

static void	test_03_string_new_SizeOfInit(void)
{
	string = string_new(STRING_INIT_SIZE);

	v_assert_size_t(STRING_INIT_SIZE * 2, ==, TBUFFER_MAX(string));

	teardown();
	VTS;
}

static void	test_04_string_new_SizePowerOf2MinsOne(void)
{
	string = string_new(255);

	v_assert_size_t(256, ==, TBUFFER_MAX(string));

	teardown();
	VTS;
}

void	suite_string_new(void)
{
	test_00_string_new_SizeBelowMinimum();
	test_01_string_new_SizeAboveMinimum();
	test_02_string_new_SizePowerOf2();
	test_03_string_new_SizeOfInit();
	test_04_string_new_SizePowerOf2MinsOne();

	VSS;
}
