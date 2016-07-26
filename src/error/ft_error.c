#include "error_42.h"

int				g_errno;
static char		*g_project_name;
static char		**g_errlist;
static size_t	g_nerr;

void	register_errlist(char *name, char **list, size_t max)
{
	g_errno = 0;
	g_project_name = (name == NULL) ? "error" : name;
	g_errlist = list;
	g_nerr = max;
}

char	*ft_strerror(int errnum)
{
	if (errnum < 0 || (size_t)errnum >= g_nerr)
		return (UNKNOWN_ERROR);
	return (g_errlist[errnum]);
}

void	ft_perror(const char *msg)
{
	ft_perrorn(msg, g_errno);
}

void	ft_perrorn(const char *msg, int errnum)
{
	t_buffer	buf;
	char		*errmsg;

	ft_buffer_init(&buf, 64);
	ft_buffer_add(&buf, g_project_name, ft_strlen(g_project_name));
	ft_buffer_add(&buf, ": ", 2);
	if (msg != NULL && msg[0] != '\0')
	{
		ft_buffer_add(&buf, msg, ft_strlen(msg));
		ft_buffer_add(&buf, ": ", 2);
	}
	errmsg = ft_strerror(errnum);
	ft_buffer_add(&buf, errmsg, ft_strlen(errmsg));
	write(STDERR_FILENO, FT_BUFFER_GET(&buf), FT_BUFFER_LEN(&buf));
	FT_BUFFER_FREE(&buf);
}

void	ft_die(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}
