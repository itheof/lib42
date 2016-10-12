#include "ft_printf.h"

/*
** Write to the character string
** Will write at most size-1 of the characters printed into the output string
** If the return value is greater than or equal to the size argument,
** the string was too short and some of the printed characters were discarded.
** The output is always null-terminated, unless size is 0.
*/

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	char	*buf;
	ssize_t	ret;
	va_list	ap;

	va_start(ap, format);
	buf = NULL;
	if ((ret = ft_printf_core(format, ap, &buf)) < 0)
		return (-1);
	if (size == 0)
		ft_memcpy(str, buf, size - 1);
	else if ((size_t)ret <= size - 1)
	{
		ft_memcpy(str, buf, (size_t)ret);
		str[ret] = '\0';
	}
	else
	{
		ft_memcpy(str, buf, size - 1);
		str[size] = '\0';
	}
	va_end(ap);
	return ((int)ret);
}