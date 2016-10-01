/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:32:11 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 11:59:50 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool_42.h"

/*
** Libère tout les chunks du pool
*/

void	pool_reset(t_pool *p)
{
	void	*ptr;

	while (p->chunks_list)
	{
		ptr = p->chunks_list;
		p->chunks_list = p->chunks_list->next;
		free(ptr);
	}
	p->chunks_list = NULL;
	p->free_list = NULL;
}
