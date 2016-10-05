/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:12:42 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 18:15:21 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbuffer_42.h"
#include "array_42.h"

void	cbuffer_push_back(t_cbuffer *b, void const *e)
{
	cbuffer_index_push_back(b->max_len, &b->len, &b->start, &b->end);
	ft_memcpy(CBUFFER_GET(b, b->end), e, b->elem_size);
}

void	cbuffer_push_front(t_cbuffer *b, void const *e)
{
	cbuffer_index_push_front(b->max_len, &b->len, &b->start, &b->end);
	ft_memcpy(CBUFFER_GET(b, b->end), e, b->elem_size);
}
