/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:26 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 17:56:24 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_pop(t_array *v, void *old)
{
	v->count -= 1;
	return (array_remove(v, v->count, old));
}

t_array	*array_push(t_array *v, void *e)
{
	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	ft_memcpy(TARRAY_GET(v, v->count), e, v->elem_size);
	v->count += 1;
	return (v);
}
