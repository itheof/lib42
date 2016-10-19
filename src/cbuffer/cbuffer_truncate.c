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

t_cbuffer	*cbuffer_truncate_from_back(t_cbuffer *buffer, size_t n)
{
	size_t	to_pop;
	void	*popped;

	if (n > buffer->len)
		return (NULL);
	to_pop = buffer->len - n;
	while (to_pop != 0)
	{
		popped = cbuffer_pop_back(buffer);
		if (buffer->delete_func != NULL)
			buffer->delete_func(popped);
		--to_pop;
	}
	return (buffer);
}

t_cbuffer	*cbuffer_truncate_from_front(t_cbuffer *buffer, size_t n)
{
	size_t	to_pop;
	void	*popped;

	if (n > buffer->len)
		return (NULL);
	to_pop = buffer->len - n;
	while (to_pop != 0)
	{
		popped = cbuffer_pop_front(buffer);
		if (buffer->delete_func != NULL)
			buffer->delete_func(popped);
		--to_pop;
	}
	return (buffer);
}
