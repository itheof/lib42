/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:51:28 by crenault          #+#    #+#             */
/*   Updated: 2016/10/10 19:46:12 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs_42.h"
#include "typedefs_42.h"
#include "cbuffer_42.h"

void		*cbuffer_at(t_cbuffer const *buffer, size_t i)
{
	if (i >= buffer->len || buffer->len == 0)
		return (NULL);
	if (buffer->start + i >= buffer->capacity)
		return (CBUFFER_AT_INDEX(buffer, buffer->start + i - buffer->capacity));
	return (CBUFFER_AT_INDEX(buffer, buffer->start + i));
}

void		*cbuffer_front(t_cbuffer const *buffer)
{
	if (buffer->len == 0)
		return (NULL);
	return (CBUFFER_AT_INDEX(buffer, buffer->start));
}

void		*cbuffer_back(t_cbuffer const *buffer)
{
	if (buffer->len == 0)
		return (NULL);
	return (CBUFFER_AT_INDEX(buffer, buffer->end));
}
