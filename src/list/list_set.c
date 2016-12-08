#include "list_42.h"
#include "memory_42.h"

void	*list_set_at(const t_list *l, size_t i, const void *e)
{
	void	*node;

	node = list_get_at(l, i);
	if (node == NULL)
		return (NULL);
	ft_memcpy(node, e, l->elem_size);
	return (node);
}
