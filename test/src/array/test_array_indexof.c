#include "header.h"

static t_array	array;
static int		tab[7] = {
	1, 2, 3, 4, 5, 6, 7
};

static void	setup(void)
{
	array_init(&array, 8, sizeof(int));
	for (size_t i = 0; i < ARR_SIZ_MAX(tab); ++i)
		array_push(&array, tab + i);
}

static void	teardown(void)
{
	free(array.data);
}

void	test_00_array_indexof_CheckAllValue(void)
{
	setup();

	v_assert_size_t(8, ==, array.capacity);

	for (size_t i = 0; i < 7; ++i)
	{
		int	*value = array_get_at(&array, i);
		int	index = array_indexof(&array, value);
		v_assert_int(i, ==, index);
	}

	// Last index
	int	*value = array_get_at(&array, array.len);
	int	index = array_indexof(&array, value);
	v_assert_int(-1, ==, index);

	teardown();
	VTS;
}

void	test_01_array_indexof_NotInArray(void)
{
	setup();

	int value;
	int	index = array_indexof(&array, &value);
	v_assert_size_t(8, ==, array.capacity);
	v_assert_int(-1, ==, index);

	teardown();
	VTS;
}

void	suite_array_indexof(void)
{
	test_00_array_indexof_CheckAllValue();
	test_01_array_indexof_NotInArray();

	VSS;
}
