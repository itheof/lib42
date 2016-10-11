#include "header.h"

static void	test_00_string_cat_Simple(void)
{
	t_string	string;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	string_init(&string, 4);
	string_cat(&string, s);

	v_assert_size_t(l, ==, string.len);
	v_assert_size_t(64, ==, string.sizemax);
	v_assert_str(s, string.str);

	free(string.str);

	VTS;
}

static void	test_01_string_cat_NeedResize(void)
{
	t_string	string;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	string_init(&string, 12);
	string_cat(&string, s);

	v_assert_size_t(l, ==, string.len);
	v_assert_size_t(64, ==, string.sizemax);
	v_assert_str(s, string.str);

	free(string.str);

	VTS;
}

static void	test_02_string_cat_BigConcatenation(void)
{
	t_string	string;
	char		a[300];
	char		m[3000];
	char		am[4000];
	size_t		alen;
	size_t		mlen;

	string_init(&string, 8);

	memset(a, 'a', sizeof(a));
	a[sizeof(a) - 1] = '\0';
	alen = strlen(a);
	string_ncat(&string, a, alen);
	v_assert_size_t(alen, ==, string.len);
	v_assert_size_t(512, ==, string.sizemax);
	v_assert_str(a, string.str);

	memset(m, 'm', sizeof(m));
	m[sizeof(m) - 1] = '\0';
	mlen = strlen(m);
	memset(am, 0, sizeof(am));
	strcat(am, a);
	strcat(am + sizeof(a) - 1, m);
	string_ncat(&string, m, mlen);
	v_assert_size_t(alen + mlen, ==, string.len);
	v_assert_size_t(4096, ==, string.sizemax);
	v_assert_str(am, string.str);

	free(string.str);

	VTS;
}

void	suite_string_cat(void)
{
	test_00_string_cat_Simple();
	test_01_string_cat_NeedResize();
	test_02_string_cat_BigConcatenation();

	VSS;
}
