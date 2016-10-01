/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:54:59 by djean             #+#    #+#             */
/*   Updated: 2016/10/01 16:03:38 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Search if the pointer e belongs to the array range
** Return the index or -1 on error
*/

int		array_indexof(t_array *v, void *e)
{
	uintptr_t	index;

	if (TARRAY_IN_RANGE(v, e))
	{
		index = (uintptr_t)e - (uintptr_t)v->data;
		index /= v->elem_size;
		return ((int)index);
	}
	return (-1);
}
