#include "header.h"

static void	test_00_cbuffer_popBackInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int n = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(a, ==, n);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_back(&buffer);

	v_assert_ptr(NULL, ==, cbuffer_get_back(&buffer));
	v_assert_ptr(NULL, ==, cbuffer_get_front(&buffer));
	v_assert_ptr(NULL, ==, cbuffer_get(&buffer, 0));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_01_cbuffer_popBackWithTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &b);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(b, ==, back);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_back(&buffer);
	{
		int front = *((int*)cbuffer_get_front(&buffer));
		v_assert_int(a, ==, front);
		int back = *((int*)cbuffer_get_back(&buffer));
		v_assert_int(a, ==, back);
	}

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_02_cbuffer_popBackEqualMaxLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &b);
	cbuffer_push_front(&buffer, &c);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);
	{
		int front = *((int*)cbuffer_get_front(&buffer));
		v_assert_int(c, ==, front);
		int back = *((int*)cbuffer_get_back(&buffer));
		v_assert_int(c, ==, back);
	}

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_03_cbuffer_popBackMoreThanLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);
	cbuffer_pop_back(&buffer);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_04_cbuffer_popFrontInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int n = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(a, ==, n);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_front(&buffer);

	v_assert_ptr(NULL, ==, cbuffer_get_back(&buffer));
	v_assert_ptr(NULL, ==, cbuffer_get_front(&buffer));
	v_assert_ptr(NULL, ==, cbuffer_get(&buffer, 0));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_05_cbuffer_popFrontWithTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &b);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(b, ==, back);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_front(&buffer);
	{
		int front = *((int*)cbuffer_get_front(&buffer));
		int back = *((int*)cbuffer_get_back(&buffer));

		v_assert_int(front, ==, back);
		v_assert_int(b, ==, front);
		v_assert_int(b, ==, back);
	}

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_05_cbuffer_popFrontEqualMaxLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &b);
	cbuffer_push_back(&buffer, &c);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);
	{
		int front = *((int*)cbuffer_get_front(&buffer));
		v_assert_int(c, ==, front);
		int back = *((int*)cbuffer_get_back(&buffer));
		v_assert_int(c, ==, back);
	}

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_07_cbuffer_popFrontMoreThanLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);
	cbuffer_pop_front(&buffer);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_08_cbuffer_popFrontCheckReturn(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int *r = cbuffer_pop_front(&buffer);
	v_assert_int(a, ==, *r);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_09_cbuffer_popBackCheckReturn(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int *r = cbuffer_pop_back(&buffer);
	v_assert_int(a, ==, *r);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

void	suite_cbuffer_pop(void)
{
	test_00_cbuffer_popBackInt();
	test_01_cbuffer_popBackWithTwoInt();
	test_02_cbuffer_popBackEqualMaxLenInt();
	test_03_cbuffer_popBackMoreThanLenInt();

	test_04_cbuffer_popFrontInt();
	test_05_cbuffer_popFrontWithTwoInt();
	test_05_cbuffer_popFrontEqualMaxLenInt();
	test_07_cbuffer_popFrontMoreThanLenInt();

	test_08_cbuffer_popFrontCheckReturn();
	test_09_cbuffer_popBackCheckReturn();

	VSS;
}
