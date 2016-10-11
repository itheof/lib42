#include "ft_printf.h"

/*
** Dynamically allocate a new string with malloc.
** Set *ret to be a pointer to a buffer sufficiently large to hold
** the formatted strings.
** If sufficient space cannot be allocated, return -1 & set ret to NULL
*/

int	ft_asprintf(char **ret, const char *format, ...)
{
	ssize_t	res;
	va_list	ap;

	va_start(ap, format);
	*ret = NULL;
	if ((res = ft_printf_core(format, ap, ret)) < 0)
		*ret = NULL;
	va_end(ap);
	return ((int)res);
}
