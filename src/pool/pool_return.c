/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 12:02:50 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 11:06:38 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool_42.h"

/*
** Ajoute le '*node' comme nouvelle tete de la freelist
** Aucune vérification n'est effectué pour savoir si le pointer '*node'
** appartient bien au pool
*/

void	pool_return(t_pool *p, void *node)
{
	*(void**)node = p->free_list;
	p->free_list = node;
}
