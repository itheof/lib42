/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:15:37 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Remove at position 'pos' a 'size' number of bytes
** Return the numbers of bytes effectively removed
*/

// TODO add 'string_pop_char' function
size_t		string_remove(t_string *s, size_t pos, size_t size)
{
	size_t	removed;

	if (pos >= s->len)
		return (0);
	if (pos + size >= s->len)
	{
		removed = s->len - pos;
		s->len = pos;
	}
	else
	{
		removed = size;
		ft_memmove(s->str + pos, s->str + pos + size, s->len - (pos + size));
		s->len -= size;
	}
	s->str[s->len] = '\0';
	if (s->iterator > pos)
		string_iterator_set(s, pos);
	return (removed);
}
