#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "string_42.h"
# include "stdlib_42.h"
# include "ctype_42.h"
# include "str_42.h"

# define PRF_BUFSIZ 128
# define PRF_INDEX(i) (FT_ISLOWER(i) ? ((i) & 0x1F) - 1 : (i) - 39)
# define SPECIFIERS "csCSdouxXp%"

# ifndef MB_LEN_MAX
#  define MB_LEN_MAX 4
# endif

int		ft_asprintf(char **ret, const char *format, ...);
int		ft_vasprintf(char **ret, const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_snprintf(char *str, size_t size, const char *format, ...);
int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_vsprintf(char *str, const char *format, va_list ap);
void	ft_printf_init(size_t initsize);
ssize_t	ft_printf_core(const char *format, va_list ap, char **ret);
void	exit_printf(int code);
int		cleanup_buf(t_string *pb);
int		parse_conv(char c, t_format *fmt);
char	*parse_flags(char *format, t_format *fmt);
char	*parse_min_width(char *format, t_format *fmt);
char	*parse_precision(char *format, t_format *fmt);
char	*parse_len_mod(char *format, t_format *fmt);
int		conv_c(t_string *b, t_format *fmt, va_list ap);
int		conv_s(t_string *b, t_format *fmt, va_list ap);
int		conv_wc(t_string *b, t_format *fmt, va_list ap);
int		conv_wcs(t_string *b, t_format *fmt, va_list ap);
int		conv_d(t_string *b, t_format *fmt, va_list ap);
int		conv_o(t_string *b, t_format *fmt, va_list ap);
int		conv_u(t_string *b, t_format *fmt, va_list ap);
int		conv_x(t_string *b, t_format *fmt, va_list ap);
int		conv_p(t_string *b, t_format *fmt, va_list ap);
int		conv_prc(t_string *b, t_format *fmt, va_list ap);
int		str_formatting(t_string *pb, t_format *fmt, size_t arglen);
int		int_format_intro(t_format *fmt, char *arg, size_t *arglen);
int		int_sign(t_string *pb, t_format *fmt, char *arg);
int		int_padding(t_string *pb, t_format *fmt, size_t arglen, int fchar);
int		int_precision(t_string *pb, t_format *fmt, size_t arglen);
int		ft_wctomb(char *s, wchar_t wchar);
size_t	ft_wcstombs(char *s, wchar_t *pwcs, size_t n);
size_t	ft_wcslen(const wchar_t *s);
int		conv_to_utf8(int wbytes, wchar_t wchar, char *s);

#endif
