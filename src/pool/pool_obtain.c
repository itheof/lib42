/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_obtain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 11:15:26 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 11:59:36 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool_42.h"

/*
** Retourne la tete de la freelist
** et update la freelist vers le nouveau node libre
** Si la freelist est vide, alloue un nouveau chunk dans le pool
*/

void	*pool_obtain(t_pool *p)
{
	t_chunk	*chunk;
	void	*node;

	if (p->free_list == NULL)
	{
		chunk = pool_new_chunk(p);
		if (chunk == NULL)
			return (NULL);
		p->free_list = CHUNK_HEAD(chunk);
		chunk->next = p->chunks_list;
		p->chunks_list = chunk;
	}
	node = p->free_list;
	p->free_list = *(void**)p->free_list;
	return (node);
}
