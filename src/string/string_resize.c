/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:08:37 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Enlarge the buffer by adding 'expand'
*/

// TODO rename 'reserve' + 'additional' parameter name
// https://doc.rust-lang.org/std/vec/struct.Vec.html#method.reserve
// TODO review this function
t_string	*string_resize(t_string *s, size_t expand)
{
	void	*new;
	size_t	newsize;

	newsize = s->sizemax * STRING_GROWTH_FACTOR;
	while (s->len + expand >= newsize)
		newsize *= STRING_GROWTH_FACTOR;
	new = ft_realloc(s->str, newsize, s->sizemax);
	if (new == NULL)
		return (NULL);
	s->sizemax = newsize;
	s->str = new;
	return (s);
}
