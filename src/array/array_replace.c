/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:02:40 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 00:31:47 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
** old est un emplacement mémoire qui va contenir l'élément remplacé
** Si old == NULL, alors l'élément est simplement écrasé
*/

void	*array_replace_at(t_array *v, size_t i, const void *e, void *old)
{
	void	*p;

	if (i >= v->len)
		return (NULL);
	if (old != NULL)
	{
		p = array_get_at(v, i);
		ft_memcpy(old, p, v->elem_size);
	}
	array_set_at(v, i, e);
	return (old);
}
