#include "ft_printf.h"

/*
** Write to the character string str.
** The function assume size of INT_MAX + 1
*/

int	ft_sprintf(char *str, const char *format, ...)
{
	char	*buf;
	ssize_t	ret;
	va_list	ap;

	va_start(ap, format);
	buf = NULL;
	if ((ret = ft_printf_core(format, ap, &buf)) < 0)
		return (-1);
	ft_memcpy(str, buf, (size_t)ret);
	str[ret] = '\0';
	va_end(ap);
	return ((int)ret);
}
