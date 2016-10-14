/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/14 23:40:23 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Concatene the string '*s' to the buffer '*b'
*/

t_string	*string_cat(t_string *s, const char *str)
{
	return (string_ncat(s, str, ft_strlen(str)));
}

/*
** Concatene the string '*s', of size 'len', to the buffer '*b'
*/

t_string	*string_ncat(t_string *s, const char *str, size_t len)
{
	if (string_reserve(s, len + 1) == NULL)
		return (NULL);
	ft_memcpy(s->str + s->len, str, len);
	s->len += len;
	s->str[s->len] = '\0';
	return (s);
}
