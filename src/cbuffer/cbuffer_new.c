/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:01:15 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 16:12:21 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "typedefs_42.h"
#include "array_42.h"

t_cbuffer	*cbuffer_new(size_t size, size_t elem_size)
{
	t_cbuffer	*buffer;

	buffer = ft_memalloc(sizeof(t_cbuffer));
	if (buffer == NULL)
		return (NULL);
	if ((cbuffer_init(buffer, size, elem_size)) == NULL)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void		*cbuffer_init(t_cbuffer *buffer, size_t size, size_t elem_size)
{
	if ((array_init(&buffer->array, size, elem_size)) == NULL)
		return (NULL);
	buffer->start = 0;
	buffer->end = 0;
	return (buffer);
}
