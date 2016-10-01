/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:55:26 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 14:10:30 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool_42.h"

inline static void	chunk_intern_link(void *ptr, size_t size, size_t count)
{
	void	**next;
	size_t	i;

	next = ptr;
	i = 1;
	while (i < count)
	{
		*next = (unsigned char*)ptr + size;
		ptr = *next;
		next += size / 8;
		++i;
	}
	*next = NULL;
}

/*
** - Alloue un nouveau chunk
** - Link chaque node interne en freelist
*/

t_chunk				*pool_new_chunk(t_pool *p)
{
	t_chunk	*chunk;

	chunk = malloc(CHUNK_SIZE(p->elem_size, p->chunk_capacity));
	if (chunk == NULL)
		return (NULL);
	chunk->next = NULL;
	chunk_intern_link(&chunk->head, p->elem_size, p->chunk_capacity);
	return (chunk);
}
