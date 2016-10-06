/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/06 15:33:59 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"

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

// TODO need return poped elem
void					cbuffer_pop_back(t_cbuffer *b)
{
	if (b->len > 0)
	{
		b->end = move_backward(b->max_len, b->end);
		b->len -= 1;
	}
}

// TODO need return poped elem
void					cbuffer_pop_front(t_cbuffer *b)
{
	if (b->len > 0)
	{
		b->start = move_forward(b->max_len, b->start);
		b->len -= 1;
	}
}
