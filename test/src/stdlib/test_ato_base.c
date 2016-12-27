#include "header.h"

static void test_ubase(const char *str, size_t expected_nb, unsigned base)
{
	size_t		nb;

	v_assert_int(ft_atou_base(&nb, str, base), ==, 0);
	v_assert_size_t(nb, ==, expected_nb);
	VTS;
}

static void test_ibase(const char *str, ssize_t expected_nb, unsigned base)
{
	ssize_t		nb;

	v_assert_int(ft_atoi_base(&nb, str, base), ==, 0);
	v_assert_long(nb, ==, expected_nb);
	VTS;
}

static void test_u(const char *str, size_t expected_nb)
{
	size_t		nb;

	v_assert_int(ft_atou(&nb, str), ==, 0);
	v_assert_size_t(nb, ==, expected_nb);
	VTS;
}

void	suite_ato_base()
{
	test_ubase("0", 0, 0x2);
	test_ubase("1", 1, 0x2);
	test_ubase("10", 2, 0x2);
	test_ubase("1111111111111111111111111111111111111111111111111111111111111111", UINT64_MAX, 0x2);
	test_ibase("111111111111111111111111111111111111111111111111111111111111111", INT64_MAX, 0x2);
	test_ibase("-1000000000000000000000000000000000000000000000000000000000000000", INT64_MIN, 0x2);
	test_ubase("7", 7, 0x8);
	test_ubase("10", 8, 0x8);
	test_ibase("-10", -8, 0x8);
	test_ubase("1777777777777777777777", UINT64_MAX, 0x8);
	test_ibase("777777777777777777777", INT64_MAX, 0x8);
	test_ibase("1000000000000000000000", INT64_MIN, 0x8);
	test_ubase("666", 666, 0xA);
	test_ibase("-9223372036854775808", INT64_MIN, 0xA);
	test_ibase("9223372036854775807", INT64_MAX, 0xA);
	test_ubase("18446744073709551615", UINT64_MAX, 0xA);
	test_ubase("100", 256, 0x10);
	test_ubase("A", 10, 0x10);
	test_ibase("-8000000000000000", INT64_MIN, 0x10);
	test_ibase("7FFFFFFFFFFFFFFF", INT64_MAX, 0x10);
	test_ubase("FFFFFFFFFFFFFFFF", UINT64_MAX, 0x10);
	v_assert(ft_atou_base(NULL, "lol", 0x10));
	v_assert(ft_atou_base(NULL, "-lol", 0xA));
	test_u("0b10", 2);
	test_u("666", 666);
	test_u("0100", 64);
	test_u("0x100", 256);
	VSS;
}
