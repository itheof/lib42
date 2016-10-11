#include "header.h"

void	test_00_string_set_simple(void)
{
	t_string b;
	char	*s = "**********";
	size_t len = strlen(s);

	string_init(&b, 0);
	string_set(&b, '*', 10);
	string_set(&b, '\0', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 1, ==, TBUFFER_LEN(&b));

	string_set(&b, '#', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 2, ==, TBUFFER_LEN(&b));

	TBUFFER_FREE(&b);
	VTS;
}

void	suite_string_set(void)
{
	test_00_string_set_simple();

	VSS;
}
