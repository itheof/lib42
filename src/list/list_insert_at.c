#include "list_42.h"

t_list	*list_insert_at(t_list *l, size_t i, const void *e)
{
	struct s_node	*new;
	struct s_node	*tmp;
	struct s_node	**ppnext;

	if (i > l->len)
		return (NULL);
	if (i == l->len)
		return (list_push_back(l, e));

	if ((new = pool_obtain_node(&l->pool)) == NULL)
		return (NULL);

	tmp = l->start;
	ppnext = &l->start;
	while (i > 0)
	{
		ppnext = &tmp->next;
		tmp = tmp->next;
		--i;
	}
	new->next = tmp;
	*ppnext = new;
	l->len += 1;;
	return (l);

}
