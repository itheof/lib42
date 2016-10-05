#include "header.h"

static t_pool	*p;

static void	setup(size_t size, size_t count)
{
	p = pool_new(size, count);
}

static void	teardown(void)
{
	void	*ptr;

	while ((ptr = p->chunks_list))
	{
		p->chunks_list = p->chunks_list->next;
		free(ptr);
	}
	free(p);
}

static void	test_00_pool_reset_MultiChunksInPool(void)
{
	size_t	elem_size = sizeof(char*);
	size_t	count = 1;

	// setup
	setup(elem_size, count);
	for (size_t i = 0; i < 6; ++i)
	{
		pool_obtain(p);
	}

	// reset du pool
	pool_reset(p);
	v_assert_ptr(NULL, ==, p->free_list);
	v_assert_ptr(NULL, ==, p->chunks_list);
	v_assert_size_t(sizeof(char*), ==, p->elem_size);
	v_assert_size_t(1, ==, p->chunk_capacity);

	teardown();
	VTS;
}

static void test_01_pool_reset_NewAllocAfterReset(void)
{
	size_t	elem_size = sizeof(char*);
	size_t	count = 1;
	void	*pValue[6];

	// setup
	setup(elem_size, count);
	for (size_t i = 0; i < 6; ++i)
	{
		pValue[i] = pool_obtain(p);
		pValue[i] = "Hello World!";
		v_assert_str("Hello World!", pValue[i]);
	}

	// reset du pool
	pool_reset(p);
	v_assert_ptr(NULL, ==, p->free_list);
	v_assert_ptr(NULL, ==, p->chunks_list);
	v_assert_size_t(sizeof(char*), ==, p->elem_size);
	v_assert_size_t(1, ==, p->chunk_capacity);

	// nouvelle allocation
	pValue[0] = pool_obtain(p);
	pValue[0] = "New alloc";
	v_assert_str("New alloc", pValue[0]);

	teardown();
	VTS;
}

void	suite_pool_reset(void)
{
	test_00_pool_reset_MultiChunksInPool();
	test_01_pool_reset_NewAllocAfterReset();

	VSS;
}
