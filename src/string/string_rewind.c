/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rewind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:23:18 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Rewind the string by 'n' chars
** Return the new size of the buffer or -1 if the rewind is to large
*/

int		string_rewind(t_string *s, size_t n)
{
	size_t	nlen;

	if (n > s->len)
		return (-1);
	nlen = s->len - n;
	s->str[nlen] = '\0';
	s->len = nlen;
	// TODO delete this horific thing !!! now !!!
	if (s->iterator > s->len)
		string_iterator_set(s, s->len);
	return ((int)nlen);
}

/*
** Rewind the string up to 'c' char
** The char 'c' is exclude from the buffer
** Return the number of chars that have been rewind, or -1 if it is not found
*/

int		string_rewindchr(t_string *s, int c)
{
	int		pos;
	size_t	ret;

	pos = ft_strrchrpos(s->str, c);
	if (pos == -1)
		return (-1);
	s->str[pos] = '\0';
	ret = s->len - (size_t)pos;
	s->len = (size_t)pos;
	if (s->iterator > s->len)
		string_iterator_set(s, s->len);
	return ((int)ret);
}
