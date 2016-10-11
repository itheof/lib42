#include "header.h"

static t_string	*b;

static void	teardown(void)
{
	free(b->str);
	free(b);
}

static void	test_00_string_dup_String(void)
{
	char	*s = "Hello world";
	size_t	len = strlen(s);

	b = string_dup(s);

	v_assert_size_t(len, ==, b->len);
	v_assert_str(s, b->str);

	teardown();
	VTS;
}

static void	test_01_string_dup_EmptyString(void)
{
	char	*s = "";
	size_t	len = strlen(s);

	b = string_dup(s);

	v_assert_size_t(len, ==, b->len);
	v_assert_str(s, b->str);

	teardown();
	VTS;
}

static void	test_02_string_ndup_SimpleString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	b = string_ndup(s, 5);

	v_assert_size_t(5, ==, b->len);
	v_assert_str("Hello", b->str);

	teardown();
	VTS;
}

static void	test_03_string_ndup_ShortenString(void)
{
	char	*s = "abc";
	/* size_t	len = strlen(s); */

	b = string_ndup(s, 10);

	v_assert_size_t(64, ==, TBUFFER_MAX(b));
	v_assert_size_t(3, ==, b->len);
	v_assert_str("abc", b->str);

	teardown();
	VTS;
}

static void	test_04_string_ndup_ZeroLength(void)
{
	char	*s = "World!";
	/* size_t	len = strlen(s); */

	b = string_ndup(s, 0);

	v_assert_size_t(0, ==, b->len);
	v_assert_str("", b->str);

	teardown();
	VTS;
}

static void	test_05_string_cdup_CharInString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	b = string_cdup(s, 'W');

	v_assert_size_t(7, ==, b->len);
	v_assert_str("Hello W", b->str);

	teardown();
	VTS;
}

static void	test_06_string_cdup_CharNotInString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	b = string_cdup(s, 'z');

	v_assert_ptr(NULL, ==, b);

	VTS;
}

void	suite_string_dup(void)
{
	test_00_string_dup_String();
	test_01_string_dup_EmptyString();
	test_02_string_ndup_SimpleString();
	test_03_string_ndup_ShortenString();
	test_04_string_ndup_ZeroLength();
	test_05_string_cdup_CharInString();
	test_06_string_cdup_CharNotInString();

	VSS;
}
