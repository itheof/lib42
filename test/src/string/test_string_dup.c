#include "header.h"

static t_string		string;

static void	teardown(void)
{
	free(string.str);
}

static void	test_00_string_dup_String(void)
{
	char	*s = "Hello world";
	size_t	len = strlen(s);

	string_dup(&string, s);

	v_assert_size_t(len, ==, string.len);
	v_assert_str(s, string.str);

	teardown();
	VTS;
}

static void	test_01_string_dup_EmptyString(void)
{
	char	*s = "";
	size_t	len = strlen(s);

	string_dup(&string, s);

	v_assert_size_t(len, ==, string.len);
	v_assert_str(s, string.str);

	teardown();
	VTS;
}

static void	test_02_string_ndup_SimpleString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	string_ndup(&string, s, 5);

	v_assert_size_t(5, ==, string.len);
	v_assert_str("Hello", string.str);

	teardown();
	VTS;
}

static void	test_03_string_ndup_ShortenString(void)
{
	char	*s = "abc";
	size_t	len = strlen(s);

	string_ndup(&string, s, 10);

	v_assert_size_t(64, ==, string.capacity);
	v_assert_size_t(len, ==, string.len);
	v_assert_str(s, string.str);

	teardown();
	VTS;
}

static void	test_04_string_ndup_ZeroLength(void)
{
	char	*s = "World!";
	/* size_t	len = strlen(s); */

	string_ndup(&string, s, 0);

	v_assert_size_t(0, ==, string.len);
	v_assert_str("", string.str);

	teardown();
	VTS;
}

static void	test_05_string_cdup_CharInString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	string_cdup(&string, s, 'W');

	v_assert_size_t(7, ==, string.len);
	v_assert_str("Hello W", string.str);

	teardown();
	VTS;
}

static void	test_06_string_cdup_CharNotInString(void)
{
	char	*s = "Hello World!";
	/* size_t	len = strlen(s); */

	v_assert_ptr(NULL, ==, string_cdup(&string, s, 'z'));

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
