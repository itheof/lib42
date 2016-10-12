#include "header.h"

static void	test_00_string_clone_Simple(void)
{
	t_string	origin;
	t_string	cp;
	char		*s = "Hello World!";
	size_t		len = strlen(s);

	string_dup(&origin, s);
	string_clone(&cp, &origin);

	v_assert_size_t(len, ==, cp.len);
	v_assert_str(s, cp.str);
	v_assert_ptr(origin.str, !=, cp.str);
	v_assert_ptr(&origin, !=, &cp);

	free(origin.str);
	free(cp.str);
	VTS;
}

void	suite_string_clone(void)
{
	test_00_string_clone_Simple();

	VSS;
}
