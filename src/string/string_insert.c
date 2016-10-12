/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 01:59:41 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Insert at the position 'pos', the string '*s' of size 'len'
*/

t_string	*string_insert(t_string *s, size_t pos, const char *str, size_t l)
{
	if (pos > s->len)
		return (NULL);
	if (STRING_NEED_RESIZE(s, l) && string_resize(s, l) == NULL)
		return (NULL);
	ft_memmove(s->str + pos + l, s->str + pos, s->len - pos);
	ft_memcpy(s->str + pos, str, l);
	s->len += l;
	s->str[s->len] = 0;
	return (s);
}
