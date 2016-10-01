#include "header.h"

static t_pool	*p;

static void	teardown(void)
{
	free(p->chunks_list);
	free(p);
	p = NULL;
}

static void	test_00_pool_new_ArgEqualZero(void)
{
	p = pool_new(0, 10);
	v_assert_ptr(NULL, ==, p);

	p = pool_new(10, 0);
	v_assert_ptr(NULL, ==, p);

	VTS;
}

static void	test_01_pool_new_SizeOfInt(void)
{
	t_chunk		*chunk;
	size_t		size;
	unsigned	*n;

	// setup
	p = pool_new(sizeof(unsigned), 10);
	size = ROUND_UP_8(sizeof(unsigned));
	v_assert_size_t(size, ==, p->elem_size);
	v_assert_size_t(10, ==, p->chunk_capacity);
	v_assert_ptr(NULL, ==, p->free_list);
	v_assert_ptr(NULL, ==, p->chunks_list);
	chunk = pool_new_chunk(p);
	p->free_list = CHUNK_HEAD(chunk);
	chunk->next = p->chunks_list;
	p->chunks_list = chunk;

	// linkage interne
	uintptr_t	*pValue = p->free_list;
	char		*pAddr = (char*)&p->chunks_list->head;
	while (*pValue)
	{
		v_assert_ptr(pAddr, ==, pValue);
		pAddr += p->elem_size;
		v_assert_uintptr(*pValue, ==, pAddr);
		pValue += 1;
	}
	v_assert_uintptr(0, ==, *pValue);

	// freelist
	v_assert_ptr(NULL, !=, p->free_list);
	n = p->free_list;
	*n = ~0U;

	teardown();
	VTS;
}

static void	test_02_pool_new_SizeOfArbitraryStruct(void)
{
	t_chunk		*chunk;
	size_t		size;
	unsigned	*n;

	struct s_pool_test
	{
		void	*p[3];
		int		i[2];
		char	c[8];
	} t;

	// setup
	p = pool_new(sizeof(struct s_pool_test), 100);
	size = ROUND_UP_8(sizeof(struct s_pool_test));
	v_assert_size_t(size, ==, p->elem_size);
	v_assert_size_t(100, ==, p->chunk_capacity);
	v_assert_ptr(NULL, ==, p->free_list);
	v_assert_ptr(NULL, ==, p->chunks_list);
	chunk = pool_new_chunk(p);
	p->free_list = CHUNK_HEAD(chunk);
	chunk->next = p->chunks_list;
	p->chunks_list = chunk;

	// linkage interne
	uintptr_t	*pValue = p->free_list;
	char		*pAddr = (char*)&p->chunks_list->head;

	while (*pValue)
	{
		v_assert_ptr(pAddr, ==, pValue);
		pAddr += p->elem_size;
		v_assert_uintptr(*pValue, ==, pAddr);
		pValue += p->elem_size / 8;
	}
	v_assert_uintptr(0, ==, *pValue);

	// freelist
	v_assert_ptr(NULL, !=, p->free_list);
	n = p->free_list;
	*n = ~0U;

	teardown();
	VTS;
}

void	suite_pool_new(void)
{
	test_00_pool_new_ArgEqualZero();
	test_01_pool_new_SizeOfInt();
	test_02_pool_new_SizeOfArbitraryStruct();

	VSS;
}
