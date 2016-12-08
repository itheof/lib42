#include "list_42.h"
#include "memory_42.h"

t_list	*list_push_back(t_list *l, const void *e)
{
	/* ft_memcpy(NODE_GET_DATA(l->end->next), e, l->elem_size); */
	/* l->end = l->end->next; */
	/* l->end->next = pool_obtain_node(&l->pool); */
	/* return (l); */

	ft_memcpy(NODE_GET_DATA(l->free_node), e, l->elem_size);
	l->end->next = l->free_node;
	l->end = l->end->next;
	l->free_node = pool_obtain_node(&l->pool);
	return (l);
}

t_list	*list_push_front(t_list *l, const void *e)
{
	ft_memcpy(NODE_GET_DATA(l->free_node), e, l->elem_size);
	l->free_node->next = l->start;
	l->start = l->free_node;
	l->free_node = pool_obtain_node(&l->pool);
	return (l);
}

t_list	*list_pop(t_list *l, void *old)
{

}
