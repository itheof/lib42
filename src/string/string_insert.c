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

t_string	*string_insert(t_string *b, size_t pos, const char *s, size_t len)
{
	if (pos > b->len)
		return (NULL);
	if (BUF_NEED_RESIZE(b, len))
		if (string_resize(b, len) == NULL)
			return (NULL);
	ft_memmove(b->str + pos + len, b->str + pos, b->len - pos);
	ft_memcpy(b->str + pos, s, len);
	b->len += len;
	b->str[b->len] = 0;
	return (b);
}
