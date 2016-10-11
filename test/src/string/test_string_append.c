#include "header.h"

static void	test_00_string_append_Simple(void)
{
	t_string	*dst;
	t_string	*src;
	char		*s1 = "Hello";
	char		*s2 = " World!";
	char		cat[20];
	size_t		l1 = strlen(s1);
	size_t		l2 = strlen(s2);

	dst = string_ndup(s1, l1);
	src = string_ndup(s2, l2);
	strcpy(cat, s1);
	strcpy(cat + l1, s2);
	string_append(dst, src);

	v_assert_size_t(l2, ==, src->len);
	v_assert_str(s2, src->str);

	/* v_assert_size_t(16, ==, dst->sizemax); */
	v_assert_size_t(l1 + l2, ==, dst->len);
	v_assert_str(cat, dst->str);

	free(src->str);
	free(dst->str);
	free(src);
	free(dst);

	VTS;
}

static void	test_01_string_append_Emptystring(void)
{
	t_string	*dst;
	t_string	*src;
	char		*s1 = "Emtpy";
	char		*s2 = "";
	char		cat[20];
	size_t		l1 = strlen(s1);
	size_t		l2 = strlen(s2);

	dst = string_ndup(s1, l1);
	src = string_ndup(s2, l2);
	strcpy(cat, s1);
	strcpy(cat + l1, s2);
	string_append(dst, src);

	v_assert_size_t(l2, ==, src->len);
	v_assert_str(s2, src->str);

	/* v_assert_size_t(16, ==, dst->sizemax); */
	v_assert_size_t(l1 + l2, ==, dst->len);
	v_assert_str(cat, dst->str);

	free(src->str);
	free(dst->str);
	free(src);
	free(dst);

	VTS;
}

void	suite_string_append(void)
{
	test_00_string_append_Simple();
	test_01_string_append_Emptystring();

	VSS;
}
