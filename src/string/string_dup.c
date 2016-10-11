/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:33:13 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:20:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Duplicate the string '*str' and return a buffer of it
*/

t_string	*string_dup(t_string *s, const char *str)
{
	return (string_ndup(s, str, ft_strlen(str)));
}

/*
** Duplicate the string '*str', up to the size 'len', and return a buffer of it
*/

t_string	*string_ndup(t_string *s, const char *str, size_t len)
{
	const char	*cpy_stop;

	if ((string_init(s, len)) == NULL)
		return (NULL);
	cpy_stop = ft_memccpy(s->str, str, '\0', len);
	s->len = cpy_stop == NULL ? len : (size_t)(cpy_stop - 1 - s->str);
	s->str[s->len] = '\0';
	return (s);
}
