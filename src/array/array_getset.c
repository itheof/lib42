/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_getset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/10/16 15:34:24 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_get_at(t_array *a, size_t i)
{
	if (i < a->len)
		return ((char *)a->data + i * a->elem_size);
	return (NULL);
}

void	*array_set_at(t_array *a, size_t i, const void *e)
{
	if (i < a->len)
		return (ft_memcpy(array_get_at(a, i), e, a->elem_size));
	return (NULL);
}
