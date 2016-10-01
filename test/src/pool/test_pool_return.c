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

static void	test_00_pool_return_AllElementTypeUnsignedIntInOrder(void)
{
	size_t	elem_size = sizeof(unsigned);
	size_t	count = 5;
	void	*pValue[count];
	char	*pAddr;

	setup(elem_size, count);
	for (size_t i = 0; i < count; ++i)
		pValue[i] = pool_obtain(p);
	v_assert_ptr(NULL, ==, p->free_list);

	// test
	for (size_t i = 0; i < count; ++i)
	{
		pool_return(p, pValue[i]);
		v_assert_ptr(pValue[i], ==, p->free_list);
	}

	teardown();
	VTS;
}

static void	test_01_pool_return_AllElementTypeUnsignedIntInDisorder(void)
{
	size_t	elem_size = sizeof(unsigned);
	size_t	count = 5;
	void	*pValue[count];
	char	*pAddr;

	setup(elem_size, count);
	for (size_t i = 0; i < count; ++i)
		pValue[i] = pool_obtain(p);
	v_assert_ptr(NULL, ==, p->free_list);

	// test
	pool_return(p, pValue[3]);
	v_assert_ptr(pValue[3], ==, p->free_list);
	pool_return(p, pValue[1]);
	v_assert_ptr(pValue[1], ==, p->free_list);
	pool_return(p, pValue[0]);
	v_assert_ptr(pValue[0], ==, p->free_list);
	pool_return(p, pValue[4]);
	v_assert_ptr(pValue[4], ==, p->free_list);
	pool_return(p, pValue[2]);
	v_assert_ptr(pValue[2], ==, p->free_list);

	// obtain
	void	*pObtain = pool_obtain(p);
	v_assert_ptr(pValue[2], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[4], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[0], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[1], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[3], ==, pObtain);

	teardown();
	VTS;
}

static void	test_02_pool_return_MultiChunksInDisorder(void)
{
	size_t	elem_size = sizeof(unsigned);
	size_t	count = 2;
	void	*pValue[count * 3];
	char	*pAddr;

	setup(elem_size, count);
	for (size_t i = 0; i < count * 3; ++i)
		pValue[i] = pool_obtain(p);
	v_assert_ptr(NULL, ==, p->free_list);

	// test
	pool_return(p, pValue[3]);
	v_assert_ptr(pValue[3], ==, p->free_list);
	pool_return(p, pValue[5]);
	v_assert_ptr(pValue[5], ==, p->free_list);
	pool_return(p, pValue[0]);
	v_assert_ptr(pValue[0], ==, p->free_list);

	// obtain
	void	*pObtain = pool_obtain(p);
	v_assert_ptr(pValue[0], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[5], ==, pObtain);
	pObtain = pool_obtain(p);
	v_assert_ptr(pValue[3], ==, pObtain);

	teardown();
	VTS;
}

void	suite_pool_return(void)
{
	test_00_pool_return_AllElementTypeUnsignedIntInOrder();
	test_01_pool_return_AllElementTypeUnsignedIntInDisorder();
	test_02_pool_return_MultiChunksInDisorder();

	VSS;
}
