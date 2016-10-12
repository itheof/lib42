/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:09:45 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:37:22 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Return the first free node or create one if the array is full
*/

void	*array_create_node(t_array *v)
{
	void	*p;

	if (TARRAY_NEED_RESIZE(v) && array_resize(v) == NULL)
		return (NULL);
	p = TARRAY_GET(v, v->len);
	v->len += 1;
	return (p);
}
