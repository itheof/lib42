/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:16:16 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:45:01 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array		*array_insert(t_array *v, size_t i, const void *e)
{
	char	*src;
	size_t	len;

	if (i > v->len)
		return (NULL);
	if (TARRAY_NEED_RESIZE(v) && array_resize(v) == NULL)
		return (NULL);
	if (i == v->len)
		return (array_push(v, e));
	src = TARRAY_GET(v, i);
	len = (v->len - i) * v->elem_size;
	ft_memmove(src + v->elem_size, src, len);
	array_set_at(v, i, e);
	v->len += 1;
	return (v);
}
