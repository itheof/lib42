#include "header.h"

static void	test_00_cbuffer_pushBackInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushBackTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_back(&buffer, &a);
	cbuffer_push_back(&buffer, &a);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushBackExactLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
									// end == 0; start == 0; len == 0; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 1; start == 0; len == 1; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 2; start == 0; len == 2; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 0; start == 1; len == 3; max_len == 3

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushBackMoreInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
									// end == 0; start == 0; len == 0; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 1; start == 0; len == 1; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 2; start == 0; len == 2; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 0; start == 1; len == 3; max_len == 3
	cbuffer_push_back(&buffer, &a);	// end == 1; start == 2; len == 3; max_len == 3

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushFrontInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_front(&buffer, &a);

	v_assert_size_t(1, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushFrontTwoInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);

	v_assert_size_t(2, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushFrontExactLenInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

static void	test_00_cbuffer_pushFrontMoreInt(void)
{
	t_cbuffer	buffer;

	cbuffer_init(&buffer, 3, sizeof(int));

	v_assert_size_t(0, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	int a = 10;
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);
	cbuffer_push_front(&buffer, &a);

	v_assert_size_t(3, ==, buffer.len);
	v_assert_size_t(3, ==, buffer.max_len);

	VTS;
}

void	suite_cbuffer_push(void)
{
	test_00_cbuffer_pushBackInt();
	test_00_cbuffer_pushBackTwoInt();
	test_00_cbuffer_pushBackExactLenInt();
	test_00_cbuffer_pushBackMoreInt();

	test_00_cbuffer_pushFrontInt();
	test_00_cbuffer_pushFrontTwoInt();
	test_00_cbuffer_pushFrontExactLenInt();
	test_00_cbuffer_pushFrontMoreInt();

	VSS;
}
