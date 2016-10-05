/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 16:50:55 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"
#include "array_42.h"

void	*cbuffer_push_back(t_cbuffer *buffer, void const *e)
{
	// TODO put this in a function
	if (buffer->end == buffer->array.max - 1)
		buffer->end = 0;
	else
		buffer->end += 1;

	array_replace(buffer->array, buffer->end, e, NULL);
	return (buffer);
}

void	*cbuffer_push_front(t_cbuffer *buffer, void const *e)
{
	//
}
