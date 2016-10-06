/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:01:15 by crenault          #+#    #+#             */
/*   Updated: 2016/10/06 16:03:44 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "typedefs_42.h"
#include "cbuffer_42.h"

t_cbuffer	*cbuffer_new(size_t len, size_t elem_size,
							void (*delete_func)(void *))
{
	t_cbuffer	*buffer;

	buffer = malloc(sizeof(t_cbuffer));
	if (buffer == NULL)
		return (NULL);
	if ((cbuffer_init(buffer, len, elem_size, delete_func)) == NULL)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void		*cbuffer_init(t_cbuffer *buffer, size_t len, size_t elem_size,
							void (*delete_func)(void *))
{
	if ((buffer->data = malloc(len * elem_size)) == NULL)
		return (NULL);
	buffer->len = 0;
	buffer->max_len = len;
	buffer->elem_size = elem_size;
	buffer->delete_func = delete_func;
	buffer->start = 0;
	buffer->end = 0;
	return (buffer);
}
