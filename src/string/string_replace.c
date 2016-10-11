/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:04:20 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Replace the content of the buffer with the string '*s'
*/

t_string	*string_replace(t_string *s, const char *str)
{
	return (string_nreplace(s, str, ft_strlen(str)));
}

/*
** Replace the content of the buffer with the string '*s', up to 'len' bytes
*/

t_string	*string_nreplace(t_string *s, const char *str, size_t len)
{
	s->len = 0;
	if (string_ncat(s, str, len) == NULL)
		return (NULL);
	s->str[s->len] = '\0';
	return (s);
}
