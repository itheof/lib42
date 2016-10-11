#include "ft_printf.h"

/*
** Write output to the given file descriptor
*/

int	ft_dprintf(int fd, const char *format, ...)
{
	char	*buf;
	ssize_t	ret;
	va_list	ap;

	va_start(ap, format);
	buf = NULL;
	if ((ret = ft_printf_core(format, ap, &buf)) < 0)
		return (-1);
	va_end(ap);
	write(fd, buf, (size_t)ret);
	free(buf);
	return ((int)ret);
}
