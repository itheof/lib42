#include "header.h"

static t_array	*v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
	"string",
	"padding",
	"enable",
};

static void	setup(void)
{
	v = array_new(8, sizeof(char*));
	for (size_t i = 0; i < ARR_SIZ_MAX(str); ++i)
	{
		array_push(v, &str[i]);
	}
}

static void	teardown(void)
{
	free(v->data);
	memset(v, 0, sizeof(t_array));
	free(v);
}

static void	test_00_array_remove_FirstItem(void)
{
	void	*ptr;
	char	*old;
	char	*value;
	size_t	index;

	setup();
	v_assert_size_t(ARR_SIZ_MAX(str), ==, v->count);

	index = 0;
	ptr = array_remove(v, index, &old);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(&old, ==, ptr);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		v_assert_ptr(str[i + 1], ==, value);
		v_assert_str(str[i + 1], value);
	}

	// last, unassigned
	v_assert_ptr(NULL, ==, array_get(v, 7));
	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

static void	test_01_array_remove_MiddleItem(void)
{
	void	*ptr;
	char	*old;
	char	*value;
	size_t	index;

	setup();
	v_assert_size_t(ARR_SIZ_MAX(str), ==, v->count);

	index = v->count / 2;
	ptr = array_remove(v, index, &old);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(&old, ==, ptr);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		if (i < index)
		{
			v_assert_ptr(str[i], ==, value);
			v_assert_str(str[i], value);
		}
		else
		{
			v_assert_ptr(str[i + 1], ==, value);
			v_assert_str(str[i + 1], value);
		}
	}

	// last, unassigned
	v_assert_ptr(NULL, ==, array_get(v, 7));
	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

static void	test_02_array_remove_LastItem(void)
{
	void	*ptr;
	char	*old;
	char	*value;
	size_t	index;

	setup();
	v_assert_size_t(ARR_SIZ_MAX(str), ==, v->count);

	index = v->count - 1;
	ptr = array_remove(v, index, &old);

	// Check return value
	v_assert_ptr(NULL, !=, ptr);
	v_assert_ptr(&old, ==, ptr);
	v_assert_ptr(str[index], ==, old);
	v_assert_str(str[index], old);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str) - 1, ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		if (i < index)
		{
			v_assert_ptr(str[i], ==, value);
			v_assert_str(str[i], value);
		}
		else
		{
			v_assert_ptr(str[i + 1], ==, value);
			v_assert_str(str[i + 1], value);
		}
	}

	// last, unassigned
	v_assert_ptr(NULL, ==, array_get(v, 7));
	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

static void	test_03_array_remove_OutOfRange(void)
{
	void	*ptr;
	char	*old;
	char	*value;
	size_t	index;

	setup();
	v_assert_size_t(ARR_SIZ_MAX(str), ==, v->count);

	index = v->count;
	ptr = array_remove(v, index, &old);

	// Check return value
	v_assert_ptr(NULL, ==, ptr);

	// Check array integrity
	v_assert_size_t(ARR_SIZ_MAX(str), ==, v->count);
	v_assert_size_t(8, ==, v->max);

	for (size_t i = 0; i < v->count; ++i)
	{
		value = *(char**)array_get(v, i);
		v_assert_ptr(str[i], ==, value);
		v_assert_str(str[i], value);
	}

	// last, unassigned
	v_assert_ptr(NULL, ==, array_get(v, 8));

	teardown();
	VTS;
}

static void	test_04_array_remove_OneItemInArrayOfSizeOne(void)
{
	int	ptr;

	v = array_new(1, sizeof(int));
	array_push(v, &(int){42});
	v_assert_size_t(8, ==, v->max);
	v_assert_size_t(1, ==, v->count);

	array_remove(v, 0, &ptr);
	v_assert_int(42, ==, ptr);
	v_assert_size_t(0, ==, v->count);

	VTS;
}

void	suite_array_remove(void)
{
	test_00_array_remove_FirstItem();
	test_01_array_remove_MiddleItem();
	test_02_array_remove_LastItem();
	test_03_array_remove_OutOfRange();
	test_04_array_remove_OneItemInArrayOfSizeOne();

	VSS;
}
