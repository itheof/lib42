/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 17:27:37 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array	*array_new(size_t size, size_t elem_size)
{
	t_array	*v;

	v = malloc(sizeof(t_array));
	if (v == NULL)
		return (NULL);
	if ((array_init(v, size, elem_size)) == NULL)
	{
		free(v);
		return (NULL);
	}
	return (v);
}

void	*array_init(t_array *v, size_t size, size_t elem_size)
{
	v->max = (size < TARRAY_MIN_SIZE) ? TARRAY_MIN_SIZE : size;
	v->count = 0;
	v->elem_size = elem_size;
	v->iterator = 0;
	v->data = malloc(elem_size * v->max);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
