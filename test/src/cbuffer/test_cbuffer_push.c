#include "header.h"

static void	test_00_cbuffer_pushBackInt(void)
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

	VTS;
}

static void	test_01_cbuffer_pushBackTwoInt(void)
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

	VTS;
}

static void	test_02_cbuffer_pushBackExactLenInt(void)
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

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int middle = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(b, ==, middle);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(c, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_03_cbuffer_pushBackMoreInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &b);
	cbuffer_push_back(&buffer, &c);
	cbuffer_push_back(&buffer, &d);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(b, ==, front);

	int middle = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(c, ==, middle);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(d, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_04_cbuffer_pushFrontInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_front(&buffer, &a);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int n = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(a, ==, n);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_05_cbuffer_pushFrontTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &b);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(b, ==, front);

	int n1 = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(b, ==, n1);

	int n2 = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(a, ==, n2);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_06_cbuffer_pushFrontExactLenInt(void)
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

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(c, ==, front);

	int middle = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(b, ==, middle);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_07_cbuffer_pushFrontMoreInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &b);
	cbuffer_push_front(&buffer, &c);
	cbuffer_push_front(&buffer, &d);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(d, ==, front);

	int middle = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(c, ==, middle);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(b, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void test_08_cbuffer_pushFrontAndBackInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_front(&buffer, &b);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(b, ==, front);

	int n1 = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(b, ==, n1);

	int n2 = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(a, ==, n2);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void test_09_cbuffer_pushFrontAndBackTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &b);
	cbuffer_push_back(&buffer, &c);
	cbuffer_push_back(&buffer, &d);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(a, ==, front);

	int n1 = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(a, ==, n1);

	int n2 = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(c, ==, n2);

	int n3 = *((int*)cbuffer_get(&buffer, 2));
	v_assert_int(d, ==, n3);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(d, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void test_10_cbuffer_pushBackAndFrontInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_front(&buffer, &b);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(b, ==, front);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void test_11_cbuffer_pushBackAndFrontTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int), NULL);

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &b);
	cbuffer_push_front(&buffer, &c);
	cbuffer_push_front(&buffer, &d);

	int front = *((int*)cbuffer_get_front(&buffer));
	v_assert_int(d, ==, front);

	int n1 = *((int*)cbuffer_get(&buffer, 0));
	v_assert_int(d, ==, n1);

	int n2 = *((int*)cbuffer_get(&buffer, 1));
	v_assert_int(c, ==, n2);

	int n3 = *((int*)cbuffer_get(&buffer, 2));
	v_assert_int(a, ==, n3);

	int back = *((int*)cbuffer_get_back(&buffer));
	v_assert_int(a, ==, back);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

void	suite_cbuffer_push(void)
{
	test_00_cbuffer_pushBackInt();
	test_01_cbuffer_pushBackTwoInt();
	test_02_cbuffer_pushBackExactLenInt();
	test_03_cbuffer_pushBackMoreInt();

	test_04_cbuffer_pushFrontInt();
	test_05_cbuffer_pushFrontTwoInt();
	test_06_cbuffer_pushFrontExactLenInt();
	test_07_cbuffer_pushFrontMoreInt();

	test_08_cbuffer_pushFrontAndBackInt();
	test_09_cbuffer_pushFrontAndBackTwoInt();

	test_10_cbuffer_pushBackAndFrontInt();
	test_11_cbuffer_pushBackAndFrontTwoInt();

	VSS;
}
