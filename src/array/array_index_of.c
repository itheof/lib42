/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_index_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:54:59 by djean             #+#    #+#             */
/*   Updated: 2016/10/16 15:41:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

ssize_t		array_index_of(t_array *a, const void *e)
{
	size_t		index;

	if (e >= a->data && (size_t)e < (size_t)a->data + a->len * a->elem_size)
	{
		index = (size_t)e - (size_t)a->data;
		index /= a->elem_size;
		return ((ssize_t)index);
	}
	return (-1);
}
