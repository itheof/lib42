#include "list_42.h"
#include "pool_42.h"

t_list	*list_init(t_list *l, size_t elem_size)
{
	if (elem_size == 0)
		return (NULL);
	if (pool_init(&l->pool, elem_size) == NULL)
		return (NULL);
	l->start = NULL;
	l->end = NULL;
	l->len = 0;
	l->elem_size = elem_size;
	return (l);
}

void	list_shutdown(t_list *l)
{
	pool_shutdown(&l->pool);
}
