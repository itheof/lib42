/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:20:17 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Concatene the string '*s' to the buffer '*b'
*/

t_string	*string_cat(t_string *b, const char *s)
{
	return (string_ncat(b, s, ft_strlen(s)));
}

/*
** Concatene the string '*s', of size 'len', to the buffer '*b'
*/

t_string	*string_ncat(t_string *b, const char *s, size_t len)
{
	if (BUF_NEED_RESIZE(b, len))
		if (string_resize(b, len) == NULL)
			return (NULL);
	ft_memcpy(b->str + b->len, s, len);
	b->len += len;
	return (b);
}
