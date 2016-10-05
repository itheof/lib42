/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:53:30 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 18:15:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cbuffer_42.h"

void	cbuffer_index_push_back(size_t max_len, size_t *len,
								size_t *start, size_t *end)
{
	if (*len == max_len && *end == *len - 1)
	{
		*start = 1;
		*end = 0;
	}
	else if (*len == max_len && *start == *len - 1)
	{
		*start = 0;
		*end = 1;
	}
	else if (*len == max_len)
	{
		*start += 1;
		*end += 1;
	}
	else if (*end == *len - 1)
	{
		*end = 0;
		++(*len);
	}
	else
	{
		*end += 1;
		++(*len);
	}
}

void	cbuffer_index_push_front(size_t max_len, size_t *len,
								size_t *start, size_t *end)
{
	if (*len == max_len && *start == 0)
	{
		*start = max_len - 1;
		*end = max_len - 2;
	}
	else if (*len == max_len && *end == 0)
	{
		*start = 0;
		*end = max_len - 1;
	}
	else if (*len == max_len)
	{
		*end -= 1;
		*start -= 1;
	}
	else if (*start == 0)
	{
		*start = *len - 1;
		++(*len);
	}
	else
	{
		*start -= 1;
		++(*len);
	}
}
