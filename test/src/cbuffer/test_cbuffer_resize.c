#include "header.h"

static void	test_00_cbuffer_resizeStartBeforeEnd(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 10, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(10, ==, buffer.capacity);

	for (int i = 0; i < 10; ++i)
	{
		cbuffer_push_back(&buffer, &i);
	}

	{
		int front = *((int*)cbuffer_front(&buffer));
		v_assert_int(0, ==, front);

		int n = *((int*)cbuffer_at(&buffer, 5));
		v_assert_int(5, ==, n);

		int back = *((int*)cbuffer_back(&buffer));
		v_assert_int(9, ==, back);
	}

	v_assert_size_t(10, ==, buffer.len);
	v_assert_size_t(10, ==, buffer.capacity);

	buffer = *cbuffer_resize(&buffer, 20);
	{
		int front = *((int*)cbuffer_front(&buffer));
		v_assert_int(0, ==, front);

		int n = *((int*)cbuffer_at(&buffer, 5));
		v_assert_int(5, ==, n);

		int back = *((int*)cbuffer_back(&buffer));
		v_assert_int(9, ==, back);
	}

	v_assert_size_t(10, ==, buffer.len);
	v_assert_size_t(20, ==, buffer.capacity);

	cbuffer_shutdown(&buffer);
	VTS;
}

static void	test_01_cbuffer_resizeStartAfterEnd(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 10, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(10, ==, buffer.capacity);

	for (int i = 0; i < 8; ++i)
	{
		cbuffer_push_front(&buffer, &i);
	}

	{
		int front = *((int*)cbuffer_front(&buffer));
		v_assert_int(7, ==, front);

		int n = *((int*)cbuffer_at(&buffer, 4));
		v_assert_int(3, ==, n);

		int back = *((int*)cbuffer_back(&buffer));
		v_assert_int(0, ==, back);
	}

	v_assert_size_t(8, ==, buffer.len);
	v_assert_size_t(10, ==, buffer.capacity);

	buffer = *cbuffer_resize(&buffer, 20);
	{
		int front = *((int*)cbuffer_front(&buffer));
		v_assert_int(7, ==, front);

		int n = *((int*)cbuffer_at(&buffer, 4));
		v_assert_int(3, ==, n);

		int back = *((int*)cbuffer_back(&buffer));
		v_assert_int(0, ==, back);
	}

	v_assert_size_t(8, ==, buffer.len);
	v_assert_size_t(20, ==, buffer.capacity);

	cbuffer_shutdown(&buffer);
	VTS;
}

static void	test_02_cbuffer_resizeEmptyBuffer(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 10, sizeof(int), NULL);

	v_assert_ptr(NULL, ==, cbuffer_back(&buffer));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(10, ==, buffer.capacity);

	buffer = *cbuffer_resize(&buffer, 20);

	v_assert_ptr(NULL, ==, cbuffer_back(&buffer));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(20, ==, buffer.capacity);

	cbuffer_shutdown(&buffer);
	VTS;
}

void	suite_cbuffer_resize(void)
{
	test_00_cbuffer_resizeStartBeforeEnd();
	test_01_cbuffer_resizeStartAfterEnd();
	test_02_cbuffer_resizeEmptyBuffer();

	VSS;
}
