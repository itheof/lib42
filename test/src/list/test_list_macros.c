#include "header.h"

static void	test_00_list_macros_NODE_SIZE(void)
{
	v_assert_size_t(12, ==, NODE_SIZE(sizeof(unsigned)));
	v_assert_size_t(9, ==, NODE_SIZE(sizeof(char)));
	v_assert_size_t(31, ==, NODE_SIZE(23));

	VTS;
}

static void	test_01_list_macros_NODE_GET_DATA(void)
{
	size_t	elem_size = sizeof(unsigned);
	void	*p = malloc(NODE_SIZE(elem_size));

	// setup
	struct s_check
	{
		void		*next;
		unsigned	a;
		unsigned	b;
	} check;
	memset(&check, 0xFF, sizeof(struct s_check));

	// test
	unsigned *pu = NODE_GET_DATA(&check);
	*pu = 42U;
	v_assert_ptr(0xFFFFFFFFFFFFFFFF, ==, check.next);
	v_assert_uint(42, ==, check.a);
	v_assert_uint(0xFFFFFFFF, ==, check.b);

	// teardown
	free(p);
	VTS;
}
void	suite_list_macros(void)
{
	test_00_list_macros_NODE_SIZE();
	test_01_list_macros_NODE_GET_DATA();

	VSS;
}
