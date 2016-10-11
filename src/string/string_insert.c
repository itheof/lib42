/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:21:01 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Insert at the position 'pos', the string '*s' of size 'len'
*/

t_string	*string_insert(t_string *s, size_t pos, const char *str, size_t len)
{
	if (pos > s->len)
		return (NULL);
	if (string_reserve(s, len + 1) == NULL)
		return (NULL);
	ft_memmove(s->str + pos + len, s->str + pos, s->len - pos);
	ft_memcpy(s->str + pos, str, len);
	s->len += len;
	s->str[s->len] = 0;
	return (s);
}
