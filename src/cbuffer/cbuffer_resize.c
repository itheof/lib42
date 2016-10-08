/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/08 18:20:41 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"
#include "memory_42.h"

inline static void	copy_data(t_cbuffer const *b, char *new_data)
{
	size_t		rest;

	if (b->start > b->end)
	{
		rest = b->capacity - b->start;
		ft_memcpy(new_data, (char*)b->data + (b->start * b->elem_size),
					rest * b->elem_size);
		ft_memcpy(new_data + (rest * b->elem_size), b->data,
					(b->len - rest) * b->elem_size);
	}
	else
	{
		ft_memcpy(new_data, (char*)b->data + (b->start * b->elem_size),
					b->len * b->elem_size);
	}
}

t_cbuffer			*cbuffer_resize(t_cbuffer *b, size_t len)
{
	char	*new_data;

	if (len < b->len)
		return (NULL);
	if (len == b->capacity)
		return (b);
	if ((new_data = malloc(len * b->elem_size)) == NULL)
		return (NULL);
	copy_data(b, new_data);
	free(b->data);
	b->data = new_data;
	b->start = 0;
	b->end = b->len == 0 ? 0 : b->len - 1;
	b->capacity = len;
	return (b);
}
