#include "header.h"

static t_string	*string;

static void	setup(char *s, size_t len, size_t max)
{
	string = malloc(sizeof(t_string));
	string->str = malloc(max);
	memset(string->str, 0, max);
	memcpy(string->str, s, len);
	string->len = len;
	string->sizemax = max;
}

static void	teardown(void)
{
	free(string->str);
	memset(string, 0, sizeof(t_string));
	free(string);
}

static void	test_00_string_replace_BiggerString(void)
{
	char	*s = "Hello";
	size_t	len = strlen(s);
	size_t	max = 8;
	setup(s, len, max);

	char	*replace = "World!";
	size_t	lrep = strlen(replace);
	string_replace(string, replace);

	v_assert_size_t(max, ==, TBUFFER_MAX(string));
	v_assert_size_t(lrep, ==, TBUFFER_LEN(string));
	v_assert_str(replace, TBUFFER_GET(string));

	teardown();
	VTS;
}

static void	test_01_string_nreplace_BigStringNotNullTerminated(void)
{
	char	*s = "Hello";
	size_t	len = strlen(s);
	size_t	max = 8;
	setup(s, len, max);

	char	*replace = "World";
	size_t	lrep = strlen(replace);
	char	arr[501];
	for (size_t i = 0; i < 100; ++i)
		memcpy(arr + (i * lrep), replace, lrep);
	arr[500] = 'x';

	string_nreplace(string, arr, 500);

	v_assert_size_t(512, ==, TBUFFER_MAX(string));
	v_assert_size_t(500, ==, TBUFFER_LEN(string));
	arr[500] = '\0';
	v_assert_str(arr, TBUFFER_GET(string));

	teardown();
	VTS;
}

static void	test_02_string_replace_LowerString(void)
{
	char	*s = "Hello World!";
	size_t	len = strlen(s);
	size_t	max = 16;
	setup(s, len, max);

	char	*replace = "abc";
	size_t	lrep = strlen(replace);
	string_replace(string, replace);

	v_assert_size_t(16, ==, TBUFFER_MAX(string));
	v_assert_size_t(lrep, ==, TBUFFER_LEN(string));
	v_assert_str(replace, TBUFFER_GET(string));

	teardown();
	VTS;
}

void	suite_string_replace(void)
{
	test_00_string_replace_BiggerString();
	test_01_string_nreplace_BigStringNotNullTerminated();
	test_02_string_replace_LowerString();

	VSS;
}
