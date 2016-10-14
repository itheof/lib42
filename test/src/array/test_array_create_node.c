#include "header.h"

static t_array	array;

static void	setup(void *data, size_t elem_size, size_t len)
{
	unsigned char	*p;
	unsigned char	*d;

	array_init(&array, 8, elem_size);
	if (data != NULL)
	{
		p = array.data;
		d = data;
		for (size_t i = 0; i < len; ++i)
			memcpy(p + (elem_size * i), d + (elem_size * i), elem_size);
		array.len = len;
	}
}

static void	teardown(void)
{
	free(array.data);
}

static void	test_00_array_create_node_EmptyArray(void)
{
	void			*p;
	size_t			elem_size = 16;
	unsigned char	*res;

	setup(NULL, elem_size, 0);
	res = array.data;

	p = array_create_node(&array);
	v_assert_ptr(res, ==, p);
	v_assert_size_t(array.len, ==, 1);

	p = array_create_node(&array);
	v_assert_ptr(res + elem_size, ==, p);
	v_assert_size_t(array.len, ==, 2);

	teardown();
	VTS;
}

static void	test_01_array_create_node_ResizeArray(void)
{
	void			*p;
	size_t			elem_size = 16;
	unsigned char	*res;

	setup(NULL, elem_size, 0);

	v_assert_size_t(8, ==, array.capacity);
	v_assert_size_t(0, ==, array.len);

	for (size_t i = 0; i < 10; ++i)
	{
		p = array_create_node(&array);
		res = array.data;
		v_assert_ptr(res + (i * elem_size), ==, p);
		v_assert_size_t(array.len, ==, i + 1);
	}

	v_assert_size_t(16, ==, array.capacity);
	v_assert_size_t(10, ==, array.len);

	teardown();
	VTS;
}

void	suite_array_create_node(void)
{
	test_00_array_create_node_EmptyArray();
	test_01_array_create_node_ResizeArray();

	VSS;
}
