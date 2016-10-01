/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:14:18 by djean             #+#    #+#             */
/*   Updated: 2016/10/01 15:59:34 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Alloue un nouveau array et copie la structure *v
** Dans le nouvel espace.
*/

t_array	*array_copy(t_array *v)
{
	t_array	*cp;

	if ((cp = array_new(v->max, v->elem_size)) == NULL)
		return (NULL);
	cp->count = v->count;
	ft_memcpy(cp->data, v->data, v->count * v->elem_size);
	return (cp);
}
