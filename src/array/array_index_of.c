/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_index_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:54:59 by djean             #+#    #+#             */
/*   Updated: 2016/10/17 15:14:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

ssize_t		array_index_of(t_array *a, const void *e)
{
	uintptr_t	index;

	if (e >= a->data
		&& (uintptr_t)e < (uintptr_t)a->data + a->len * a->elem_size)
	{
		index = (uintptr_t)e - (uintptr_t)a->data;
		index /= a->elem_size;
		return ((ssize_t)index);
	}
	return (-1);
}
