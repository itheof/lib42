/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuffer_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:53:30 by crenault          #+#    #+#             */
/*   Updated: 2016/10/05 17:13:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		cbuffer_index_push_back(size_t count, size_t max,
									size_t *start, size_t *end)
{
	if (count == max && *end == count - 1)
	{
		*start = 1;
		*end = 0;
	}
	else if (count == max && *start == count - 1)
	{
		*start = 0;
		*end = 1;
	}
	else if (count == max)
	{
		*start += 1;
		*end += 1;
	}
	else if (*end == count - 1)
	{
		*end = 0;
	}
	else
	{
		*end += 1;
	}
}

void		cbuffer_index_push_front(size_t count, size_t max,
									size_t *start, size_t *end)
{
	if (count == max && *start == 0)
	{
		*start = max - 1;
		*end = max - 2;
	}
	else if (count == max && *end == 0)
	{
		*start = 0;
		*end = max - 1;
	}
	else if (count == max)
	{
		*end -= 1;
		*start -= 1;
	}
	else if (*start == 0)
	{
		*start = count - 1;
	}
	else
	{
		*start -= 1;
	}
}
