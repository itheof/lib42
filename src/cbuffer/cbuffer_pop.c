/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/08 18:29:05 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_42.h"
#include "typedefs_42.h"
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

void					*cbuffer_pop_back(t_cbuffer *b)
{
	void	*popped;

	if (b->len > 0)
	{
		popped = CBUFFER_GET(b, b->end);
		b->end = move_backward(b->capacity, b->end);
		b->len -= 1;
		return (popped);
	}
	return (NULL);
}

void					*cbuffer_pop_front(t_cbuffer *b)
{
	void	*popped;

	if (b->len > 0)
	{
		popped = CBUFFER_GET(b, b->start);
		b->start = move_forward(b->capacity, b->start);
		b->len -= 1;
		return (popped);
	}
	return (NULL);
}
