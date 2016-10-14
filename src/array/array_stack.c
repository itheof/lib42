/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:26 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:42:46 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_pop(t_array *v, void *old)
{
	v->len -= 1;
	return (array_remove(v, v->len, old));
}

t_array	*array_push(t_array *v, const void *e)
{
	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	ft_memcpy(TARRAY_GET(v, v->len), e, v->elem_size);
	v->len += 1;
	return (v);
}
