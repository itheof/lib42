#include "list_42.h"

void	*list_get_available(t_list *l)
{
	struct s_node	*new_node;

	new_node = pool_obtain_node(&l->pool);
	if (new_node == NULL)
		return (NULL);
	l->end = l->end->next;
	l->end->next = new_node;
	l->len += 1;
	return (NODE_GET_DATA(l->end));
}

void	*list_get_at(const t_list *l, size_t i)
{
	struct s_node	*ret;

	if (i >= l->len)
		return (NULL);
	ret = l->start;
	while (i > 0)
	{
		ret = ret->next;
		i -= 1;
	}
	return (NODE_GET_DATA(ret));
}

void	*list_get_first(const t_list *l)
{
	return (NODE_GET_DATA(l->start));
}

void	*list_get_last(const t_list *l)
{
	return (NODE_GET_DATA(l->end));
}
