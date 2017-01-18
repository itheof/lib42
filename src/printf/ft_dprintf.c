#include "ft_printf.h"

/*
** Write output to the given file descriptor
*/

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*buf;
	ssize_t	ret;

	buf = NULL;
	if ((ret = ft_printf_core(format, ap, &buf)) < 0)
		return (-1);
	write(fd, buf, (size_t)ret);
	free(buf);
	return ((int)ret);
}
