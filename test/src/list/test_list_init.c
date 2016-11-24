#include "header.h"

static t_list	list;

static void	setup(void)
{
	memset(&list, 0xFF, sizeof(list));
}

static void	teardown(void)
{
	pool_shutdown(&list.pool);
}

static void test_00_list_init_ElemSizeEqualZero(void)
{
	void	*ret;

	ret = list_init(&list, 0);
	v_assert_ptr(NULL, ==, ret);

	VTS;
}

static void	test_01_list_init_ElemSizeValid(void)
{
	void	*ret;

	setup();

	ret = list_init(&list, 17);
	v_assert_ptr(NULL, !=, ret);
	v_assert_ptr(NULL, !=, list.pool.chunks_list);
	v_assert_ptr(NULL, !=, list.pool.free_list);
	v_assert_size_t(127, ==, list.pool.chunk_capacity);
	v_assert_size_t(32, ==, list.pool.elem_size);
	v_assert_size_t(17, ==, list.elem_size);
	v_assert_size_t(0, ==, list.len);

	teardown();
	VTS;
}

void suite_list_init(void)
{
	test_00_list_init_ElemSizeEqualZero();
	test_01_list_init_ElemSizeValid();

	VSS;
}
