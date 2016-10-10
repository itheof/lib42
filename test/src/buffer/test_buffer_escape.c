#include "header.h"

static void	test_00_buffer_escape_classic(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("Hello World!");
	buffer_escape(&buffer, 'l');

	v_assert_str("He\\l\\lo Wor\\ld!", buffer.str);

	VTS;
}

static void	test_01_buffer_unescape_classic(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("He\\l\\lo Wor\\ld!");
	buffer_unescape(&buffer, 'l');

	v_assert_str("Hello World!", buffer.str);

	VTS;
}

static void	test_02_buffer_escape_no_match(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("Hello World!");
	buffer_escape(&buffer, 'm');

	v_assert_str("Hello World!", buffer.str);

	VTS;
}

static void	test_03_buffer_unescape_no_match(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("He\\l\\lo Wor\\ld!");
	buffer_unescape(&buffer, 'm');

	v_assert_str("He\\l\\lo Wor\\ld!", buffer.str);

	VTS;
}

static void	test_04_buffer_escape_in_the_void(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("He");
	buffer_escape(&buffer, 'H');

	v_assert_str("\\He", buffer.str);

	VTS;
}

static void	test_05_buffer_unescape_in_the_void(void)
{
	t_buffer	buffer;

	buffer = *buffer_dup("l\\");
	buffer_unescape(&buffer, 'l');

	v_assert_str("l\\", buffer.str);

	VTS;
}

void	suite_buffer_escape(void)
{
	test_00_buffer_escape_classic();
	test_01_buffer_unescape_classic();

	test_02_buffer_escape_no_match();
	test_03_buffer_unescape_no_match();

	test_04_buffer_escape_in_the_void();
	test_05_buffer_unescape_in_the_void();

	VSS;
}
