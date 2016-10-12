/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:25:04 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array		*array_init(t_array *v, size_t size, size_t elem_size)
{
	v->capacity = (size < TARRAY_MIN_SIZE) ? TARRAY_MIN_SIZE : size;
	v->len = 0;
	v->elem_size = elem_size;
	v->data = malloc(elem_size * v->capacity);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
