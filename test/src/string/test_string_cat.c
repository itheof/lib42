#include "header.h"

static void	test_00_string_cat_Simple(void)
{
	t_string	*b;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	b = string_new(4);
	string_cat(b, s);

	v_assert_size_t(l, ==, b->len);
	v_assert_size_t(64, ==, TBUFFER_MAX(b));
	v_assert_str(s, b->str);

	free(b->str);
	free(b);

	VTS;
}

static void	test_01_string_cat_NeedResize(void)
{
	t_string	*b;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	b = string_new(12);
	string_cat(b, s);

	v_assert_size_t(l, ==, b->len);
	v_assert_size_t(64, ==, TBUFFER_MAX(b));
	v_assert_str(s, b->str);

	free(b->str);
	free(b);

	VTS;
}

static void	test_02_string_cat_BigConcatenation(void)
{
	t_string	*b;
	char		a[300];
	char		m[3000];
	char		am[4000];
	size_t		alen;
	size_t		mlen;

	b = string_new(8);

	memset(a, 'a', sizeof(a));
	a[sizeof(a) - 1] = '\0';
	alen = strlen(a);
	string_ncat(b, a, alen);
	v_assert_size_t(alen, ==, b->len);
	v_assert_size_t(512, ==, TBUFFER_MAX(b));
	v_assert_str(a, b->str);

	memset(m, 'm', sizeof(m));
	m[sizeof(m) - 1] = '\0';
	mlen = strlen(m);
	memset(am, 0, sizeof(am));
	strcat(am, a);
	strcat(am + sizeof(a) - 1, m);
	string_ncat(b, m, mlen);
	v_assert_size_t(alen + mlen, ==, b->len);
	v_assert_size_t(4096, ==, TBUFFER_MAX(b));
	v_assert_str(am, b->str);

	free(b->str);
	free(b);

	VTS;
}

void	suite_string_cat(void)
{
	test_00_string_cat_Simple();
	test_01_string_cat_NeedResize();
	test_02_string_cat_BigConcatenation();

	VSS;
}
