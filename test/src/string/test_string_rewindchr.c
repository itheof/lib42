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

static void	test_00_string_rewindchr_SimpleRewind(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&string, 'l'); */
	string_rewindchr(&string, 'l');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(9, ==, string.len);
	v_assert_str("Hello Wor", string.str);

	teardown();
	VTS;
}

static void	test_01_string_rewindchr_EndOfString(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&string, '\0'); */
	string_rewindchr(&string, '\0');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(12, ==, string.len);
	v_assert_str("Hello World!", string.str);

	teardown();
	VTS;
}

static void	test_02_string_rewindchr_LastChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&string, '!'); */
	string_rewindchr(&string, '!');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(11, ==, string.len);
	v_assert_str("Hello World", string.str);

	teardown();
	VTS;
}

static void	test_03_string_rewindchr_FirstChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&string, 'H'); */
	string_rewindchr(&string, 'H');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(0, ==, string.len);
	v_assert_str("", string.str);

	teardown();
	VTS;
}

static void	test_04_string_rewindchr_MultipleOccurrence(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&string, 'o'); */
	string_rewindchr(&string, 'o');
	v_assert_size_t(128, ==, string.capacity);
	v_assert_size_t(7, ==, string.len);
	v_assert_str("Hello W", string.str);

	teardown();
	VTS;
}

void	suite_string_rewindchr(void)
{
	test_00_string_rewindchr_SimpleRewind();
	test_01_string_rewindchr_EndOfString();
	test_02_string_rewindchr_LastChar();
	test_03_string_rewindchr_FirstChar();
	test_04_string_rewindchr_MultipleOccurrence();

	VSS;
}
