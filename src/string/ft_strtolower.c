#include "string_42.h"

char	*ft_strtolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = FT_TOLOWER(str[i]);
		++i;
	}
	return (str);
}
