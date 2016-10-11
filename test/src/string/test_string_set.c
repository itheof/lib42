#include "header.h"

void	test_00_string_set_simple(void)
{
	t_string	string;
	char	*s = "**********";
	size_t len = strlen(s);

	string_init(&string, 0);
	string_set(&string, '*', 10);
	string_set(&string, '\0', 1);
	v_assert_str(s, string.str);
	v_assert_size_t(len + 1, ==, string.len);

	string_set(&string, '#', 1);
	v_assert_str(s, string.str);
	v_assert_size_t(len + 2, ==, string.len);

	free(string.str);
	VTS;
}

void	suite_string_set(void)
{
	test_00_string_set_simple();

	VSS;
}
