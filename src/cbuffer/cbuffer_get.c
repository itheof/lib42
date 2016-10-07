/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:51:28 by crenault          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:18 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cbuffer_42.h"

void		*cbuffer_get(t_cbuffer const *buffer, size_t i)
{
	if (i >= buffer->len || buffer->len == 0)
		return (NULL);
	if (buffer->start + i >= buffer->max_len)
		return (CBUFFER_GET(buffer, buffer->start + i - buffer->max_len));
	return (CBUFFER_GET(buffer, buffer->start + i));
}

void		*cbuffer_get_front(t_cbuffer const *buffer)
{
	if (buffer->len == 0)
		return (NULL);
	return (CBUFFER_GET(buffer, buffer->start));
}

void		*cbuffer_get_back(t_cbuffer const *buffer)
{
	if (buffer->len == 0)
		return (NULL);
	return (CBUFFER_GET(buffer, buffer->end));
}
