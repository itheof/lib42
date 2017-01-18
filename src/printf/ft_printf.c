#include "ft_printf.h"

/*
** Write output to stdout
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

int		ft_vprintf(const char *format, va_list ap)
{
	char	*str;
	ssize_t	ret;

	if ((ret = ft_printf_core(format, ap, &str)) < 0)
		return (-1);
	write(1, str, (size_t)ret);
	free(str);
	return ((int)ret);
}
