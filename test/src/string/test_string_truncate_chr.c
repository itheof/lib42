#include "header.h"

static t_string		string;

static void	setup(void)
{
	string_init(&string, 127);
	string_ncat(&string, "Hello World!", 12);
}

static void	teardown(void)
{
	free(string.str);
}

static void	test_00_string_truncate_chr_SimpleRewind(void)
{
	/* size_t res; */
	setup();

	/* res = string_truncate_chr(&string, 'l'); */
	string_truncate_chr(&string, 'l');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(9, ==, string.len);
	v_assert_str("Hello Wor", string.str);

	teardown();
	VTS;
}

static void	test_01_string_truncate_chr_EndOfString(void)
{
	/* size_t res; */
	setup();

	/* res = string_truncate_chr(&string, '\0'); */
	string_truncate_chr(&string, '\0');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(12, ==, string.len);
	v_assert_str("Hello World!", string.str);

	teardown();
	VTS;
}

static void	test_02_string_truncate_chr_LastChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_truncate_chr(&string, '!'); */
	string_truncate_chr(&string, '!');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(11, ==, string.len);
	v_assert_str("Hello World", string.str);

	teardown();
	VTS;
}

static void	test_03_string_truncate_chr_FirstChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_truncate_chr(&string, 'H'); */
	string_truncate_chr(&string, 'H');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(0, ==, string.len);
	v_assert_str("", string.str);

	teardown();
	VTS;
}

static void	test_04_string_truncate_chr_MultipleOccurrence(void)
{
	/* size_t res; */
	setup();

	/* res = string_truncate_chr(&string, 'o'); */
	string_truncate_chr(&string, 'o');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(7, ==, string.len);
	v_assert_str("Hello W", string.str);

	teardown();
	VTS;
}

void	suite_string_truncate_chr(void)
{
	test_00_string_truncate_chr_SimpleRewind();
	test_01_string_truncate_chr_EndOfString();
	test_02_string_truncate_chr_LastChar();
	test_03_string_truncate_chr_FirstChar();
	test_04_string_truncate_chr_MultipleOccurrence();

	VSS;
}
