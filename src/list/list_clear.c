#include "list_42.h"

void	list_clear(t_list *l)
{
	l->start = NULL;
	l->end = NULL;
	l->len = 0;
}
