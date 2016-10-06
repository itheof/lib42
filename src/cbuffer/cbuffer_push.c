/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/06 00:09:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"
#include "memory_42.h"

inline static size_t	move_forward(size_t len, size_t n)
{
	if (n >= len - 1)
		return (0);
	return (n + 1);
}

inline static size_t	move_backward(size_t len, size_t n)
{
	if (n == 0)
		return (len - 1);
	return (n - 1);
}

void					cbuffer_push_back(t_cbuffer *b, void const *elem)
{
	if (b->len == 0)
	{
		b->len += 1;
	}
	else if (b->len == b->max_len)
	{
		b->end = move_forward(b->len, b->end);
		b->start = move_forward(b->len, b->start);
	}
	else
	{
		b->len += 1;
		b->end = move_forward(b->len, b->end);
	}
	ft_memcpy(CBUFFER_GET(b, b->end), elem, b->elem_size);
}

void					cbuffer_push_front(t_cbuffer *b, void const *elem)
{
	if (b->len == 0)
	{
		b->len += 1;
	}
	else if (b->len == b->max_len)
	{
		b->start = move_backward(b->max_len, b->start);
		b->end = move_backward(b->max_len, b->end);
	}
	else
	{
		b->len += 1;
		b->start = move_backward(b->max_len, b->start);
	}
	ft_memcpy(CBUFFER_GET(b, b->start), elem, b->elem_size);
}
