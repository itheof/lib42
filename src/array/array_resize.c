/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:33:29 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_resize(t_array *v)
{
	void	*new;
	size_t	new_size;

	new_size = v->elem_size * v->capacity * TARRAY_GROWTH_FACTOR;
    // TODO don't need to be zeroed !!!
	new = ft_realloc(v->data, new_size, v->len * v->elem_size);
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->capacity *= TARRAY_GROWTH_FACTOR;
	return (v);
}
