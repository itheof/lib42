#include "ft_printf.h"

/*
** Write output to stdout
*/

int	ft_printf(const char *format, ...)
{
	char	*str;
	ssize_t	ret;
	va_list	ap;

	va_start(ap, format);
	if ((ret = ft_printf_core(format, ap, &str)) < 0)
		return (-1);
	va_end(ap);
	write(1, str, (size_t)ret);
	free(str);
	return ((int)ret);
}
