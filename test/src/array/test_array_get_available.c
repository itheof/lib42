#include "header.h"

static void	test_00_array_get_available_Simple(void)
{
	t_array		array;
	int			*avlbl;

	array_init(&array, sizeof(int));

	avlbl = array_get_available(&array);
	v_assert_ptr(NULL, !=, avlbl);

	*avlbl = 42;

	v_assert_int(42, ==, *(int *)array_get_at(&array, 0));

	array_shutdown(&array);
	VTS;
}

static void	test_00_array_get_available_Realloc(void)
{
	t_array		array;
	int			*avlbl;

	array_init(&array, sizeof(int));

	for (size_t i = 0; i < array.capacity - 1; ++i)
	{
		int n = 21;
		v_assert_ptr(NULL, !=, array_push(&array, &n));
	}

	v_assert_size_t(ARRAY_INIT_SIZE, ==, array.capacity);

	avlbl = array_get_available(&array);
	v_assert_ptr(NULL, !=, avlbl);

	v_assert_size_t(ARRAY_INIT_SIZE, ==, array.capacity);

	avlbl = array_get_available(&array);
	v_assert_ptr(NULL, !=, avlbl);

	v_assert_size_t(ARRAY_INIT_SIZE * 2, ==, array.capacity);

	array_shutdown(&array);
	VTS;
}

void	suite_array_get_available(void)
{
	test_00_array_get_available_Simple();
	test_00_array_get_available_Realloc();

	VSS;
}
