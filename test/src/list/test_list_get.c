#include "header.h"

static t_list	list;

static void	setup(size_t elem_size)
{
	list_init(&list, elem_size);
}

static void	teardown(void)
{
	memset(&list, 0xFF, sizeof(t_list));
}

static void test_00_list_get_available(void)
{
	setup(sizeof(unsigned));
	v_assert_size_t(0, ==, list.len);
	/* v_assert_ptr(NULL, !=, list.start); */
	/* v_assert_ptr(NULL, !=, list.end); */

	unsigned *n1 = (unsigned*)list_get_available(&list);
	v_assert_ptr(NULL, !=, n1);
	v_assert_size_t(1, ==, list.len);
	v_assert_ptr(NULL, !=, list.start);
	v_assert_ptr(NULL, !=, list.end);
	v_assert_ptr(list.start, ==, list.end);
	v_assert_ptr(&list.end->data, ==, n1);
	*n1 = ~0U;

/* 	printf("#### start: %p\n", (void*)list.start); */
/* 	printf("#### end: %p\n", (void*)list.end); */
/* 	printf("#### n1: %p\n", (void*)n1); */
/* 	printf("#### &start.data: %p\n", (void*)&list.start->data); */
/* 	printf("#### &end.data: %p\n", (void*)&list.end->data); */
/* 	printf("#### start.GET_DATA: %u\n", *(unsigned*)NODE_GET_DATA(list.start)); */
/* 	printf("#### start.GET_DATA: %#x\n", *(unsigned*)NODE_GET_DATA(list.start)); */
/* 	printf("#### end.GET_DATA: %u\n", *(unsigned*)NODE_GET_DATA(list.end)); */
/* 	printf("#### end.GET_DATA: %#x\n", *(unsigned*)NODE_GET_DATA(list.end)); */
/* 	puts(""); */

	v_assert_uint(*n1, ==, *(unsigned*)NODE_GET_DATA(list.start));

	unsigned *n2 = (unsigned*)list_get_available(&list);
	v_assert_ptr(NULL, !=, n2);
	v_assert_size_t(2, ==, list.len);
	v_assert_ptr(NULL, !=, list.start);
	v_assert_ptr(NULL, !=, list.end);
	v_assert_ptr(list.start, !=, list.end);
	v_assert_ptr(&list.start->data, ==, n1);
	v_assert_ptr(&list.end->data, ==, n2);
	*n2 = 42;

/* 	printf("#### second call to list_get_available\n"); */
/* 	printf("#### start: %p\n", (void*)list.start); */
/* 	printf("#### end: %p\n", (void*)list.end); */
/* 	printf("#### n1: %p\n", (void*)n1); */
/* 	printf("#### n2: %p\n", (void*)n2); */
/* 	printf("#### &start.data: %p\n", (void*)&list.start->data); */
/* 	printf("#### &end.data: %p\n", (void*)&list.end->data); */
/* 	printf("#### start.GET_DATA: %u\n", *(unsigned*)NODE_GET_DATA(list.start)); */
/* 	printf("#### start.GET_DATA: %#x\n", *(unsigned*)NODE_GET_DATA(list.start)); */
/* 	printf("#### end.GET_DATA: %u\n", *(unsigned*)NODE_GET_DATA(list.end)); */
/* 	printf("#### end.GET_DATA: %#x\n", *(unsigned*)NODE_GET_DATA(list.end)); */

	v_assert_uint(~0U, ==, *(unsigned*)NODE_GET_DATA(list.start));
	v_assert_uint(42, ==, *(unsigned*)NODE_GET_DATA(list.end));

	unsigned *n3 = (unsigned*)list_get_available(&list);
	v_assert_ptr(NULL, !=, n3);
	v_assert_size_t(3, ==, list.len);
	v_assert_ptr(NULL, !=, list.start);
	v_assert_ptr(NULL, !=, list.end);
	v_assert_ptr(list.start, !=, list.end);
	v_assert_ptr(&list.start->data, ==, n1);
	v_assert_ptr(&list.end->data, ==, n3);
	*n3 = 1234;

	v_assert_uint(~0U, ==, *(unsigned*)NODE_GET_DATA(list.start));
	v_assert_uint(42, ==, *(unsigned*)NODE_GET_DATA(list.start->next));
	v_assert_uint(1234, ==, *(unsigned*)NODE_GET_DATA(list.end));

	teardown();
	VTS;
}

static void	test_01_list_get_at(void)
{
	setup(sizeof(char));
	v_assert_size_t(0, ==, list.len);

	char *c[4];
	c[0] = (char*)list_get_available(&list);
	c[1] = (char*)list_get_available(&list);
	c[2] = (char*)list_get_available(&list);
	c[3] = (char*)list_get_available(&list);
	c[0][0] = 'a';
	c[1][0] = 'b';
	c[2][0] = 'c';
	c[3][0] = 'd';

	v_assert_size_t(4, ==, list.len);
	v_assert_char('a', ==, *(char*)list_get_at(&list, 0));
	v_assert_char('b', ==, *(char*)list_get_at(&list, 1));
	v_assert_char('c', ==, *(char*)list_get_at(&list, 2));
	v_assert_char('d', ==, *(char*)list_get_at(&list, 3));
	v_assert_ptr(NULL, ==, list_get_at(&list, 4));

	teardown();
	VTS;
}

void	suite_list_get(void)
{
	test_00_list_get_available();
	test_01_list_get_at();

	VSS;
}
