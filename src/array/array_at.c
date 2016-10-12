/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:35:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_get_at(t_array *v, size_t i)
{
	if (i < v->len)
		return (TARRAY_GET(v, i));
	return (NULL);
}

void	array_set_at(t_array *v, size_t i, const void *e)
{
	if (i < v->len)
		ft_memcpy(TARRAY_GET(v, i), e, v->elem_size);
}
