#include "stdlib_42.h"
#include "ctype_42.h"

#define ERROR	0x1
#define SUCCESS	0x0

static inline int	get_char_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (-1);
}

int					ft_atou_base(size_t *n, const char *str, unsigned base)
{
	int			char_val;
	size_t		ret;

	ret = 0;
	while (FT_ISXDIGIT(*str))
	{
		char_val = get_char_value(*str);
		if (char_val == -1 || (unsigned)char_val >= base)
			return (ERROR);
		else
			ret = ret * base + (unsigned)char_val;
		str += 1;
	}
	*n = ret;
	return (SUCCESS);
}

int					ft_atoi_base(ssize_t *n, const char *str, unsigned base)
{
	int			char_val;
	ssize_t		ret;
	int			sign;

	ret = 0;
	if (*str == '-')
	{
		sign = -1;
		str += 1;
	}
	else
		sign = 1;
	while (FT_ISXDIGIT(*str))
	{
		char_val = get_char_value(*str);
		if (char_val == -1 || (unsigned)char_val >= base)
			return (ERROR);
		else
			ret = ret * base + char_val * sign;
		str += 1;
	}
	*n = ret;
	return (SUCCESS);
}

int					ft_atou(size_t *n, const char *str)
{
	if (!ft_strncmp(str, "0x", 2))
		return (ft_atou_base(n, str + 2, 16));
	else if (!ft_strncmp(str, "0b", 2))
		return (ft_atou_base(n, str + 2, 2));
	else if (!ft_strncmp(str, "0", 1))
		return (ft_atou_base(n, str + 1, 8));
	else
		return (ft_atou_base(n, str, 10));
}
