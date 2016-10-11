#include "ft_printf.h"

int	conv_prc(t_buffer *pb, t_format *fmt, va_list ap)
{
	(void)ap;
	fmt->prec = -1;
	if (fmt->min_width > 1 && fmt->f_minus == 0)
		str_formatting(pb, fmt, 1);
	buffer_ncat(pb, &(char){'%'}, 1);
	if (fmt->min_width > 1 && fmt->f_minus == 1)
		str_formatting(pb, fmt, 1);
	return (1);
}
