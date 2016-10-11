#include "header.h"

static void	test_00_string_twin_Simple(void)
{
	t_string	*origin;
	t_string	*cp;
	char		*s = "Hello World!";
	size_t		len = strlen(s);

	origin = string_dup(s);
	string_iterator_next(origin);
	string_iterator_next(origin);
	string_iterator_next(origin);
	string_iterator_next(origin);
	cp = string_twin(origin);

	v_assert_size_t(STRING_INIT_SIZE, ==, TBUFFER_MAX(cp));
	v_assert_size_t(len, ==, TBUFFER_LEN(cp));
	v_assert_size_t(TBUFFER_ITER(origin), ==, TBUFFER_ITER(cp));
	v_assert_str(s, TBUFFER_GET(cp));
	v_assert_ptr(TBUFFER_GET(origin), !=, TBUFFER_GET(cp));
	v_assert_ptr(origin, !=, cp);

	free(TBUFFER_GET(origin));
	free(TBUFFER_GET(cp));
	free(origin);
	free(cp);
	VTS;
}

void	suite_string_twin(void)
{
	test_00_string_twin_Simple();

	VSS;
}
