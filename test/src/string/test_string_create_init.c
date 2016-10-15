#include "header.h"

static t_string		string;

static void	teardown(void)
{
	free(string.str);
}

static void	test_00_string_init_SizeBelowMinimum(void)
{
	string_init_with_capacity(&string, 4);

	v_assert_size_t(STRING_INIT_SIZE, ==, string.capacity);

	teardown();
	VTS;
}

static void	test_01_string_init_SizeAboveMinimum(void)
{
	string_init_with_capacity(&string, 1111);

	v_assert_size_t(2048, ==, string.capacity);

	teardown();
	VTS;
}

static void	test_02_string_init_SizePowerOf2(void)
{
	string_init_with_capacity(&string, 256);

	v_assert_size_t(512, ==, string.capacity);

	teardown();
	VTS;
}

static void	test_03_string_init_SizeOfInit(void)
{
	string_init_with_capacity(&string, STRING_INIT_SIZE);

	v_assert_size_t(next_power_of_2(STRING_INIT_SIZE), ==, string.capacity);

	teardown();
	VTS;
}

static void	test_04_string_init_SizePowerOf2MinsOne(void)
{
	string_init_with_capacity(&string, 255);

	v_assert_size_t(256, ==, string.capacity);

	teardown();
	VTS;
}

void	suite_string_create_init(void)
{
	test_00_string_init_SizeBelowMinimum();
	test_01_string_init_SizeAboveMinimum();
	test_02_string_init_SizePowerOf2();
	test_03_string_init_SizeOfInit();
	test_04_string_init_SizePowerOf2MinsOne();

	VSS;
}
