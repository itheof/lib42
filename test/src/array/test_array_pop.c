#include "header.h"

static t_array		array;

static void	test_00_array_pop_Int(void)
{
	int	data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	array_init(&array, sizeof(int));

	for (size_t i = 0; i < ARR_SIZ_MAX(data); ++i)
	{
		int	value = data[i];
		array_push(&array, &value);
		if (i < 8)
			v_assert_size_t(TARRAY_INIT_SIZE, ==, array.capacity);
		else
			v_assert_size_t(16, ==, array.capacity);
		v_assert_size_t(i + 1, ==, array.len);
		int	*res = array_get_at(&array, i);
		v_assert_int(value, ==, *res);
	}

	int popped;

	array_pop(&array, &popped);
	v_assert_int(10, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(9, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(8, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(7, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(6, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(5, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(4, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(3, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(2, ==, popped);

	array_pop(&array, &popped);
	v_assert_int(1, ==, popped);

	v_assert_ptr(NULL, ==, array_pop(&array, &popped));

	array_shutdown(&array);
	VTS;
}

static void	test_01_array_pop_whenEmpty(void)
{
	array_init(&array, 1);

	v_assert_ptr(NULL, ==, array_pop(&array, NULL));

	array_shutdown(&array);
}

void	suite_array_pop(void)
{
	test_00_array_pop_Int();
	test_01_array_pop_whenEmpty();

	VSS;
}
