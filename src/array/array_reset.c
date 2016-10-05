/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 19:29:46 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 17:45:46 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_reset(t_array *v)
{
	v->count = 0;
	v->iterator = 0;
	v->max = TARRAY_MIN_SIZE;
	free(v->data);
	v->data = malloc(v->elem_size * v->max);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
