#include "header.h"

static t_string b;

static void	setup(void)
{
	string_init(&b, 127);
	string_ncat(&b, "Hello World!", 12);
}

static void	teardown(void)
{
	TBUFFER_FREE(&b);
}

static void	test_00_string_rewindchr_SimpleRewind(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&b, 'l'); */
	string_rewindchr(&b, 'l');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(9, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello Wor", TBUFFER_GET(&b));

	teardown();
	VTS;
}

static void	test_01_string_rewindchr_EndOfString(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&b, '\0'); */
	string_rewindchr(&b, '\0');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(12, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World!", TBUFFER_GET(&b));

	teardown();
	VTS;
}

static void	test_02_string_rewindchr_LastChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&b, '!'); */
	string_rewindchr(&b, '!');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(11, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello World", TBUFFER_GET(&b));

	teardown();
	VTS;
}

static void	test_03_string_rewindchr_FirstChar(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&b, 'H'); */
	string_rewindchr(&b, 'H');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(0, ==, TBUFFER_LEN(&b));
	v_assert_str("", TBUFFER_GET(&b));

	teardown();
	VTS;
}

static void	test_04_string_rewindchr_MultipleOccurrence(void)
{
	/* size_t res; */
	setup();

	/* res = string_rewindchr(&b, 'o'); */
	string_rewindchr(&b, 'o');
	v_assert_size_t(128, ==, TBUFFER_MAX(&b));
	v_assert_size_t(7, ==, TBUFFER_LEN(&b));
	v_assert_str("Hello W", TBUFFER_GET(&b));

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
