/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:14:18 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:32:28 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Init un nouvel array et copie la structure *v dans le nouvel espace.
*/

t_array		*array_copy(t_array *dst, const t_array *src)
{
	if (array_init(dst, src->capacity, src->elem_size) == NULL)
		return (NULL);
	dst->len = src->len;
	ft_memcpy(dst->data, src->data, src->len * src->elem_size);
	return (dst);
}
