#include "string_42.h"

inline static int	return_value(int res)
{
	if (res > 0)
		return (1);
	else if (res < 0)
		return (-1);
	else
		return (0);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	min;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	min = FT_MIN(s1len + 1, s2len + 1);
	return (return_value(ft_memcmp(s1, s2, min)));
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;
	size_t	min;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	min = FT_MIN(s1len + 1, s2len + 1);
	min = FT_MIN(min, n);
	return (return_value(ft_memcmp(s1, s2, min)));
}
