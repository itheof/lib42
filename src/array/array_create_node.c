/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:09:45 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 16:45:08 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Return the first free node or create one if the array is full
*/

void	*array_create_node(t_array *v)
{
	void	*p;

	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	p = TARRAY_GET(v, v->count);
	v->count += 1;
	return (p);
}
