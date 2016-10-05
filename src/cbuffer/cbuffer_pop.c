/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 23:01:25 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"

inline static size_t	move_forward(size_t len, size_t n)
{
	if (n == len - 1)
		return (0);
	return (n + 1);
}

inline static size_t	move_backward(size_t len, size_t n)
{
	if (n == 0)
		return (len - 1);
	return (n - 1);
}

void					cbuffer_pop_back(t_cbuffer *b)
{
	b->len -= 1;
	b->end = move_backward(b->len, b->end);
}

void					cbuffer_pop_front(t_cbuffer *b)
{
	b->len -= 1;
	b->start = move_forward(b->len, b->start);
}
