#include "list_42.h"

ssize_t	list_index_of(const t_list *l, const void *e)
{
	size_t	i;

	i = 0;
	while (i < l->len)
	{
		if (list_get_at(l, i) == e)
			return ((ssize_t)i);
		i += 1;
	}
	return (-1);
}
