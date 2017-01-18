#include "ft_printf.h"

/*
** Write to the character string str.
** The function assume size of INT_MAX + 1
*/

int	ft_sprintf(char *str, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	char	*buf;
	ssize_t	ret;

	buf = NULL;
	if ((ret = ft_printf_core(format, ap, &buf)) < 0)
		return (-1);
	ft_memcpy(str, buf, (size_t)ret);
	str[ret] = '\0';
	return ((int)ret);
}
