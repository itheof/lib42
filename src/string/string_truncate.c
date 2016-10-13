/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_truncate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:04:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Truncate the string by 'n' chars
** Return the new size of the buffer or -1 if the truncate is to large
*/

int		string_truncate(t_string *s, size_t n)
{
	if (n > s->len)
		return (-1);
	s->len -= n;
	s->str[s->len] = '\0';
	return ((int)s->len);
}

/*
** truncate the string up to 'c' char
** The char 'c' is exclude from the buffer
** Return the number of chars that have been truncate, or -1 if it is not found
*/

int		string_truncate_chr(t_string *s, int c)
{
	int		pos;
	size_t	ret;

	pos = ft_strrchrpos(s->str, c);
	if (pos == -1)
		return (-1);
	s->str[pos] = '\0';
	ret = s->len - (size_t)pos;
	s->len = (size_t)pos;
	return ((int)ret);
}
