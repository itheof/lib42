/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 16:25:41 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // delete

#include "string_42.h"

t_string	*string_replace(t_string *s, const char *str)
{
	return (string_nreplace(s, str, ft_strlen(str)));
}

t_string	*string_nreplace(t_string *s, const char *str, size_t len)
{
	s->len = 0;
	if (string_ncat(s, str, len) == NULL)
		return (NULL);
	s->str[s->len] = '\0';
	return (s);
}

t_string	*string_set(t_string *s, size_t from, size_t n, int c)
{
	if (from > s->len)
		return (NULL);
	if (string_reserve(s, n - from + 1) == NULL)
		return (NULL);
	ft_memset(s->str + from, c, n);
	if (from + n > s->len)
		s->len = from + n;
	s->str[s->len] = '\0';
	return (s);
}
