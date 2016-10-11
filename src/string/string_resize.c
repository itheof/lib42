/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:22:39 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Enlarge the buffer by adding 'expand'
*/

t_string	*string_resize(t_string *b, size_t expand)
{
	void	*new;
	size_t	newsize;

	newsize = b->sizemax * STRING_GROWTH_FACTOR;
	while (b->len + expand >= newsize)
		newsize *= STRING_GROWTH_FACTOR;
	new = ft_realloc(b->str, newsize, b->sizemax);
	if (new == NULL)
		return (NULL);
	b->sizemax = newsize;
	b->str = new;
	return (b);
}
