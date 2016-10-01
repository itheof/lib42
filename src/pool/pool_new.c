/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:56:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 12:00:02 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool_42.h"

t_pool	*pool_new(size_t elem_size, size_t chunk_capacity)
{
	t_pool	*p;

	p = malloc(sizeof(t_pool));
	if (p != NULL)
	{
		if (pool_init(p, elem_size, chunk_capacity) == NULL)
		{
			free(p);
			p = NULL;
		}
	}
	return (p);
}

t_pool	*pool_init(t_pool *p, size_t elem_size, size_t chunk_capacity)
{
	if (elem_size == 0 || chunk_capacity == 0)
		return (NULL);
	p->chunk_capacity = chunk_capacity;
	p->elem_size = ROUND_UP_8(elem_size);
	p->free_list = NULL;
	p->chunks_list = NULL;
	return (p);
}
